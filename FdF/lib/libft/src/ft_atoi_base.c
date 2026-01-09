/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:03:24 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 11:46:35 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	size_t	lenb;
	size_t	i;
	int		rs;
	int		sign;

	lenb = ft_strlen(base_from);
	i = 0;
	rs = 0;
	sign = 1;
	if (nbr[0] == '-')
	{
		i++;
		sign = -1;
	}
	while (nbr[i])
	{
		rs = rs * lenb + ft_find_index(nbr[i], base_from);
		i++;
	}
	return (rs * sign);
}
