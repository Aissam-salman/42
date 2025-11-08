/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:51:13 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/08 21:02:22 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* Allocates memory (using malloc(3)) and returns a
substring from the string ’s’.
The substring starts at index ’start’ and has a
maximum length of ’len’

Parameters 
s: The original string from which to create the substring.
start: The starting index of the substring within ’s’.
len: The maximum length of the substring.

Return Value The substring.
NULL if the allocation fails.

*/
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	// ft_substr("Bonjour comment ca va?", 5, 8); => "ur comme"
	
	// len the s
	// si start not in s 
	// if start + len not event greath than len_s
	// malloc char *
	// cpy the s (start) to len
	// return 
}
