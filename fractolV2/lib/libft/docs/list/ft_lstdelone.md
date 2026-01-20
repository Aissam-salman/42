# ft_lstdelone

## Description

Libère un élément de la liste

## Prototype

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

## Paramètres

| Paramètre | Type | Description |
|-----------|------|-------------|
| `lst` | `t_list *` | Élément à libérer |
| `del` | `void (*)(void *)` | Fonction de suppression du contenu |


## Valeur de retour

Aucune (void)

## Description détaillée

La fonction `ft_lstdelone` libère un élément de la liste

## Exemple d'utilisation

```c
#include "includes/libft.h"
#include <stdio.h>

int main(void)
{
    // Exemple d'utilisation de ft_lstdelone
    // TODO: Ajoutez votre code ici
    return 0;
}
```

## Notes importantes

⚠️ **Attention** : Consultez la section paramètres pour les préconditions.

## Voir aussi

Consultez les autres fonctions de la catégorie dans la barre latérale.
