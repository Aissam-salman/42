/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:18:37 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:39:57 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	only_digit(char *param)
{
	int	i;

	i = 0;
	if (param[i] == '+')
		i++;
	else if (param[i] == '-')
		return (FALSE);
	while (param[i])
	{
		if (!ft_isdigit(param[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_valid_params(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!only_digit(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
