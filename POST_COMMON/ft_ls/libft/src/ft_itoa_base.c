/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:09:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/12 11:47:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_lennbr(long nb, int len_base)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= len_base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nb, char *base_to)
{
	int		len_base;
	long	n;
	int		lennb;
	char	*res;

	len_base = ft_strlen(base_to);
	n = nb;
	lennb = ft_lennbr(n, len_base);
	res = malloc(lennb + 1);
	if (!res)
		return (NULL);
	res[lennb] = '\0';
	if (n == 0)
		res[0] = base_to[0];
	if (nb < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[--lennb] = base_to[n % len_base];
		n /= len_base;
	}
	return (res);
}
