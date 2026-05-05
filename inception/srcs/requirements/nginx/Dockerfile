FROM debian:stable-backports

## install package needed 
RUN apt update -y
RUN apt install nginx curl openssl -y

## backup the conf
RUN  mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig

## copy conf to container
COPY conf/nginx.conf /etc/nginx/nginx.conf


## add ssl support for TSL
RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/server.crt -keyout /etc/nginx/ssl/server.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=alamjada.42.fr/UID=alamjada"
RUN chmod 600 /etc/nginx/ssl/server.key
RUN chmod 644 /etc/nginx/ssl/server.crt 

## run nginx 
CMD ["nginx", "-g", "daemon off;"]

