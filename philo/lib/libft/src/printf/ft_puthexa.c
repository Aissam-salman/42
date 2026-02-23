/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:23:00 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/30 11:32:43 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_puthexa(unsigned long p, int fd, char *base)
{
	int		len;
	size_t	i;
	char	*hexa_digits;
	char	buffer[20];

	if (p == 0)
	{
		ft_putstr_fd("0", fd);
		return (1);
	}
	hexa_digits = base;
	len = 0;
	i = 0;
	while (p > 0)
	{
		buffer[i] = hexa_digits[p % 16];
		p = p / 16;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar_fd(buffer[i], fd);
	return (len);
}
