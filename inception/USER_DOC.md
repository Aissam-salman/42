# Stack

- Nginx : http web server 
- Mariadb: database for the website data
- Wordpress: CMS(web content management system) to build web site & manage
content without code
- Docker: container applications

each service have his own container, the mariadb and wordpress have her own
volumes to stock data.

# How this work ? 
- login to user account

```

cd inception 
cp srcs/.env.example srcs/.env

# complete .env with your own info

make # to build and start the project

make stop # to stop the project

make clean # to stop all container and rm all volumes

```


# Access the website

- open your navigator 
- enter : https://login.42.fr
you will get the homepage of your website, if you want go to admin panel: 
enter : https://login.42.fr/wp-admin


# Locate and manage credentials
```
cp inception/srcs/.env.example inception/srcs/.env

# complete .env with your own info

```

# Check that the services are running correctly

`docker ps`
To see the logs of container
`docker log <container>`

