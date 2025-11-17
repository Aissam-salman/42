/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:37:57 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/17 17:50:44 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(long nb, size_t base_len)
{
	size_t	nbr_len;

	nbr_len = 0;
	while (nb > 0)
	{
		nb = nb / base_len;
		nbr_len++;
	}
	return (nbr_len);
}

static char *ft_tobase(long nb, size_t base_len, int sign)
{
	size_t i;
	char *nbr;
	size_t nbr_len;

	if (sign == -1)
	{
		nb = -nb;
		nbr_len = ft_nbrlen(nb, base_len) + 1;
	}
	else 
		nbr_len = ft_nbrlen(nb, base_len);
	nbr = malloc(nbr_len + 1);
	if (!nbr)
		return (NULL);
	i = nbr_len - 1;
	nbr[nbr_len] = '\0';
	while (i > 0)
	{
		nbr[i--] = nb % base_len + '0';
		nb = nb / base_len;
	}
	if (sign == -1)
		nbr[0] = '-';
	return (nbr);

}
char *ft_itoa_base(long nb, char *base_to)
{
	size_t	base_len;
	int 	sign;

	sign = 1;
	base_len = ft_strlen(base_to);
	if (nb < 0)
		sign = -1;
	return (ft_tobase(nb, base_len, sign));
}
