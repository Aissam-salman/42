/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:35:23 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/09 15:12:31 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** ft_strlcat
** Concatène src après dst en respectant la taille totale du buffer (size).
** Retourne la longueur que la chaîne finale aurait eue sans troncature.
*/
static size_t	ft_strnlen(const char *dst, size_t size_max)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < size_max)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	 size_t	len_src;
	 size_t	len_dst;
	 size_t	i;

	 len_src = ft_strlen(src);
	 len_dst = ft_strnlen(dst, size);
	 if (size == 0)
	 	return (len_src);
	 if (len_dst >= size)
	 	return (size + len_src);
	 i = 0;
	 while (src[i] && (len_dst + i) < (size - 1))
	 {
	 	dst[len_dst + i] = src[i];
	 	i++;
	 }
	 if (len_dst < size)
	 	dst[len_dst + i] = '\0';
	 return (len_dst + len_src);
}
