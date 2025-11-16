/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:53:53 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/14 22:45:05 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_cpy;

	p_cpy = (unsigned char *) s;
	while (n > 0)
	{
		*p_cpy = '\0';
		p_cpy++;
		n--;
	}
}
