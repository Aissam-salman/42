/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:31:47 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/30 11:31:46 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	find_nblen(unsigned long n)
{
	size_t			count;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*fill_nbr(char *out, unsigned long n, size_t len)
{
	unsigned long	nbr;
	size_t			i;

	nbr = (unsigned long)n;
	i = 0;
	if (n == 0)
	{
		out[0] = '0';
		out[1] = '\0';
		return (out);
	}
	while (nbr > 0)
	{
		out[len - 1 - i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	out[len] = '\0';
	return (out);
}

char	*ft_itoa_u(unsigned int n)
{
	size_t	len_nb;
	char	*out;

	len_nb = find_nblen(n);
	out = malloc(len_nb + 1);
	if (!out)
		return (NULL);
	out = fill_nbr(out, n, len_nb);
	return (out);
}
