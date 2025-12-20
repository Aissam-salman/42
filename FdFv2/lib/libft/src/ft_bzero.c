/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:53:53 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 15:46:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Writes n zeroed bytes to the string s.
 *
 * @param s The string to write to.
 * @param n The number of bytes to write.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_cpy;

	p_cpy = (unsigned char *) s;
	while (n > 0)
	{
		*p_cpy = '\0';
		p_cpy++;
		n--;
	}
}
