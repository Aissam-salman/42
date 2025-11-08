/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:19:48 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/08 13:30:43 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
	unsigned char *cpy_s;
	unsigned char	*last_oc;

	cpy_s = (unsigned char *) s;
	last_oc = 0;
	while (*cpy_s != '\0')
	{		
		if (*cpy_s == c)
			last_oc = cpy_s;
		cpy_s++;
	}
	if (last_oc != 0)
			return ((char *) last_oc);
	if (c == '\0')
		return ((char *) cpy_s);
	return (0);
}
