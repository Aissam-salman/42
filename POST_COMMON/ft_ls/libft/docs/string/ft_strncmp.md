# ft_strncmp

## Description

Compare deux chaînes sur n caractères maximum

## Prototype

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

## Paramètres

| Paramètre | Type | Description |
|-----------|------|-------------|
| `s1` | `const char *` | Première chaîne |
| `s2` | `const char *` | Deuxième chaîne |
| `n` | `size_t` | Nombre maximum de caractères à comparer |


## Valeur de retour

0 si égales, <0 si s1 < s2, >0 si s1 > s2

## Description détaillée

La fonction `ft_strncmp` compare deux chaînes sur n caractères maximum

## Exemple d'utilisation

```c
#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
    // Exemple d'utilisation de ft_strncmp
    // TODO: Ajoutez votre code ici
    return 0;
}
```

## Notes importantes

⚠️ **Attention** : Consultez la section paramètres pour les préconditions.

## Voir aussi

Consultez les autres fonctions de la catégorie dans la barre latérale.
