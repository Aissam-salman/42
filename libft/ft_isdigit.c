/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:07:07 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:19:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for a digit (0 through 9).
 *
 * @param c The character to check.
 * @return 1 if the character is a digit, 0 otherwise.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
