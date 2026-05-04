#!/bin/sh

set -e


DB_NAME=${MYSQL_DATABASE:-app_db}
DB_USER=${MYSQL_USER:-app_user}
DB_PASS=${MYSQL_PASSWORD:-app_pass}
ROOT_PASS=${MYSQL_ROOT_PASSWORD:-root_pass}


service mariadb start;

mariadb << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '$ROOT_PASS';
CREATE DATABASE IF NOT EXISTS \`$DB_NAME\`;
CREATE USER IF NOT EXISTS \`$DB_USER\`@localhost IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON \`$DB_NAME\`.* TO \`$DB_USER\`@'%';
FLUSH PRIVILEGES;
EOF

mysqladmin -u root -p$ROOT_PASS shutdown

exec mariadbd-safe
