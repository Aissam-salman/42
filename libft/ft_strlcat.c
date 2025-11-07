/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:35:23 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/07 18:54:22 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Elle sert à ajouter une chaîne (src) à la fin d’une autre (dst)
 * sans dépasser une taille maximale (size).
 */
size_t static ft_strnlen(char *dst, size_t size_max)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < size_max)
		i++;
	return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t size) {
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = (size_t) ft_strlen(src);
	len_dst = (size_t) ft_strnlen(dst, size);
	
	if (size == 0)
		return (len_src);
	//size == 0 → retour = len_src
	if (len_dst >= size)
		return (size + len_src);
	else
	{
		//cpy src > dst + len_dst -- jusqu'a size - 1
		i = 0;
		while (len_dst + i < size - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		if (size > 0)
			dst[len_dst + i] = '\0';
	}
	return (len_dst + len_src);
}
