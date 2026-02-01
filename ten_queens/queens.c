/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:02:00 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/29 11:37:57 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int is_safe(int n, int row, int col, char board[n][n])
{
	// vertical
	 for(int r = 0; r < row; ++r)
	 {
		 if (board[r][col] == 'Q')
			 return (0);
	 }
	 // diag left
	 for(int c = col, r = row; c>= 0 && r>= 0; --c, --r)
	 {
		 if (board[r][c] == 'Q')
			 return (0);
	 }
	 // diag left
	 for(int c = col, r = row; c <= n && r >= 0; ++c, --r)
	 {
		 if (board[r][c] == 'Q')
			 return (0);
	 }
	 return (1);
}

void backtracking(int row, int n, char board[n][n])
{
	if (row == n)
	{
		print_board(n, board);
		exit(EXIT_SUCCESS);
	}
	else
	{
		for (int col = 0; col < n; ++col)
		{
			if (is_safe(n, row, col, board) == 1)
			{
				board[row][col] = 'Q';
				backtracking(row + 1, n, board);
				board[row][col] = 0;
			}
		}
	}
}

int **queen(int n)
{
	char chessboard[n][n];

	backtracking(0, n, chessboard);
	return 0;
}

int main()
{
	queen(10);
	return (0);
}
