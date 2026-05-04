FROM debian:stable-backports

RUN apt update -y
RUN apt install mariadb-server -y

# RUN mariadb-install-db --user=mysql
COPY conf/entrypoint.sh /usr/local/bin/entrypoint.sh
COPY  conf/50-server.cnf /etc/my.cnf.d/50-server.cnf
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["sh", "usr/local/bin/entrypoint.sh"]
