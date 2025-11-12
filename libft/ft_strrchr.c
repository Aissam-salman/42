/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:19:48 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/12 16:19:54 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char	*last_oc;
	unsigned char	ch;

	last_oc = NULL;
	ch = (unsigned char) c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
			last_oc = (char *) s;
		s++;
	}
	if (ch == '\0')
		return ((char *) s);
	return (last_oc);
}
