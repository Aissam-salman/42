/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:49:00 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 11:47:03 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_nbr_base_from(char *nbr, char *base_from)
{
	size_t	i;

	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_strchr(base_from, nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_base(char *base)
{
	size_t	lenb;
	size_t	i;
	size_t	j;

	if (!base || !*base)
		return (0);
	lenb = ft_strlen(base);
	if (lenb < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (!ft_isprint(base[i]) || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[i] && base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*res;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	if (!check_nbr_base_from(nbr, base_from))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	res = ft_itoa_base(n, base_to);
	return (res);
}
