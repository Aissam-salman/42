FROM alpine:3.22

## install package needed 
RUN apk update 
RUN apk upgrade 
RUN apk add nginx curl vim openssl

## create user www for nginx
RUN adduser -D -g 'www' www

## for html file
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www

## backup the conf
RUN  mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig

## copy conf to container
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/index.html /www/index.html


## add ssl support for TSL
RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/server.crt -keyout /etc/nginx/ssl/server.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=alamjada.42.fr/UID=alamjada"
RUN chmod 600 /etc/nginx/ssl/server.key
RUN chmod 644 /etc/nginx/ssl/server.crt 

## run nginx 
CMD ["nginx", "-g", "daemon off;"]

