FROM debian:stable-backports

RUN apt update -y
RUN apt install nginx curl openssl -y


COPY tools/main.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/main.sh

EXPOSE 443

ENTRYPOINT ["sh", "/usr/local/bin/main.sh"]

