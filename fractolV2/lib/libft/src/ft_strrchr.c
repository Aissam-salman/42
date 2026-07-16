/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:19:48 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:29:53 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Locates the last occurrence of c (converted to a char) in the string
 * pointed to by s. The terminating null character is considered to be part of
 * the string; therefore if c is '\\0', the functions locate the terminating
 * '\\0'.
 *
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the located character, or NULL if the character does
 * not appear in the string.
 */

char	*ft_strrchr(const char *s, int c)
{
	char			*last_oc;
	unsigned char	ch;

	last_oc = NULL;
	ch = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
			last_oc = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (last_oc);
}
