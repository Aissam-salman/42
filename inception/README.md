*This project has been created as part of the 42 curriculum by alamjada*

# Description

Introduction to Docker and containers. The goal is to reproduce a real-world stack used by thousands of people around the world:

* nginx
* mariadb
* wordpress

You need to learn how Docker works and deploy it inside your VM, similar to Born2beroot.

You must create your own Docker images and not use pre-built ones from Docker Hub.

---

## Virtual Machines vs Docker

Docker and Virtual Machines (VMs) are two technologies used for application deployment.

### Docker Containers

* Portable environment
* Allows you to model each container and store it as a local image
* Packages only the application and its required dependencies
* Contains the code and everything needed to run it

### Virtual Machines

* A digital copy of a physical machine

Virtual machines were originally designed to allow multiple operating systems to run on a single physical machine. The goal is to provide users with an isolated virtual environment independent of the underlying hardware. VMs abstract hardware details, making it easier to run applications on different architectures and to use hardware resources efficiently.

Docker, on the other hand, was designed to provide a lightweight and portable way to package and run applications in an isolated and reproducible environment. Docker abstracts operating system details to solve the challenge of deploying applications across different environments such as development, testing, and production. Managing software updates and maintaining consistent environments can be difficult, especially for organizations using hundreds of applications or microservices. Docker addresses this problem through containerization.

---

## Secrets vs Environment Variables

### Environment Variables

* Simple and quick to configure
* Visible in plain text via `docker inspect`, `docker exec env`, logs
* Accessible to all processes in the container

### Secrets

* Mounted as files in `/run/secrets/` (not as variables)
* Not visible via `docker inspect` or `docker exec env`
* More secure for passwords, tokens, and keys
* Slightly more complex to configure

---

## Docker Network vs Host Network

### Docker Network (Bridge)

* Each container has its own isolated IP
* Containers communicate using their names (nginx, wordpress, mariadb)
* Full isolation from the host network
* You control exactly which ports are exposed
* Slightly more configuration required

```
services:
  nginx:
    networks:
      - inception

networks:
  inception:
    driver: bridge
```

### Host Network

* The container uses the host machine's network directly
* Maximum performance (no NAT)
* No isolation — the container has full access to the host network
* Possible port conflicts
* Less secure

```
services:
  nginx:
    network_mode: host
```

---

## Docker Volumes vs Bind Mount

### Docker Volumes

* Managed entirely by Docker
* Data stored in `/var/lib/docker/volumes/`
* Portable and independent of the host system
* Harder to access files directly from the host

### Bind Mounts

* You choose exactly where data is stored on the host
* Direct access to files from the host machine
* Useful for development (live file editing)
* Depends on exact host paths
* Less portable

---

# Instructions

```
cd inception
cp srcs/.env.example srcs/.env
```

Complete the `.env` file with your own information.

```
make        # build and start the project
make stop   # stop the project
make clean  # stop all containers and remove all volumes
```

---

# Resources

* [https://docs.docker.com/](https://docs.docker.com/)
* [https://blog.stephane-robert.info/docs/conteneurs/moteurs-conteneurs/docker/](https://blog.stephane-robert.info/docs/conteneurs/moteurs-conteneurs/docker/)
* [https://blog.stephane-robert.info/docs/conteneurs/moteurs-conteneurs/docker/secrets/](https://blog.stephane-robert.info/docs/conteneurs/moteurs-conteneurs/docker/secrets/)
* [https://tuto.grademe.fr/inception/](https://tuto.grademe.fr/inception/)
* [https://github.com/Vikingu-del/Inception-Guide](https://github.com/Vikingu-del/Inception-Guide)

