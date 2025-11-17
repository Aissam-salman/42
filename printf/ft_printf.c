/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:28:14 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/17 20:21:11 by alamjada         ###   ########.fr       */
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

void ft_puthexap_fd(void *p, int fd)
{
	char *out;
	char *hex_digits;
	unsigned char i;
	unsigned long val;
	int reminder;

	out = malloc(17);
	if (!out)
		return ;
	val = (unsigned long)p;
	hex_digits = "0123456789abcdef";
	out[16] = '\0';
	i = 15;
	while (i >= 0)
	{
		reminder = val % 16;
		out[i] = hex_digits[reminder];
		val = val / 16;
		i--;
	}
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(out, fd);
}

int ft_printf(const char *format, ...)
{
	const char *CONVERSION = "cspdiuxX%";
	const char formater_prefix = '%';
	// const char *flags = "-0.# +";
	va_list args;
	size_t	nb_formater;
	size_t total_len;

	nb_formater = count_nb_formater(format, formater_prefix, CONVERSION);
	if (nb_formater == 0)
	{
		ft_putendl_fd("No conversion present", 1);
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen(format));
	}
	va_start(args, format);
	size_t i = 0;
	size_t stop = 1;
	total_len = 0;
	while (*format)
	{
		if (*format == formater_prefix && stop)
		{
			format++;
			if (*format == 'c')
			{
				unsigned char val = va_arg(args, int);
				ft_putchar_fd(val, 1);
				total_len++;
			}
			else if (*format == 's')
			{
				char *val = va_arg(args, char *);
				ft_putstr_fd(val, 1);
				total_len += ft_strlen(val);
			}
			else if (*format == 'p')
			{
				void *val = va_arg(args, void *);
				ft_puthexap_fd(val, 1);
				total_len += 18;
			}
			else if (*format == 'd' || *format == 'i')
			{
				signed int val = va_arg(args,  signed int);
				ft_putnbr_fd(val, 1);
			}
			else if (*format == 'u' )
			{
				unsigned int val = va_arg(args,  unsigned int);
				ft_putnbr_fd(val, 1);
			}
			else if (*format == 'x')
			{
				unsigned int val = va_arg(args,  unsigned int);
				ft_putstr_fd(ft_itoa_base(val, "0123456789abcdef"), 1);
			}
			else if (*format == 'X' )
			{
				unsigned int val = va_arg(args,  unsigned int);
				ft_putstr_fd(ft_itoa_base(val, "0123456789ABCDEF"), 1);
			}
			else
				return (-1);
			i++;
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			total_len++;
			format++;
		}
		if (i == nb_formater)
			stop = 0;
	}
	va_end(args);
    return  (nb_formater);
}
