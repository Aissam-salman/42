/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:26:50 by alamjada          #+#    #+#             */
/*   Updated: 2026/02/05 11:32:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void find_solutions(int row, int n, char board[n][n])
{
	if (row == n)
	{
		print_board(n, board);
		exit(EXIT_SUCCESS);
	}
	for(int col = 0; col < n; ++col)
	{
		if (is_safe(n, row, col, board) == 1)
		{
			board[row][col] = 'Q';
			find_solutions(row + 1,n, board);
			board[row][col] = '0';
		}
	}
}

void queen(int n)
{
	char chessboard[n][n];

	find_solutions(0, n, chessboard);
}

int main()
{
	queen(4);
	return EXIT_SUCCESS;
}
