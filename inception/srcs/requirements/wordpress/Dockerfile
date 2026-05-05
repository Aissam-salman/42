FROM debian:stable-backports

RUN apt update -y

RUN apt install php8.4 php8.4-fpm php8.4-mysql php8.4-curl -y

RUN apt install mariadb-client wget curl vim -y


RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN mkdir -p /var/www/wordpress
RUN sed -i 's/memory_limit = .*/memory_limit = 512M/' /etc/php/*/cli/php.ini


COPY conf/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh


ENTRYPOINT ["sh", "/usr/local/bin/entrypoint.sh"]
