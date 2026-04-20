# Guide rapide — comprendre et retenir `microshell4.c`

## 1) Idée globale (à mémoriser)

Le shell lit les arguments (`av`) comme une suite de commandes séparées par :
- `|` (pipe)
- `;` (fin de commande)

Il découpe **un bloc à la fois**, exécute ce bloc, puis passe au suivant.

---

## 2) Les 3 fonctions clés

### `ft_cd(av, i)`
- Gère uniquement `cd`.
- Vérifie qu’il y a exactement 2 arguments (`cd` + chemin).
- Fait `chdir(av[1])`.
- Retourne `1` en cas d’erreur, `0` sinon.

### `ft_exec(av, i, &tmp_fd, envp)`
Exécute une commande “normale” (pas `cd`), avec ou sans pipe.

1. Détecte si le prochain séparateur est `|` (`next_is_pipe`).
2. Si pipe: `pipe(fd)`.
3. `fork()`.
4. **Child** :
   - Coupe la commande: `av[i] = NULL`.
   - Branche l’entrée depuis `tmp_fd` (`dup2(tmp_fd, STDIN)`).
   - Si pipe: branche la sortie vers `fd[1]` (`dup2(fd[1], STDOUT)`).
   - `execve(av[0], av, envp)`.
5. **Parent** :
   - Ferme l’ancien `tmp_fd`.
   - Si pipe: garde `fd[0]` dans `tmp_fd` pour la commande suivante.
   - Sinon: attend les enfants, puis reset `tmp_fd = dup(STDIN_FILENO)`.

### `main()`
- Initialise `tmp_fd` comme une copie de `STDIN`.
- Boucle sur `av` :
  - avance le pointeur `av += i` pour se placer au début du prochain bloc,
  - calcule `i` = taille du bloc jusqu’à `|` ou `;`,
  - si commande = `cd` → `ft_cd`,
  - sinon → `ft_exec`.
- Retourne le dernier `status`.

---

## 3) Le point le plus important: `tmp_fd`

`tmp_fd` représente “d’où la prochaine commande doit lire”.

- Au départ: `tmp_fd = STDIN`.
- Après une commande suivie de `|`: `tmp_fd` devient l’extrémité lecture du pipe.
- Après une commande finale (pas de `|`): `tmp_fd` revient à une copie de `STDIN`.

**Mémo examen:**  
`tmp_fd` = “entrée courante du pipeline”.

---

## 4) Simulation mentale (exemple)

Commande:
`./microshell4 /bin/echo hello "|" /usr/bin/wc -c ";" /bin/ls`

1. Bloc 1: `/bin/echo hello` (suivi de `|`)
   - écrit dans le pipe
   - parent garde la lecture du pipe dans `tmp_fd`
2. Bloc 2: `/usr/bin/wc -c` (fin `;`)
   - lit depuis `tmp_fd` (donc depuis echo)
   - pas de pipe ensuite → wait + reset `tmp_fd` sur STDIN
3. Bloc 3: `/bin/ls`
   - lit depuis STDIN normal

---

## 5) Erreurs à ne pas oublier

- `error: fatal` pour `pipe/fork/dup2` critiques.
- `error: cannot execute X` si `execve` échoue.
- `error: cd: bad arguments` si mauvais nombre d’arguments.
- `error: cd: cannot change directory to X` si `chdir` échoue.

---

## 6) Checklist de récitation (30 secondes)

1. Parser `av` par blocs jusqu’à `|` ou `;`.
2. `cd` exécuté dans le parent.
3. Sinon `fork` + `execve`.
4. Child: `dup2(tmp_fd -> stdin)`, et si pipe `dup2(fd[1] -> stdout)`.
5. Parent: met à jour `tmp_fd` avec `fd[0]` si pipe, sinon wait + reset stdin.

Si tu récites ça proprement, tu expliques tout le process de `microshell4.c`.
