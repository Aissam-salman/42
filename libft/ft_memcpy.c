/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:34:32 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/06 11:17:40 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long size_t;

void *ft_memcpy(void *dest, const void *src, size_t n) {
  	size_t len_src;
  	char *cpy_src;
  	char *cpy_dest;
  	size_t count;

	if (dest == 0 || src == 0)
		return (dest);
  	cpy_dest = dest;
  	cpy_src = (char *) src;
  	count = 0;
  	while (cpy_src[count])
    	count++;
  	len_src = (size_t)count;
  	count = 0;
  	while (cpy_src[count] && count < n) {
    	cpy_dest[count] = cpy_src[count];
    	count++;
  	}
  	cpy_dest[count] = '\0';
  	return (dest);
}
