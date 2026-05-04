#!/bin/sh

set -e

WP_ADMIN=${WORDPRESS_ADMIN:-wpcli}
WP_ADMIN_PASS=${WORDPRESS_ADMIN_PASS:-wpCliPassWord}
WP_ADMIN_EMAIL=${WORDPRESS_ADMIN_EMAIL:-info@wp-cli.org}
WP_URL=${WORDPRESS_URL:-alamjada.42.fr}

DB_NAME=${MARIADB_DATABASE:-app_db}
DB_USER=${MARIADB_USER:-app_user}
DB_PASS=${MARIADB_PASSWORD:-app_pass}

WP_USER=${WORDPRESS_USER:-alamjada}
WP_USER_PASS=${WORDPRESS_USER_PASS:-passwordComplicat}
WP_USER_EMAIL=${WORDPRESS_USER_EMAIL:-salman.59560@gmail.com}

until mysql -h mariadb -u"$DB_USER" -p"$DB_PASS" -e "SELECT 1" "$DB_NAME" >/dev/null 2>&1; do
	echo "wait db..."
	sleep 2
done

if [ ! -f /var/www/wordpress/wp-config.php ]; then
	echo "Downloading WordPress..."
	wp core download --path=/var/www/wordpress --allow-root
	chown -R www-data:www-data /var/www/wordpress

	echo "Create config..."
	wp config create --allow-root \
		--dbname="$DB_NAME" \
		--dbuser="$DB_USER" \
		--dbpass="$DB_PASS" \
		--dbhost="mariadb:3306" \
		--path='/var/www/wordpress'
fi

if ! wp core is-installed --allow-root --path=/var/www/wordpress >/dev/null 2>&1; then
	echo "Core install..."
	wp core install --allow-root --skip-email --path=/var/www/wordpress --url="$WP_URL" --title="Inception" \
		--admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASS" --admin_email="$WP_ADMIN_EMAIL"
fi

if ! wp user get --allow-root --path=/var/www/wordpress "$WP_USER" >/dev/null 2>&1; then
	echo "Create user..."
	wp user create --allow-root --path=/var/www/wordpress "$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_USER_PASS"
fi


echo "Run wordpress..."
/usr/sbin/php-fpm8.4 -F


