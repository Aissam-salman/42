/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:27:30 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/19 08:42:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_itoa_u(unsigned int nb);
int		ft_puthexa(unsigned long p, int fd, char *base);
int		ft_puthexa_p_fd(unsigned long p, int fd);
int		ft_print_str(char *str);
int		ft_print_nbr(int nb);
int		ft_print_nbr_u(unsigned int nb);
int		ft_putchar_len(char c, int fd);

#endif
