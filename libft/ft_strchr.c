/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:28:14 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/08 13:18:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char *cpy_s;

	cpy_s = (unsigned char *) s;
	while (*cpy_s != '\0')
	{		
		if (*cpy_s == c)
			return ((char *) cpy_s);
		cpy_s++;
	}
	if (c == '\0')
		return ((char *) cpy_s);
	return (0);
}
