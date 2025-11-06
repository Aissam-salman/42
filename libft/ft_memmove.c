/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:37:25 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/06 11:44:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
typedef unsigned long size_t;

static int ft_isoverlap(void *dest, const void *src, size_t n)
{
  	unsigned char *s;
  	unsigned char *d;

  	s = (unsigned char *) src;
  	d = (unsigned char *) dest;
	return ((d + n > s) || (s + n < d));
}

static void	*ft_reverse_memcpy(void *dest, const void *src, size_t n)
{
  	unsigned char *cpy_src;
  	unsigned char *cpy_dest;
  	size_t count;

  	cpy_dest = (unsigned char *) dest;
  	cpy_src = (unsigned char *) src;
	count = 0;
  	while (cpy_src[n] && n  > 0) {
    	cpy_dest[count] = cpy_src[count];
    	n--;
		count++;
  	}
  	cpy_dest[count] = '\0';
  	return (dest);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == 0 || src == 0)
		return (dest);
	if (ft_isoverlap(dest, src, n))
		ft_reverse_memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
  	return (dest);
}
