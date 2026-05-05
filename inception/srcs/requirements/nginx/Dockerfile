FROM debian:stable-backports

## install package needed 
RUN apt update -y
RUN apt install nginx curl openssl -y


COPY tools/main.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/main.sh

## run nginx 
ENTRYPOINT ["sh", "/usr/local/bin/main.sh"]

