/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:29:59 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/18 12:30:46 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/includes/libft.h"

static int	ft_isspace(unsigned char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi_safe(const char *nptr, int *res)
{
	long long	nbr;
	int			sign;

	if (!nptr)
		return (-1);
	while (ft_isspace((unsigned char)*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nbr = 0;
	while (ft_isdigit((unsigned char)*nptr))
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	if (nbr * sign < -2147483648 || nbr * sign > 2147483647)
		return (0);
	*res = (int)nbr  * sign;
	return (1);
}
