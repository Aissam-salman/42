/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:28:14 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/30 11:32:19 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_len((unsigned char)va_arg(args, int), 1));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_puthexa_p_fd(va_arg(args, unsigned long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_nbr_u((unsigned int)va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa((unsigned long)va_arg(args, unsigned int), 1,
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthexa((unsigned long)va_arg(args, unsigned int), 1,
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_len('%', 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	total_len;

	va_start(args, format);
	total_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_len += ft_handle_conversion(*format, args);
		}
		else
			total_len += ft_putchar_len(*format, 1);
		format++;
	}
	va_end(args);
	return (total_len);
}
