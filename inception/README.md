*This project has been created as part of the 42 curriculum by alamjada*


# Description

Introduction to docker, container, try to product a real stack used by
thousant people in the word. 
- nginx
- mariadb
- wordpress

You need to learn how docker work and put them in your VM like Born2beroot.

But you need to create your hown image docker and not use already done in docker hub.

## Virtual Machines vs Docker

Docker et les machines virtuelles (VM) sont deux technologies utilisées dans le déploiement d'applications.


Docker container
- environnement portable
- permet de modeliser chq contenreur et de les stocker sous la forme d’une image en local
- Le conteneur permet d'empaqueter une application mais juste avec l’app et ses dependance necessaire
- le code et de quoi le faire run

VM
- une copie numérique d'une machine physique.

Les machines virtuelles ont été conçues à l'origine pour permettre à plusieurs systèmes d'exploitation de fonctionner sur une seule machine physique. L'objectif est de permettre aux utilisateurs de créer un environnement virtuel isolé du matériel sous-jacent. Les VM masque les détails du matériel afin de faciliter l'exécution d'applications sur différentes architectures matérielles et d'utiliser les ressources matérielles plus efficacement.

Docker, quant à lui, a été conçu pour fournir un moyen léger et portable de packager et d'exécuter des applications dans un environnement isolé et reproductible. Docker masque les détails du système d'exploitation pour relever le défi du déploiement d'applications dans différents environnements, tels que le développement, les tests et la production. Il peut être très difficile de gérer les mises à jour de l'environnement logiciel et de maintenir la cohérence de l'environnement partout. Cela est particulièrement vrai pour les organisations qui utilisent des centaines d'applications ou qui décomposent les applications en centaines de microservices. Docker résout ce problème grâce à la conteneurisation.


## Secrets vs Environment Variables
Env
 Simple et rapide à configurer
 Visible en clair via docker inspect, docker exec env, logs
 Accessible à tous les processus du container

Secrets
 Monté comme un fichier dans /run/secrets/ (pas une variable)
 Non visible via docker inspect ou docker exec env
 Plus sécurisé pour les mots de passe, tokens, clés
 Légèrement plus complexe à configurer

## Docker Network vs Host Network
Docker
 Chaque container a sa propre IP isolée
 Les containers communiquent entre eux par leur nom (nginx, wordpress, mariadb)
 Isolation totale du réseau hôte
 Tu contrôles exactement quels ports sont exposés
 Légèrement plus de config  

```
services:
  nginx:
    networks:
      - inception

networks:
  inception:
    driver: bridge
```

Host
 Le container utilise directement le réseau de la machine hôte
 Performances maximales (pas de NAT)
 Pas d'isolation → le container voit tout le réseau host
 Conflits de ports possibles
 Moins sécurisé

```
services:
  nginx:
    network_mode: host
```

## Docker Volumes vs Bind Mount
Docker
✅ Géré entièrement par Docker
✅ Données stockées dans /var/lib/docker/volumes/
✅ Portable et indépendant du système hôte
✅ Meilleures performances sur Docker Desktop (Mac/Windows)
❌ Moins facile d'accéder aux fichiers depuis l'hôte

Bind
✅ Tu choisis exactement où les données sont stockées sur l'hôte
✅ Accès direct aux fichiers depuis la machine hôte
✅ Pratique pour le développement (modifier des fichiers en temps réel)
✅ Obligatoire pour 42 Inception
❌ Dépend du chemin exact sur la machine hôte
❌ Moins portable

# Instructions


cd inception 
cp srcs/.env.example srcs/.env

# complete .env with your own info

make # to build and start the project

make stop # to stop the project

make clean # to stop all container and rm all volumes

# Resources
- https://docs.docker.com/
- https://blog.stephane-robert.info/docs/conteneurs/moteurs-conteneurs/docker/
- https://blog.stephane-robert.info/docs/conteneurs/moteurs-conteneurs/docker/secrets/
- https://tuto.grademe.fr/inception/
- https://github.com/Vikingu-del/Inception-Guide

