/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:00:00 by author            #+#    #+#             */
/*   Updated: 2026/03/17 17:25:36 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// PROGRAM ENTRY POINT
// FLOW: zero the main struct -> parse .cub -> print debug info -> launch game loop.
int	main(int argc, char **argv)
{
	t_cub data;

	ft_bzero(&data, sizeof(t_cub));
	// ft_cub_init(&data);
	ft_parsing(&data, argv, argc);
	ft_cub_print(&data);
	ft_game(&data);
	return (EXIT_SUCCESS);
}
