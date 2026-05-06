# Configuration et Spécifications de l'Environnement de Travail (École 42)

Ce document répertorie les outils, versions et librairies nécessaires pour recréer à l'identique l'environnement de développement disponible sur les postes sous Fedora à l'École 42.

## 1. Système d'Exploitation et Noyau
*   **Système d'Exploitation** : Fedora Linux 42 (Adams)
*   **Architecture** : x86_64
*   **Noyau (Kernel)** : Linux 6.19.12-100.fc42.x86_64

## 2. Chaîne de Compilation (C / C++)
*   **GCC** : 15.2.1 (Red Hat 15.2.1-7)
*   **G++** : 15.2.1
*   **Clang** : 20.1.8 (Fedora 20.1.8-4.fc42)
*   **Make** : GNU Make 4.4.1

## 3. Outils de Débogage et Mémoire
*   **Valgrind** : 3.26.0
*   **GDB** : 17.1-1.fc42

## 4. Outils Spécifiques à l'École 42
*   **Norminette** : 3.3.59
*   **Python** (utilisé par la norminette) : 3.13.12
*   **Bash** : 5.2.37

## 5. Bibliothèques de Développement (Headers / Devel)
Ces paquets sont particulièrement nécessaires pour des projets comme `minishell`, `cub3d`, `fract-ol` (MinilibX, manipulation système, etc.) :
*   **Readline** (`readline-devel`) : Nécessaire pour Minishell.
*   **libX11** (`libX11-devel`) : Nécessaire pour la MinilibX sous Linux.
*   **libXext** (`libXext-devel`) : Nécessaire pour la MinilibX sous Linux.
*   **libbsd** (`libbsd-devel`) : Utile pour certaines fonctions conformes à bsd.
*   **GLFW** (`glfw-devel`) : Utile pour des projets graphiques avancés.

## 6. Commandes d'Installation Typiques (sur une nouvelle VM Fedora 42)

Pour remettre en place cet environnement sur une nouvelle machine Fedora, vous pouvez utiliser la commande suivante :

```bash
# Mise à jour du système
sudo dnf update -y

# Installation des compilateurs et outils de base
sudo dnf install -y gcc gcc-c++ clang make valgrind gdb git python3 python3-pip bash

# Installation des dépendances graphiques et systèmes (MinilibX, Minishell)
sudo dnf install -y readline-devel libX11-devel libXext-devel libbsd-devel glfw-devel

# Installation de la Norminette
pip3 install norminette
```
