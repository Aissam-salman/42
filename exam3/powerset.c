/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:11:02 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/07 18:33:52 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void print_comb(int *comb, int comb_size)
{
	for (int i = 0; i < comb_size; i++) {
		printf("%d", comb[i]);
		if (i < comb_size - 1)
			printf(" ");
	}
	printf("\n");
}


void backtracking(int *candidates, int size, int target, int *comb, int comb_size, int start, int max)
{
	if (comb_size == max)
	{
		if (target == 0)
			print_comb(comb, comb_size);
		return ;
	}
	if (target < 0)
		return;
	for (int i = start; i < size; i++) {
		comb[comb_size] = candidates[i];
		backtracking(candidates, size, target - candidates[i],comb , comb_size + 1, i + 1, max);
	}
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (1);
	int target = atoi(av[1]);
	int sizec = ac - 2;
	int *candidates = malloc(sizeof(int) * sizec);
	if (!candidates)
		return (1);
	int *comb = malloc(sizeof(int) * sizec);
	if (!comb)
		return (1);

	for (int i = 0; i < sizec; i++) {
		candidates[i] = atoi(av[i + 2]);
	}

	for (int k = 1; k <= sizec; k++) {
		backtracking(candidates, sizec, target, comb, 0, 0, k);
	}
	free(candidates);
	free(comb);
	return (0);
}
