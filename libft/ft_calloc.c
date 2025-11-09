/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:03:41 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/09 15:13:03 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	 size_t	 total;
	 unsigned char *ptr;

	 if (nmemb == 0 || size == 0)
	 	return (malloc(1)); /* Return distinct non-null minimal allocation like some libc implementations */
	 if (nmemb > SIZE_MAX / size)
	 	return (NULL);
	 total = nmemb * size;
	 ptr = (unsigned char *)malloc(total);
	 if (!ptr)
	 	return (NULL);
	 for (size_t i = 0; i < total; i++)
	 	ptr[i] = 0;
	 return (ptr);
}
