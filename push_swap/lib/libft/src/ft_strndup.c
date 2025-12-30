/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:40:03 by salman            #+#    #+#             */
/*   Updated: 2025/12/30 11:42:05 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (*s && i < len)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}