# ft_lstmap

## Description

Crée une nouvelle liste en appliquant une fonction

## Prototype

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

## Paramètres

| Paramètre | Type | Description |
|-----------|------|-------------|
| `lst` | `t_list *` | Liste à parcourir |
| `f` | `void *(*)(void *)` | Fonction à appliquer |
| `del` | `void (*)(void *)` | Fonction de suppression en cas d'erreur |


## Valeur de retour

La nouvelle liste ou NULL en cas d'erreur

## Description détaillée

La fonction `ft_lstmap` crée une nouvelle liste en appliquant une fonction

## Exemple d'utilisation

```c
#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
    // Exemple d'utilisation de ft_lstmap
    // TODO: Ajoutez votre code ici
    return 0;
}
```

## Notes importantes

⚠️ **Attention** : Consultez la section paramètres pour les préconditions.

## Voir aussi

Consultez les autres fonctions de la catégorie dans la barre latérale.
