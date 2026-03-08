/*
** TSP - Problème du Voyageur de Commerce
** Algorithme : Brute-force (toutes les permutations)
**
** ÉTAPES :
**   1. Lire les villes depuis stdin dans une structure
**   2. Tester toutes les permutations (récursif + backtrack)
**   3. Garder la distance minimale du circuit fermé
**   4. Afficher cette distance
*/

#include <stdio.h>
#include <math.h>

#define MAX 12

typedef struct
{
    float   x[MAX];     /* coordonnées x des villes */
    float   y[MAX];     /* coordonnées y des villes */
    int     chemin[MAX];/* permutation en cours d'exploration */
    int     n;          /* nombre de villes */
    float   best;       /* meilleure distance trouvée */
} t_tsp;

/* Distance euclidienne entre deux villes */
float dist(t_tsp *t, int a, int b)
{
    float dx = t->x[a] - t->x[b];
    float dy = t->y[a] - t->y[b];
    return sqrtf(dx * dx + dy * dy);
}

/* Distance totale du circuit (inclut le retour à la ville de départ) */
float circuit(t_tsp *t)
{
    float total = 0;
    int   i;

    for (i = 0; i < t->n - 1; i++)
        total += dist(t, t->chemin[i], t->chemin[i + 1]);
    total += dist(t, t->chemin[t->n - 1], t->chemin[0]); /* retour au départ */
    return total;
}

/* Échange deux positions dans le chemin */
void swap(t_tsp *t, int i, int j)
{
    int tmp      = t->chemin[i];
    t->chemin[i] = t->chemin[j];
    t->chemin[j] = tmp;
}

/*
** permute(t, k) : génère toutes les permutations à partir de la position k
**
**  BASE     : k == n  → chemin complet → comparer la distance avec best
**  RECURSIF : pour chaque ville i encore libre (i >= k) :
**               swap(k, i)      ← met la ville i en position k
**               permute(k + 1)  ← complète le reste du chemin
**               swap(k, i)      ← annule (backtrack)
*/
void permute(t_tsp *t, int k)
{
    float d;
    int   i;

    if (k == t->n)
    {
        d = circuit(t);
        if (d < t->best)
            t->best = d;
        return;
    }
    for (i = k; i < t->n; i++)
    {
        swap(t, k, i);
        permute(t, k + 1);
        swap(t, k, i);
    }
}

int main(void)
{
    t_tsp tsp;
    int   i;

    /* 1. Lire les villes */
    tsp.n = 0;
    while (fscanf(stdin, "%f, %f\n", &tsp.x[tsp.n], &tsp.y[tsp.n]) == 2)
        tsp.n++;

    if (tsp.n == 0)
        return (1);

    /* 2. Initialiser le chemin et best */
    for (i = 0; i < tsp.n; i++)
        tsp.chemin[i] = i;
    tsp.best = 1e30f;

    /* 3. Chercher le meilleur chemin */
    permute(&tsp, 0);

    /* 4. Afficher la distance minimale */
    printf("%.2f\n", tsp.best);

    return (0);
}
