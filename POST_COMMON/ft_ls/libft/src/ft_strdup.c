/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:10:19 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string
 * s. Memory for the new string is obtained with malloc(3), and can be freed
 * with free(3).
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string. It returns NULL if insufficient
 * memory was available.
 */

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}
