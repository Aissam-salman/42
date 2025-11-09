/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:51:13 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/09 15:13:17 by salman           ###   ########.fr       */
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	 size_t	 s_len;
	 size_t	 max_len;
	 char	 *out;

	 if (!s)
	 	return (NULL);
	 s_len = ft_strlen(s);
	 if (start >= s_len)
	 	return (ft_strdup(""));
	 max_len = s_len - start;
	 if (len > max_len)
	 	len = max_len;
	 out = (char *)malloc(len + 1);
	 if (!out)
	 	return (NULL);
	 for (size_t i = 0; i < len; i++)
	 	out[i] = s[start + i];
	 out[len] = '\0';
	 return (out);
}
