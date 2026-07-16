/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:19:48 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/14 16:59:18 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
