/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:28:14 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/18 18:29:00 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isset(char c, const char *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++; }
	return (0);
}

static size_t count_nb_formater(const char *format, const char prefix, const char *set)
{

	size_t	i;
	size_t nb_formater;

	i = 0;
	nb_formater = 0;
	while (format[i])
	{
		if (format[i] == prefix && ft_isset(format[i + 1], set))
			nb_formater++;
		i++;
	}
	return (nb_formater);
}

int ft_puthexa_p_fd(unsigned long p, int fd)
{
	int len;
	size_t i;
	const char *hexa_digits;
	char buffer[20];

	if (!p)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	hexa_digits = "0123456789abcdef";
	ft_putstr_fd("0x", fd);
	len = 0;
	i = 0;
	while (p > 0)
	{
		buffer[i] = hexa_digits[p % 16];
		p = p / 16;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar_fd(buffer[i], fd);
	return (len + 2);
}

int ft_print_nbr(int nb)
{
	char *res;

	res = ft_itoa(nb);
	ft_putstr_fd(res, 1);
	return (ft_strlen(res));

}

int ft_print_nbr_u(unsigned int nb)
{
	char *res;

	res = ft_itoa_u(nb);
	ft_putstr_fd(res, 1);
	return (ft_strlen(res));
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t	total_len;

	if (count_nb_formater(format, '%', "cspdiuxX%") == 0)
	{
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen(format));
	}
	va_start(args, format);
	total_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ft_putchar_fd((unsigned char)va_arg(args, int), 1);
				total_len++;
			}
			else if (*format == 's')
			{
				char *val = va_arg(args, char *);
				if (!val)
				{
					ft_putstr_fd("(null)", 1);
					total_len += 6;
				}
				else 
				{
					ft_putstr_fd(val, 1);
					total_len += ft_strlen(val);
				}
			}
			else if (*format == 'p')
				total_len += ft_puthexa_p_fd(va_arg(args, unsigned long), 1);
			else if (*format == 'd' || *format == 'i')
				total_len += ft_print_nbr(va_arg(args, int));
			else if (*format == 'u')
				total_len += ft_print_nbr_u((unsigned int)va_arg(args, unsigned int));
		}
		else
		{
			ft_putchar_fd(*format, 1);
			total_len++;
		}
		format++;
	}
	return (total_len);
}
