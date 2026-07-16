# get_next_line

## Description

Lit une ligne depuis un file descriptor. Chaque appel retourne la ligne suivante.

## Prototype

```c
char *get_next_line(int fd);
```

## Paramètres

| Paramètre | Type | Description |
|-----------|------|-------------|
| `fd` | `int` | File descriptor depuis lequel lire |

## Valeur de retour

- La ligne lue (avec le `\n` final si présent)
- `NULL` si fin de fichier ou erreur

## Description détaillée

`get_next_line` lit un file descriptor ligne par ligne. La fonction utilise un buffer statique pour gérer les lectures entre les appels.

### Configuration

La taille du buffer de lecture peut être définie à la compilation :

```bash
gcc -D BUFFER_SIZE=42 ...
```

Par défaut, `BUFFER_SIZE` est défini à 42.

## Exemple d'utilisation

### Lecture d'un fichier

```c
#include "includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### Lecture depuis stdin

```c
#include "includes/get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;

    printf("Entrez du texte (Ctrl+D pour terminer):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Lu: %s", line);
        free(line);
    }
    return 0;
}
```

## Notes importantes

⚠️ **Gestion mémoire** : Chaque ligne retournée doit être libérée avec `free()`.

⚠️ **Comportement** : La fonction conserve un état interne entre les appels. Ne pas mélanger les lectures sur différents fd sans terminer complètement un fichier.

💡 **Buffer size** : Un BUFFER_SIZE plus grand améliore les performances pour les gros fichiers, mais consomme plus de mémoire.

## Complexité

- **Temps** : O(n) où n est la longueur de la ligne
- **Espace** : O(BUFFER_SIZE)

## Cas particuliers

- **Fichier vide** : Retourne NULL immédiatement
- **Ligne sans \n** : La dernière ligne sans newline est retournée normalement
- **Fd invalide** : Retourne NULL

## Voir aussi

- [ft_strlen](../string/ft_strlen.md)
- [ft_strjoin](../string/ft_strjoin.md)
- [ft_substr](../string/ft_substr.md)
