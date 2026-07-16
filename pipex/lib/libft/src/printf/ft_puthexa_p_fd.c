/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_p_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:23:42 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/30 11:32:37 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_puthexa_p_fd(unsigned long p, int fd)
{
	int		len;
	size_t	i;
	char	*hexa_digits;
	char	buffer[20];

	if (!p)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	hexa_digits = "0123456789abcdef";
	ft_putstr_fd("0x", fd);
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
	return (len + 2);
}
