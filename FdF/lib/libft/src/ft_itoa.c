/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:31:47 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:19:38 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Converts an integer to a string.
 *
 * @param n The integer to convert.
 * @return The string representation of the integer.
 */

static size_t	find_nblen(int n)
{
	size_t		count;
	long int	nbr;

	nbr = (long int)n;
	if (nbr == 0)
		return (1);
	count = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*fill_nbr(char *out, int n, size_t len)
{
	long int	nbr;
	size_t		i;

	nbr = (long int)n;
	i = 0;
	if (n == 0)
	{
		out[0] = '0';
		out[1] = '\0';
		return (out);
	}
	if (nbr < 0)
	{
		out[0] = '-';
		nbr = -nbr;
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

char	*ft_itoa(int n)
{
	size_t	len_nb;
	char	*out;

	len_nb = find_nblen(n);
	if (n < 0)
		len_nb++;
	out = malloc(len_nb + 1);
	if (!out)
		return (NULL);
	out = fill_nbr(out, n, len_nb);
	return (out);
}
