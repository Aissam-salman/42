#!/bin/sh

DOMAIN=${DOMAIN_NAME:-localhost}


if [ ! -f /etc/nginx/.first ]; then

	## add ssl support for TSL
	mkdir -p /etc/nginx/ssl
	openssl req -x509 -nodes -out /etc/nginx/ssl/server.crt -keyout /etc/nginx/ssl/server.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=$DOMAIN/UID=alamjada"

	chmod 600 /etc/nginx/ssl/server.key
	chmod 644 /etc/nginx/ssl/server.crt 

	cat << EOF > /etc/nginx/sites-available/wordpress
upstream php {
    server wordpress:9000;
}

server {
	listen 80;
	listen [::]:80;
	server_name  $DOMAIN;
	return 301 https://$DOMAIN\$request_uri;
}

server {
	listen       *:443 ssl;
	listen      [::]:443 ssl;
	http2 on;
	server_name  $DOMAIN;

	root  /var/www/wordpress;
	index index.php;

	ssl_protocols TLSv1.2 TLSv1.3;
	ssl_certificate      /etc/nginx/ssl/server.crt;
	ssl_certificate_key  /etc/nginx/ssl/server.key;
	ssl_ciphers  HIGH:!aNULL:!MD5;
	ssl_prefer_server_ciphers  on;

	location / {
		try_files \$uri \$uri/ /index.php?\$args;
	}

	location ~ \.php$ {
			fastcgi_pass wordpress:9000;
			include fastcgi.conf;
			fastcgi_intercept_errors on;
	}

}
EOF

  ln -sf /etc/nginx/sites-available/wordpress /etc/nginx/sites-enabled/wordpress
	touch /etc/nginx/.first 

fi

exec nginx -g 'daemon off;'
