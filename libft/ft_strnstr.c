/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:21:09 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/08 18:57:41 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 
       haystack
	   The string to be searched

       needle
	   The string to search for

       n
	   the maximum number of characters to search
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*h;
	char	*ne;
	size_t	i;
	size_t	j;

	if (needle == 0)
		return ((char *) haystack);
	ne = (char *) needle;
	h = (char *) haystack;
	i = 0;
	while (h[i] && i < n)
	{
		j = 0;
		while (ne[j] == h[i + j])
			j++;
		if (j  == (size_t) ft_strlen(ne))
			return (h + i);
		i++;
	}
	return (0);
}
