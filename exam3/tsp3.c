#include <math.h>
#include <stdio.h>

#define MAX 12

typedef struct s_tsp
{
	float	x[MAX];
	float	y[MAX];
	int		way[MAX];
	int		nbcity;
	float	best;
}			t_tsp;

float	dist(t_tsp *t, int a, int b)
{
	float	dx;
	float	dy;

	dx = t->x[a] - t->x[b];
	dy = t->y[a] - t->y[b];
	return (sqrtf(dx * dx + dy * dy));
}

float	visit(t_tsp *t)
{
	float	total;

	total = 0;
	for (int i = 0; i < t->nbcity - 1; i++)
		total += dist(t, t->way[i], t->way[i + 1]);
	total += dist(t, t->way[t->nbcity - 1], t->way[0]);
	return (total);
}

void	swap(t_tsp *t, int i, int j)
{
	int	tmp;

	tmp = t->way[i];
	t->way[i] = t->way[j];
	t->way[j] = tmp;
}

void	compute(t_tsp *t, int k)
{
	float	dist;
	int		i;

	if (k == t->nbcity)
	{
		dist = visit(t);
		if (dist < t->best)
			t->best = dist;
		return ;
	}
	for (i = k; i < t->nbcity; i++)
	{
		swap(t, k, i);
		compute(t, k + 1);
		swap(t, k, i);
	}
}

int	main(void)
{
	t_tsp	tsp;
	int		i;

	tsp.nbcity = 0;
	while (fscanf(stdin, "%f, %f\n", &tsp.x[tsp.nbcity],
			&tsp.y[tsp.nbcity]) == 2)
		tsp.nbcity++;
	if (tsp.nbcity == 0)
		return (1);
	for (i = 0; i < tsp.nbcity; i++)
		tsp.way[i] = i;
	tsp.best = 1e30f;
	compute(&tsp, 0);
	printf("%.2f\n", tsp.best);
	return (0);
}
