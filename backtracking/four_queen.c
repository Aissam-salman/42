/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_queen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:29:59 by alamjada          #+#    #+#             */
/*   Updated: 2026/02/02 13:33:15 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void print_board(int n, char board[n][n])
{
	static int configs = 0;
	++configs;
	printf("config: %d\n", configs);
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			printf("%s", board[row][col] == 'Q' ? "[Q]" : "[ ]");
		}
		printf("\n");
	}
	printf("\n\n");
}

int is_safe(int n, char board[n][n], int row, int col)
{
	int r,c;

	c = 0;
	while (c < col)
	{
		if (board[row][c] == 'Q')
			return (0);
		c++;
	}
	r = row;
	c = col;
	while (r >= 0 && c >= 0)
	{
		if (board[r][c] == 'Q')
			return (0);
		r--;
		c--;
	}
	r = row;
	c = col;
	while (r < n && c>= 0)
	{
		if (board[r][c] == 'Q')
			return (0);
		r++;
		c--;
	}
	return (1);
}

int find_solution(int n, char board[n][n], int col)
{
	if (col == n)
	{
		print_board(n, board);
		// return (1);
	}
	int row = 0;
	while (row < n)
	{
		if (is_safe(n, board, row, col))
		{
			board[row][col] = 'Q';
			if (find_solution(n, board, col + 1))
				return (1);
			board[row][col] = '0';
		}
		row++;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int len = atoi(av[1]);
		char chessboard[len][len];
		bzero(chessboard, len * len);
		find_solution(len, chessboard, 0);
	}
	return (0);
}
