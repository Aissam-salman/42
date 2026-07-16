# ft_strlen

## Description

Calcule la longueur d'une chaîne de caractères.

## Prototype

```c
size_t ft_strlen(const char *s);
```

## Paramètres

| Paramètre | Type | Description |
|-----------|------|-------------|
| `s` | `const char *` | La chaîne dont on veut connaître la longueur |

## Valeur de retour

Retourne le nombre de caractères dans la chaîne, **sans compter** le caractère nul de fin (`\0`).

## Description détaillée

La fonction `ft_strlen` parcourt la chaîne de caractères jusqu'à trouver le caractère nul de terminaison et compte le nombre de caractères rencontrés.

Cette fonction est l'équivalent de la fonction standard `strlen` de `<string.h>`.

## Implémentation

```c
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
```

## Exemples d'utilisation

### Exemple 1 : Utilisation basique

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = "Hello, World!";
    size_t len;

    len = ft_strlen(str);
    printf("La longueur de '%s' est %zu\n", str, len);
    // Affiche: La longueur de 'Hello, World!' est 13
    return 0;
}
```

### Exemple 2 : Chaîne vide

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *empty = "";

    printf("Longueur d'une chaîne vide: %zu\n", ft_strlen(empty));
    // Affiche: Longueur d'une chaîne vide: 0
    return 0;
}
```

### Exemple 3 : Utilisation avec allocation dynamique

```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = "Bonjour 42!";
    char *copy;
    size_t len;

    len = ft_strlen(str);
    copy = malloc(sizeof(char) * (len + 1));
    if (copy)
    {
        ft_strlcpy(copy, str, len + 1);
        printf("Copie: %s (longueur: %zu)\n", copy, ft_strlen(copy));
        free(copy);
    }
    return 0;
}
```

## Notes importantes

⚠️ **Attention** : La fonction ne vérifie pas si le pointeur est NULL. Passer un pointeur NULL causera un segmentation fault.

💡 **Astuce** : `ft_strlen` est souvent utilisée avant d'allouer de la mémoire pour copier une chaîne.

## Complexité

- **Temps** : O(n) où n est la longueur de la chaîne
- **Espace** : O(1)

## Voir aussi

- [ft_strlcpy](ft_strlcpy.md) - Copie une chaîne
- [ft_strlcat](ft_strlcat.md) - Concatène des chaînes
- [ft_strdup](ft_strdup.md) - Duplique une chaîne
