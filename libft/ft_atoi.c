/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:07:50 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 15:11:41 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned long	nbr;
	char			*p;
	int				sign;

	nbr = 0;
	sign = 1;
	if (!nptr)
		return (0);
	p = (char *)nptr;
	while ((*p == ' ') || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign *= -1;
		p++;
	}
	while (ft_isdigit((int)*p))
		nbr = nbr * 10 + (*p++ - '0');
	return ((int) (nbr * sign));
}
