/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:57:51 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:19:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for any printable character including space.
 *
 * @param c The character to check.
 * @return 1 if the character is printable, 0 otherwise.
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
