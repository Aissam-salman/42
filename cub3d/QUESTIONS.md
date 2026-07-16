# Cub3D - Guide de Lecture Rapide

## 1) A quoi sert chaque dossier

- `src/main.c`: point d'entree du programme.
- `src/parsing/`: lit le fichier `.cub`, valide format + map + textures.
- `src/core/`: logique de lancement du jeu et boucle MLX.
- `src/render/`: creation des images et rendu minimap/joueur.
- `src/utils/`: helpers (init MLX, erreurs, liens entre structs).
- `includes/`: prototypes, macros, structures globales.
- `maps/working/`: maps valides pour tester.
- `maps/broken/`: maps invalides pour tester les erreurs du parsing.

## 2) Chemin d'execution (du lancement au rendu)

1. `main()` zero `t_cub` avec `ft_bzero`.
2. `ft_parsing()` valide l'argument, ouvre le `.cub`, remplit `data->file`.
3. `ft_textures_parsing()` extrait NO/SO/WE/EA + floor/ceiling.
4. `ft_map_fill()` construit `data->map.map`, `height`, `width`.
5. `ft_map_check()` valide les caracteres + fermeture des murs + joueur unique.
6. `ft_game()` initialise MLX, minimap, hooks clavier/render.
7. `mlx_loop()` tourne en boucle et appelle `ft_map_render()`.

## 3) Les structures importantes

- `t_cub`: structure centrale (mlx, fenetre, map, player, textures, gc).
- `t_map`: la grille + dimensions + minimap integree.
- `t_minimap`: info d'affichage minimap + images des tiles.
- `t_player`: position, direction, marqueur visuel.
- `t_p_structs`: pointeurs partages pour recuperer facilement le contexte.

## 4) Macros utiles a connaitre

- `DATA(ptr)`: recupere `t_cub *` depuis une structure qui contient `t_p_structs`.
- `MAP(ptr)`, `MINIMAP(ptr)`, `PLAYER(ptr)`: memes idee pour les autres types.

But: eviter de passer `t_cub *` partout dans les signatures.

## 5) Pourquoi le code peut paraitre "spaghetti"

- Beaucoup de structs imbriquees (`data->map.minimap.tiles...`).
- Melange parsing, rendu et gestion memoire (GC) dans une meme execution.
- MiniLibX utilise des callbacks generiques (`int (*)()`), pas tres explicites.

## 6) Usage rapide

- Build: `make`
- Run: `./cub3d ./maps/working/basic.cub`
- Valgrind: `make leaks`
- Valgrind avec suppressions X11/readline: `make leaks_supp`

## 7) Comment lire le code sans se perdre

1. Lire `main.c` puis `ft_parsing()` (vue globale).
2. Lire `ft_game()` pour voir comment la boucle graphique est branchee.
3. Lire `ft_map_render()` pour comprendre ce qui est dessine a chaque frame.
4. Ensuite seulement, aller dans les details (`ft_cell_check`, `ft_img_init`, etc.).

## 8) Question tabs dans la map

Recommendation simple: interdire les tabs dans la map et retourner une erreur parsing.

Pourquoi:
- visuellement un tab n'a pas une largeur fixe,
- ca complique la validation des murs,
- ca introduit des differences entre editeurs.

Alternative possible: convertir `\t` en espaces AVANT validation, mais il faut choisir
une largeur fixe (souvent 4) et garder cette regle partout.