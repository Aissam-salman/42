/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:07:50 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/16 13:51:24 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(unsigned char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	unsigned long	nbr;
	int				sign;

	if (!nptr)
		return (0);
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
	return ((int)(nbr * sign));
}
