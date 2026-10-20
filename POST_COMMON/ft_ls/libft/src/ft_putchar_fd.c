/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:15:43 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/08 16:24:25 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
