/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:38:22 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:38:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
		return (print_params(), EXIT_FAILURE);
	if (!is_valid_params(ac, av))
		return (print_params(), EXIT_FAILURE);
	table = malloc(sizeof(t_table));
	if (!table)
		return (EXIT_FAILURE);
	if (init(table, av))
		return (EXIT_FAILURE);
	if (run(table))
	{
		free_all(table);
		return (EXIT_FAILURE);
	}
	free_all(table);
	return (EXIT_SUCCESS);
}
