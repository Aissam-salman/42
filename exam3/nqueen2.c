/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:41:54 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/09 19:42:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int is_safe(int *board, int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (board[i] == col)
			return (0);
		else if (abs(board[i] - col) == row - i)
			return (0);
	}
	return (1);
}

void solve(int *board, int n, int row)
{
	if (n == row)
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
	int *board;
	int n;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	board = malloc(sizeof(int) * n);
	if (!board)
		return (1);
	solve(board, n, 0);
	free(board);
	return (0);
}
