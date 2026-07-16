# ft_strmapi

## Description

Applique une fonction à chaque caractère d'une chaîne

## Prototype

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

## Paramètres

| Paramètre | Type | Description |
|-----------|------|-------------|
| `s` | `char const *` | Chaîne à parcourir |
| `f` | `char (*)(unsigned int, char)` | Fonction à appliquer |


## Valeur de retour

La nouvelle chaîne résultante ou NULL en cas d'erreur

## Description détaillée

La fonction `ft_strmapi` applique une fonction à chaque caractère d'une chaîne

## Exemple d'utilisation

```c
#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
    // Exemple d'utilisation de ft_strmapi
    // TODO: Ajoutez votre code ici
    return 0;
}
```

## Notes importantes

⚠️ **Attention** : Consultez la section paramètres pour les préconditions.

## Voir aussi

Consultez les autres fonctions de la catégorie dans la barre latérale.
