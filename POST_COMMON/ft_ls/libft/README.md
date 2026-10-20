# 📚 Libft - Extended C Library

Une bibliothèque C complète et optimisée développée dans le cadre du cursus 42. Cette bibliothèque réimplémente les fonctions standard de la libc et ajoute des fonctionnalités supplémentaires incluant `ft_printf`, `get_next_line`, et des utilitaires de conversion de bases.

[![Norminette](https://img.shields.io/badge/norminette-passing-success)](https://github.com/42School/norminette)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

## 📖 Documentation

📝 **Documentation complète avec Docsify**

Une documentation interactive et moderne de toutes les fonctions est disponible !

### Consulter la documentation

```bash
# Méthode rapide (recommandé)
./serve_docs.sh

# Ou avec Docsify
npm install -g docsify-cli
docsify serve docs

# Puis ouvrez http://localhost:3000
```

La documentation contient :
- ✅ **57 fonctions documentées** avec exemples
- ✅ **Recherche en temps réel** pour trouver rapidement
- ✅ **Interface moderne** responsive et intuitive
- ✅ **Exemples de code** copiables en un clic

👉 Consultez le [DOCUMENTATION_GUIDE.md](DOCUMENTATION_GUIDE.md) pour plus d'informations.

## ✨ Fonctionnalités

### 🔤 Fonctions de manipulation de chaînes
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`
- `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`
- `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`

### 🧮 Fonctions de manipulation de mémoire
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_memchr`, `ft_memcmp`, `ft_calloc`

### 🔍 Fonctions de vérification de caractères
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_toupper`, `ft_tolower`

### 🔢 Fonctions de conversion
- `ft_atoi`, `ft_itoa`
- `ft_atoi_base`, `ft_itoa_base`, `ft_convert_base` (conversions entre bases)

### 📤 Fonctions d'entrée/sortie
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- `ft_printf` - Implémentation complète de printf

### 📋 Fonctions de listes chaînées
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
- `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`
- `ft_lstiter`, `ft_lstmap`

### 📄 Lecture de fichiers
- `get_next_line` - Lecture ligne par ligne depuis un file descriptor

### 🛠️ Fonctions utilitaires
- `ft_swap`, `ft_reverse`, `ft_power`

## 🚀 Installation

```bash
# Cloner le dépôt
git clone https://github.com/Aissam-salman/42.git libft
cd libft/libft_pimp

# Compiler la bibliothèque
make

# Compiler avec les bonus (listes chaînées)
make bonus

# Nettoyer les fichiers objets
make clean

# Nettoyer tous les fichiers générés
make fclean

# Recompiler depuis zéro
make re
```

Cela génère `libft.a` dans le répertoire courant.

## 💻 Utilisation

### Exemple basique

```c
#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("hello world");
    char **words = ft_split(str, ' ');

    ft_printf("Chaîne originale: %s\n", str);
    ft_printf("Première mot: %s\n", words[0]);
    ft_printf("Deuxième mot: %s\n", words[1]);

    free(str);
    // Libérer words...
    return 0;
}
```

### Compilation avec votre projet

```bash
# Compiler votre fichier avec la libft
gcc -Wall -Wextra -Werror your_file.c -L. -lft -I./includes -o your_program

# Exécuter
./your_program
```

### Utilisation de ft_printf

```c
#include "includes/ft_printf.h"

int main(void)
{
    ft_printf("Nombre: %d\n", 42);
    ft_printf("Hexadécimal: %x\n", 255);
    ft_printf("Pointeur: %p\n", &main);
    ft_printf("Caractère: %c\n", 'A');
    ft_printf("Chaîne: %s\n", "Hello 42!");
    return 0;
}
```

### Utilisation de get_next_line

```c
#include "includes/get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## 📁 Structure du projet

```
libft_pimp/
├── includes/           # Fichiers d'en-tête
│   ├── libft.h
│   ├── ft_printf.h
│   └── get_next_line.h
├── src/               # Code source
│   ├── ft_*.c         # Fonctions libft
│   ├── printf/        # Implémentation de ft_printf
│   └── get_next_line/ # Implémentation de get_next_line
├── docs/              # Documentation Docsify
├── Makefile           # Fichier de compilation
└── README.md          # Ce fichier
```

## 🧪 Tests

Pour tester la bibliothèque, vous pouvez utiliser des testeurs externes :

- [libft-war-machine](https://github.com/y3ll0w42/libft-war-machine)
- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [Tripouille/libftTester](https://github.com/Tripouille/libftTester)

## 📚 Ressources

- [Documentation C Standard Library](https://en.cppreference.com/w/c)
- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [42 Norminette](https://github.com/42School/norminette)

## 👤 Auteur

**Aissam Salman** - [@Aissam-salman](https://github.com/Aissam-salman)

## 📝 License

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

---

*Projet réalisé dans le cadre du cursus de l'école 42* 🎓
