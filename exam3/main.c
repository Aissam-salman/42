/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:02:28 by alamjada          #+#    #+#             */
/*   Updated: 2026/02/02 11:15:43 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void print_board(int n, char board[n][n])
{
	int i;
	int j;

	i = 0;
	
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			printf("%c", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
}

/*
* @brief Find way using backtracking algo
* @param n size of board
* @param board 
* @param row 
* @param col 
* @return void
*/

int backtracking(int n, char board[n][n], int row, int col)
{
	if (!(row >= 0 && row < n && col >= 0 && col < n))
		return (0);
	else if (board[row][col] == '#' || board[row][col] == 'X')
		return (0);
	else if (board[row][col] == 'E')
	{
		board[row][col] = 'X';
		return (1);
	}
	else 
	{
		char ca = board[row][col];
		board[row][col] = 'X';
		if (backtracking(n, board, row, col + 1) ||
			backtracking(n, board, row, col - 1) ||
			backtracking(n, board, row + 1, col) || 
			backtracking(n, board, row - 1, col)) 
		{
			return (1);
		}
		board[row][col] = ca;
		return (0);
	}
}

int main(void)
{
	char board[3][3] = {
		{'S', '.', '#'},
		{'.', '#', '.'},
		{'.', '.', 'E'}
	};
	int res = backtracking(3, board, 0, 0);
	print_board(3, board);
	return (0);
}
