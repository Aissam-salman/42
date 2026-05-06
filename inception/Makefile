buid:
	mkdir -p /home/salman/data
	mkdir -p /home/salman/data/wordpress
	mkdir -p /home/salman/data/mariadb
	docker compose -f ./srcs/docker-compose.yml up -d --build

start:
	docker compose -f ./srcs/docker-compose.yml up

stop:
	docker compose -f ./srcs/docker-compose.yml stop	

clean:
	docker compose -f ./srcs/docker-compose.yml down -v
	rm -rf /home/salman/data/*
	rm -rf /home/salman/data



