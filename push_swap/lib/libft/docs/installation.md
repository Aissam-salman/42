# Installation

## Prérequis

- **Compilateur C** : gcc ou clang
- **Make** : pour la compilation automatique
- **Git** : pour cloner le dépôt

## Étapes d'installation

### 1. Cloner le dépôt

```bash
git clone https://github.com/Aissam-salman/42.git libft
cd libft/libft_pimp
```

### 2. Compiler la bibliothèque

```bash
make
```

Cette commande génère le fichier `libft.a` contenant toutes les fonctions principales.

### 3. Compiler avec les bonus (optionnel)

```bash
make bonus
```

Cette commande ajoute les fonctions bonus (listes chaînées) à la bibliothèque.

## Commandes Make disponibles

| Commande | Description |
|----------|-------------|
| `make` | Compile la bibliothèque principale |
| `make bonus` | Ajoute les fonctions bonus |
| `make clean` | Supprime les fichiers objets (.o) |
| `make fclean` | Supprime les fichiers objets et la bibliothèque |
| `make re` | Recompile entièrement (fclean + all) |

## Utilisation dans vos projets

### Compiler avec libft

```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lft -I./includes -o your_program
```

**Explication des flags :**
- `-L.` : cherche la bibliothèque dans le répertoire courant
- `-lft` : lie avec libft.a
- `-I./includes` : ajoute le dossier includes au chemin de recherche des headers

### Exemple de fichier Makefile

```makefile
NAME = my_program
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft_pimp
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)/includes

SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
```

## Structure des fichiers

Après compilation, votre projet aura cette structure :

```
libft_pimp/
├── includes/
│   ├── libft.h          ← Header principal
│   ├── ft_printf.h      ← Header pour printf
│   └── get_next_line.h  ← Header pour GNL
├── src/
│   ├── *.o              ← Fichiers objets
│   └── ...
├── libft.a              ← Bibliothèque compilée
├── Makefile
└── docs/
```

## Inclure les headers

Dans vos fichiers .c, incluez les headers nécessaires :

```c
#include "includes/libft.h"          // Fonctions principales
#include "includes/ft_printf.h"      // Pour ft_printf
#include "includes/get_next_line.h"  // Pour get_next_line
```

## Vérification de l'installation

Pour vérifier que la bibliothèque fonctionne correctement :

```bash
# Créer un fichier de test
cat > test.c << 'EOF'
#include "includes/libft.h"
#include "includes/ft_printf.h"

int main(void)
{
    ft_printf("Libft fonctionne ! 🎉\n");
    return 0;
}
EOF

# Compiler
gcc test.c -L. -lft -I. -o test

# Exécuter
./test
```

Si vous voyez le message "Libft fonctionne ! 🎉", l'installation est réussie ! ✅

## Dépannage

### Erreur : "cannot find -lft"
Assurez-vous que `libft.a` existe dans le répertoire et que vous utilisez `-L.` pour indiquer le chemin.

### Erreur : "libft.h: No such file or directory"
Vérifiez que vous utilisez `-I./includes` ou le bon chemin vers le dossier includes.

### Erreur lors de la compilation
Essayez de nettoyer et recompiler :
```bash
make fclean
make
```

---

Une fois l'installation terminée, vous pouvez consulter la documentation des fonctions dans les sections suivantes ! 📚
