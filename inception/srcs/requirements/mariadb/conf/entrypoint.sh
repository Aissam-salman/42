#!/bin/sh

# stop script if one cmd fail
set -e

DATADIR="/var/lib/mysql"

DB_NAME=${MARIADB_DATABASE:-app_db}
DB_USER=${MARIADB_USER:-app_user}
DB_PASS=${MARIADB_PASSWORD:-app_pass}
ROOT_PASS=${MARIADB_ROOT_PASSWORD:-root_pass}

# if DB already exist
if [ ! -d "$DATADIR"/mysql ]; then
	echo "Init MariaDB..."

	# create base table system
	mariadb-install-db --user=mysql --datadir="$DATADIR"

	echo "Start temporary MariaDB..."
	mariadbd --skip-networking &
	pid="$!"

	until mariadb-admin ping --silent; do
		sleep 1
	done

	echo "Create DB..."

# % other ip allows
mariadb << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOT_PASS';
CREATE DATABASE IF NOT EXISTS \`$DB_NAME\`;
CREATE USER IF NOT EXISTS \`$DB_USER\`@localhost IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON \`$DB_NAME\`.* TO \`$DB_USER\`@'%';
FLUSH PRIVILEGES;
EOF

	echo "Stop MariaDB..."
	mariadb-admin -u root -p$ROOT_PASS shutdown

	wait "$pid"
fi

echo "Starting MariaDB..."
exec mariadbd-safe
