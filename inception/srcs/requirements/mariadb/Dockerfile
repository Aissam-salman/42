FROM debian:stable-backports

RUN apt update -y
RUN apt install mariadb-server -y

COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/usr/local/bin/entrypoint.sh"]
