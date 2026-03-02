/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:14:55 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:39:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	get_current_time(size_t *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (-1);
	}
	*time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (0);
}

size_t	get_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

size_t	get_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

size_t	ft_atol(char *str)
{
	int		i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		nb = nb * 10 + (str[i++] - '0');
	return (nb);
}
