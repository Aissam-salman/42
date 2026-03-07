/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:35:17 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/07 18:43:14 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_safe(int *board, int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (board[i] == col)
			return (0);
		if (abs(board[i] - col) == row - i)
			return (0);
	}
	return (1);
}

void solve(int *board, int n, int row)
{
	if (row == n)
	{
		for (int i = 0; i < n; i++) {
			printf("%d", board[i]);
		}
		printf("\n");
		return ;
	}
	for (int col = 0; col < n; col++) {
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve(board, n, row + 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int n = atoi(av[1]);
	int *board = malloc(sizeof(int) * n);
	if (!board)
		return (1);
	solve(board, n, 0);
	free(board);
	return (0);
}
