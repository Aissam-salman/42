# Fiches de Révision — Exam Shell 42

---

## 1. broken_gnl — Get Next Line

### Concept
Lire ligne par ligne depuis un fd. Un `static char *store[1024]` garde le reste non-lu entre les appels.

### Flux d'appel
```
get_next_line(fd)
  └─ read_line(store, fd)       ← lit dans fd jusqu'à trouver '\n' ou EOF
       └─ ft_strjoin(store[fd], buffer)  ← accumule dans store
  └─ get_line(store[fd])        ← extrait la ligne (avec '\n' inclus)
  └─ clean_line(store[fd])      ← coupe après le '\n', garde le reste
```

### Fonctions helper à connaître
| Fonction | Rôle |
|---|---|
| `have_endl(str)` | retourne 1 si '\n' trouvé dans str |
| `get_line(re)` | malloc + copie jusqu'à '\n' inclus |
| `clean_line(re)` | retourne ce qui est après le '\n', free l'ancien store |
| `read_line(store, fd)` | boucle `read()` tant que pas de '\n' |

### Code clé
```c
char *get_next_line(int fd)
{
    static char *store[1024];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!read_line(store, fd))         // remplit store[fd]
        return (NULL);
    line = get_line(store[fd]);        // extrait la ligne
    store[fd] = clean_line(store[fd]); // nettoie le reste
    return (line);
}
```

### Pièges
- `clean_line` et `get_line` doivent gérer `!re` et `!re[0]`
- `clean_line` : `malloc(ft_strlen(re) - i)` → taille = reste APRÈS '\n'
- `read_line` : toujours `free(tmp)` avant de réassigner `store[fd]`
- Ne pas oublier `buffer[read_b] = '\0'` après `read()`

---

## 2. filter — Remplacer un mot par des `*`

### Concept
Lire stdin en entier dans un buffer, puis parcourir. À chaque fois qu'on trouve `av[1]`, on imprime autant de `*` que la longueur du mot. Sinon on imprime le caractère courant.

### Code clé
```c
int main(int ac, char **av)
{
    if (ac != 2)
        return (1);

    char buf[4096];
    int  len = strlen(av[1]);
    int  i = 0;
    char c;

    while (read(0, &c, 1) != 0)
        buf[i++] = c;
    buf[i] = 0;

    i = 0;
    while (buf[i])
    {
        if (strncmp(&buf[i], av[1], len) == 0)
        {
            for (int j = 0; j < len; j++)
                write(1, "*", 1);
            i += len;           // sauter tout le mot
        }
        else
            write(1, &buf[i++], 1);
    }
    return (0);
}
```

### Pièges
- `i += len` et non `i++` quand on a trouvé le mot
- Lire TOUT stdin avant de traiter
- `buf[i] = 0` après la boucle de lecture

---

## 3. permutations — Toutes les permutations d'une chaîne

### Concept
**Backtracking** par swap. On fixe chaque caractère à la position `left`, puis on permute le reste récursivement. On re-swap après pour restaurer l'état (backtrack).

### Code clé
```c
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void permutation(char *str, int left, int right)
{
    if (left == right)
    {
        printf("%s\n", str);
        return ;
    }
    for (int i = left; i <= right; i++)
    {
        swap(str + left, str + i);       // choisir str[i] pour position left
        permutation(str, left + 1, right);
        swap(str + left, str + i);       // RESTAURER (backtrack)
    }
}

// Appel : permutation(str, 0, strlen(str) - 1);
```

### Visualisation pour "abc"
```
left=0: i=0 swap(a,a)→abc  left=1: i=1 swap(b,b)→abc  left=2: print abc
                                    i=2 swap(b,c)→acb  left=2: print acb
        i=1 swap(a,b)→bac  left=1: i=1 swap(a,a)→bac  left=2: print bac
                                    ...
        i=2 swap(a,c)→cba  ...
```

