/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:49:49 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:19:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks whether c fits into the ASCII character set.
 *
 * @param c The character to check.
 * @return 1 if c is an ASCII character, 0 otherwise.
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
