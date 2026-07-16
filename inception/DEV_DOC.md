# Setup environment from scratch 

## prerequisites
- VM with debian stable 13.4
- docker, make, vim installed 

## config files
- change /etc/hosts add : 127.0.0.1  login.42.fr

## secrets 
- path variables environments: srcs/.env.example
- cp srcs/.env.example srcs/.env
- Complete as you want

# Build and launch the project

## Docker compose
```
	mkdir -p /home/login/data
	mkdir -p /home/login/data/wordpress
	mkdir -p /home/login/data/mariadb
	docker compose -f ./srcs/docker-compose.yml up -d --build
```

## Makefile

- buid: build and launch the project
- start: launch the project
- stop: just stop all container of project
- clean: stop all container and remove volumes, and local data

# Common command docker

`docker build path  -t name_build`  to build just one container
`docker build -t nginx .`

`docker image ls` to see your builded image

`docker run image_name`

`docker ps` to see all container and their status

`docker exec -it <container_name> sh` to enter to your container
and have shell


# File tree of project
.
├── DEV_DOC.md
├── Makefile
├── note.md
├── README.md
├── secrets
├── srcs
│   ├── docker-compose.yml
│   └── requirements
│       ├── bonus
│       │   ├── adminer
│       │   │   ├── conf
│       │   │   ├── Dockerfile
│       │   │   └── tools
│       │   ├── ftp
│       │   │   ├── conf
│       │   │   ├── Dockerfile
│       │   │   └── tools
│       │   └── redis
│       │       ├── conf
│       │       ├── Dockerfile
│       │       └── tools
│       ├── mariadb
│       │   ├── conf
│       │   │   ├── 50-server.cnf
│       │   │   └── entrypoint.sh
│       │   ├── Dockerfile
│       │   └── tools
│       ├── nginx
│       │   ├── conf
│       │   ├── Dockerfile
│       │   └── tools
│       │       └── main.sh
│       ├── tools
│       └── wordpress
│           ├── conf
│           │   └── entrypoint.sh
│           ├── Dockerfile
│           └── tools
└── USER_DOC.md
