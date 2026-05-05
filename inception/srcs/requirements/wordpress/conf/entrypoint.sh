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

cat << EOF > /etc/php/8.4/fpm/pool.d/www.conf
[www]

user = www-data
group = www-data
listen = 0.0.0.0:9000
clear_env = no

pm = dynamic
pm.max_children = 30
pm.start_servers = 1
pm.min_spare_servers = 1
pm.max_spare_servers = 30
EOF

chown -R www-data:www-data /var/www/wordpress

cd /var/www/wordpress

if [ ! -f /var/www/.mountFirst ]; then
	mariadb-admin ping --protocol=tcp --host=mariadb -u"$DB_USER" -p"$DB_PASS" --wait > /dev/null
	echo "Downloading WordPress..."
	pwd
	cat $(ls)

	if [ ! -f /var/www/wordpress/wp-config.php ]; then

		wp core download --allow-root || true

		echo "Create config..."
		wp config create --allow-root \
			--dbname="$DB_NAME" \
			--dbuser="$DB_USER" \
			--dbpass="$DB_PASS" \
			--dbhost="mariadb" \
			--path='/var/www/wordpress'

		wp core install --allow-root \
			--skip-email \
			--url="$WP_URL" --title="Inception" \
			--admin_user="$WP_ADMIN" \
			--admin_password="$WP_ADMIN_PASS" \
			--admin_email="$WP_ADMIN_EMAIL"

		wp config set --allow-root WP_HOME "https://$WP_URL"
		wp config set --allow-root WP_SITEURL "https://$WP_URL"

		if ! wp user get --allow-root "$WP_USER" >/dev/null 2>&1; then
			echo "Create user..."
			wp user create --allow-root  \
				"$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_USER_PASS"
		fi

	fi
	chmod o+w -R /var/www/wordpress
	touch /var/www/.mountFirst
fi



echo "Run wordpress..."
/usr/sbin/php-fpm8.4 -F