### Pièges
- Le **2e swap est obligatoire** pour restaurer la chaîne (backtrack)
- `right = strlen(str) - 1` (index du dernier char, pas la longueur)
- Cas de base : `left == right` (plus qu'un seul caractère à placer)

---

## 4. powerset / combination sum — Sous-ensembles dont la somme = target

### Concept
**Backtracking** : on essaie d'ajouter chaque candidat à une combinaison. On passe `start` pour éviter les doublons. On boucle `max` de 1 à n pour trouver toutes les tailles possibles.

### Code clé
```c
void backtracking(int *cands, int size, int target,
                  int *comb, int comb_size, int start, int max)
{
    if (comb_size == max)
    {
        if (target == 0)
            print_comb(comb, comb_size);
        return ;
    }
    if (target < 0)
        return ;
    for (int i = start; i < size; i++)
    {
        comb[comb_size] = cands[i];
        backtracking(cands, size, target - cands[i],
                     comb, comb_size + 1, i + 1, max);
    }
}

// Dans main :
for (int k = 1; k <= sizec; k++)
    backtracking(candidates, sizec, target, comb, 0, 0, k);
```

### Pièges
- `i + 1` comme nouveau `start` → chaque élément utilisé au plus une fois
- Vérifier `target < 0` pour élaguer tôt (pruning)
- On n'imprime QUE quand `comb_size == max` ET `target == 0`
- `candidates` = `av[2..ac-1]`, `target` = `av[1]`

---

## 5. nqueens — N reines sur un échiquier N×N

### Concept
Placer une reine par ligne. `board[row] = col` = "la reine de la ligne `row` est en colonne `col`". On vérifie pour chaque ligne précédente l'absence de conflit colonne et diagonale.

### is_safe
```c
int is_safe(int *board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col)                // même colonne
            return (0);
        if (abs(board[i] - col) == row - i) // même diagonale
            return (0);
    }
    return (1);
}
```

### solve
```c
void solve(int *board, int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", board[i]);
        printf("\n");
        return ;
    }
    for (int col = 0; col < n; col++)
    {
        if (is_safe(board, row, col))
        {
            board[row] = col;
            solve(board, n, row + 1);
            // pas de reset : la prochaine itération écrase board[row]
        }
    }
}
```

### Pièges
- Diagonale : `abs(col_diff) == row_diff` → les deux conditions en une ligne
- Output : chiffres **collés** (pas d'espace), un `\n` par solution
- `board` alloué avec `malloc(sizeof(int) * n)`, free à la fin
- Pas besoin de reset `board[row]` car la boucle for le réassigne

---

## 6. ft_scanf — Implémentation simplifiée de scanf

### Concept
Lire stdin en entier dans un buffer, puis parser selon le format. On avance un index `i` dans le buffer au fur et à mesure. On gère `%d`/`%i`, `%s` et `%c`.

### Fonctions helper
| Fonction | Rôle |
|---|---|
| `skip(buf, i)` | avance `i` en sautant les espaces |
| `read_int(buf, i, *n)` | lit un entier, retourne le nouvel `i` |
| `read_str(buf, i, dest)` | lit un mot (jusqu'à espace), retourne le nouvel `i` |
| `convert(spec, buf, i, args)` | dispatch selon le specifier `%` |

### Code clé
```c
int ft_scanf(const char *fmt, ...)
{
    va_list args;
    char    buf[4096];
    int     n, i, count;

    n = read(0, buf, sizeof(buf) - 1);
    if (n <= 0) return (-1);
    buf[n] = '\0';
    i = 0; count = 0;
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            i = convert(*fmt, buf, i, args);
            if (i < 0) break;
            count++;
        }
        else if (isspace(*fmt))
            i = skip(buf, i);
        else
        {
            if (buf[i++] != *fmt) break;  // caractère littéral attendu
        }
        fmt++;
    }
    va_end(args);
    return (count);
}
```

### Pièges
- `%c` **ne skippe PAS** les espaces (contrairement à `%d` et `%s`)
- `read_int` retourne `-1` si pas de chiffre après le signe → `i < 0` → break
- Bien faire `buf[n] = '\0'` après `read()`
- `count` n'est incrémenté que si `convert` réussit (`i >= 0`)

---

## 7. rip — Remove Invalid Parentheses

### Concept
Trouver toutes les chaînes minimalement valides en supprimant le minimum de parenthèses invalides. La fonction `prepa` calcule combien il faut retirer : `nb_open` ouvrants en trop, `nb_close` fermants en trop. Puis `solve` backtrack en essayant de garder ou supprimer chaque parenthèse.

### prepa — calculer les suppressions nécessaires
```c
void prepa(char *source, int *score, int *nb_open, int *nb_close)
{
    int i = 0;
    while (source[i])
    {
        if (source[i] == '(')
            (*score)++;
        else if (source[i] == ')' && *score == 0)
            (*nb_close)++;   // ')' orphelin → à supprimer
        else if (source[i] == ')')
            (*score)--;
        i++;
    }
    if (*score > 0)
        *nb_open = *score;   // '(' non fermés → à supprimer
}
```

### solve — backtracking
```c
void solve(char *source, int i, int nb_open, int nb_close, int score)
{
    if (score < 0 || nb_open < 0 || nb_close < 0) return;
    if (source[i] == '\0')
    {
        if (score == 0 && nb_open == 0 && nb_close == 0)
            puts(source);   // solution valide
        return;
    }
    char tmp = source[i];
    // Cas 1 : garder source[i]
    if (source[i] == '(')
        solve(source, i + 1, nb_open, nb_close, score + 1);
    else if (source[i] == ')' && score > 0)
        solve(source, i + 1, nb_open, nb_close, score - 1);
    else if (source[i] != '(' && source[i] != ')')
        solve(source, i + 1, nb_open, nb_close, score);
    // Cas 2 : supprimer source[i] (remplacer par espace)
    if (source[i] == '(' && nb_open > 0)
    {
        source[i] = ' ';
        solve(source, i + 1, nb_open - 1, nb_close, score);
        source[i] = tmp;   // backtrack
    }
    else if (source[i] == ')' && nb_close > 0)
    {
        source[i] = ' ';
        solve(source, i + 1, nb_open, nb_close - 1, score);
        source[i] = tmp;   // backtrack
    }
}
```

### Pièges
- `score` = profondeur courante des `(` non fermés, doit rester ≥ 0
- On supprime en remplaçant par `' '` puis on **restore** (`source[i] = tmp`)
- Condition finale : `score == 0 && nb_open == 0 && nb_close == 0`
- Ne pas oublier le cas `source[i] != '(' && source[i] != ')'` (lettres)

---

## 8. tsp — Travelling Salesman Problem (Voyageur de Commerce)

### Concept
**Brute-force** : générer toutes les permutations des villes, calculer la distance du circuit pour chacune, garder le minimum. Même pattern swap/backtrack que les permutations.

### Structure
```c
typedef struct {
    float x[MAX], y[MAX];  // coordonnées des villes
    int   chemin[MAX];     // permutation en cours
    int   n;               // nombre de villes
    float best;            // meilleure distance trouvée
} t_tsp;
```

### Code clé
```c
float dist(t_tsp *t, int a, int b)
{
    float dx = t->x[a] - t->x[b];
    float dy = t->y[a] - t->y[b];
    return sqrtf(dx * dx + dy * dy);
}

float circuit(t_tsp *t)
{
    float total = 0;
    for (int i = 0; i < t->n - 1; i++)
        total += dist(t, t->chemin[i], t->chemin[i + 1]);
    total += dist(t, t->chemin[t->n - 1], t->chemin[0]); // retour au départ
    return total;
}

void permute(t_tsp *t, int k)
{
    if (k == t->n)
    {
        float d = circuit(t);
        if (d < t->best) t->best = d;
        return;
    }
    for (int i = k; i < t->n; i++)
    {
        swap(t, k, i);
        permute(t, k + 1);
        swap(t, k, i);   // backtrack
    }
}
```

### Lecture stdin
```c
while (fscanf(stdin, "%f, %f\n", &tsp.x[tsp.n], &tsp.y[tsp.n]) == 2)
    tsp.n++;
tsp.best = 1e30f;  // infini initial
```

### Pièges
- Initialiser `best = 1e30f` (valeur "infinie")
- Le circuit est **fermé** : ajouter `dist(chemin[n-1], chemin[0])`
- `fscanf` retourne le nombre de conversions réussies → vérifier `== 2`
- Même double-swap que permutations (avant récursion + backtrack)

---

## Récap rapide des patterns

| Exercice | Pattern | Astuce clé |
|---|---|---|
| broken_gnl | static buffer + read | `have_endl` → `get_line` → `clean_line` |
| filter | lecture stdin puis scan | `strncmp` + `i += len` |
| permutations | swap/backtrack | double swap (avant + après récursion) |
| powerset | backtrack + target | `start=i+1`, boucler sur `max` |
| nqueens | backtrack ligne/col | `abs(col_diff) == row_diff` pour diagonale |
| ft_scanf | parse format + va_args | `%c` ne skippe pas les espaces |
| rip | backtrack + supprimer/garder | `prepa` calcule nb à retirer, restore après |
| tsp | permute toutes les villes | circuit fermé, `best = 1e30f` |
