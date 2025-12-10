/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:03:24 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/10 13:28:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}
int	ft_atoi_base(char *nbr, char *base_from)
{
	size_t lenb;
	size_t lenn;
	size_t i;
	int rs;
	int sign;

	lenb = ft_strlen(base_from);
	lenn = ft_strlen(nbr) - 1;
	i = 0;
	rs = 0;
	sign = 1;
	if (nbr[0] == '-')
	{
		i++;
		sign = -1;
		// lenn--;
	}
	while (nbr[i])
	{
		// rs += ft_find_index(nbr[i], base_from) * ft_power(lenb, lenn);
		rs = rs * lenb + ft_find_index(nbr[i], base_from);
		// lenn--;
		i++;
	}
	return (rs * sign);
}
