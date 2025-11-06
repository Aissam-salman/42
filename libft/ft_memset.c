/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:15:56 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/06 09:50:13 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned long size_t;

void *ft_memset(void *s, int c, size_t n){
	size_t i;
	unsigned char *array;
	unsigned char value_replace;

	array = (unsigned char *) s;
	value_replace = (unsigned char) c;

	i = 0;
	while (i < n)
	{
		array[i] = value_replace;
		i++;
	}
	return (s);
}
