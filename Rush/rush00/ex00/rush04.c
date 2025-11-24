/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:43:19 by alamjada          #+#    #+#             */
/*   Updated: 2025/08/09 12:07:20 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c);

void	ft_print_rows(int x, char first_char, char middle_char)
{
	int	col;

	col = 1;
	while(col <= x)
	{
		if (col == 1 || col == x)
			ft_putchar(first_char);
		else
			ft_putchar(middle_char);
		col++;
	}

}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		int	row;

		row = 1;
		while(row <= y)
		{
				if (row == 1)
					ft_print_rows(x, 'A', 'B');
				else if (row == y)
					ft_print_rows(x, 'C', 'B');
				else 
					ft_print_rows(x, 'B', ' ');
			ft_putchar('\n');
			row++;
		}
	}
}
