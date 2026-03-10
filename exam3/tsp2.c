#include <stdio.h>
#include <math.h>

#define MAX 12

typedef struct s_tsp
{
	float x[MAX];
	float y[MAX];
	int way[MAX];
	int nb_city;
	float best;
} t_tsp;


float dist(t_tsp *t, int a, int b)
{
	float dx = t->x[a] - t->x[b];
	float dy = t->y[a] - t->y[b];
	return (sqrtf(dx * dx + dy * dy));
}

float circle(t_tsp *t)
{
	float total = 0;

	for (int i = 0; i < t->nb_city - 1; i++) {
		total += dist(t, t->way[i], t->way[i + 1]);
	}
	total += dist(t, t->way[t->nb_city - 1], t->way[0]);
	return (total);
}

void swap(t_tsp *t, int i, int j)
{
	int tmp;

	tmp = t->way[i];
	t->way[i] = t->way[j];
	t->way[j] = tmp;
}

void compute(t_tsp *t, int k)
{
	float distance;
	int i;

	if (k == t->nb_city)
	{
		distance = circle(t);
		if (distance < t->best)
			t->best = distance;
		return ;
	}
	for(i = k; i < t->nb_city; i++)
	{
		swap(t, k, i);
		compute(t, k + 1);
		swap(t, k, i);
	}
}

int main(void)
{
	t_tsp tsp;
	int i;

	tsp.nb_city = 0;
	while (fscanf(stdin, "%f, %f\n", &tsp.x[tsp.nb_city], &tsp.y[tsp.nb_city]) == 2)
		tsp.nb_city++;

	if (tsp.nb_city == 0)
		return (1);
	for (i = 0; i < tsp.nb_city; i++) {
		tsp.way[i] = i;
	}
	tsp.best = 1e30f;
	compute(&tsp, 0);
	printf("%.2f\n", tsp.best);
	return (0);
}
