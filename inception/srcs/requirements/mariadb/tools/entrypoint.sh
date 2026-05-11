#!/bin/bash

# stop script if one cmd fail
set -e

DATADIR="/var/lib/mysql"

DB_NAME=${MARIADB_DATABASE:-app_db}
DB_USER=${MARIADB_USER:-app_user}
DB_PASS=${MARIADB_PASSWORD:-app_pass}
ROOT_PASS=${MARIADB_ROOT_PASSWORD:-root_pass}

# if DB already exist
if [ ! -f "$DATADIR"/.mountInit ]; then
	echo "Init MariaDB..."

	# create base table system
	mariadb-install-db --user=mysql --datadir="$DATADIR"\
		--auth-root-authentication-method=socket > /dev/null 2>/dev/null

	echo "Start temporary MariaDB..."
	mariadbd-safe &
	pid="$!"

	mariadb-admin ping --silent --wait > /dev/null 2>/dev/null
cat << EOF | mariadb --protocol=socket -u root -p=
CREATE DATABASE IF NOT EXISTS \`$DB_NAME\`;
CREATE USER IF NOT EXISTS \`$DB_USER\`@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON \`$DB_NAME\`.* TO \`$DB_USER\`@'%';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$ROOT_PASS';
FLUSH PRIVILEGES;
EOF

	echo "Stop MariaDB..."
	mariadb-admin -u root -p"$ROOT_PASS" shutdown
	touch /var/lib/mysql/.firstInit

	wait "$pid"
fi

echo "Starting MariaDB..."
exec mariadbd-safe
