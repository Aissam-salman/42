#include <stdio.h>
#include <stdlib.h>

void print_comb(int *comb, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d", comb[i]);
		if (i < len - 1)
			printf(" ");
	}
	printf("\n");
}

void backtrack(int *candidates, int size, int target, int *comb, int comb_size, int start, int max)
{
	if (comb_size == max)
	{
		if (target == 0)
			print_comb(comb, comb_size);
		return ;
	}
	if (target < 0)
		return ;
	for (int i = start; i < size; i++) {
		comb[comb_size] = candidates[i];
		backtrack(candidates, size, target - candidates[i], comb, comb_size + 1, i + 1, max);
	}
}

int main(int ac, char **av)
{
	int target;
	int sizec;
	int *candidates;
	int *comb;

	if (ac < 3)
		return (1);
	target = atoi(av[1]);
	sizec = ac - 2;
	candidates = malloc(sizeof(int) * sizec);
	if (!candidates)
		return (1);
	comb = malloc(sizeof(int) * sizec);
	if (!comb)
		return (1);
	for (int i = 0; i < sizec; i++) {
		candidates[i] = atoi(av[i + 2]);
	}
	for (int k = 1; k <= sizec; k++) {
		backtrack(candidates, sizec, target, comb, 0, 0, k);
	}
	free(candidates);
	free(comb);
	return (0);

}
