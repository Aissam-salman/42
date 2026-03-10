/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:23:01 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/10 18:50:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int skip(char *buf, int i)
{
	while (buf[i] && isspace(buf[i]))
		i++;
	return (i);
}

int read_string(char *buf, int i, char *dest)
{
	int j;

	j = 0;
	while (buf[i] && !isspace(buf[i]))
		dest[j++] = buf[i++];
	dest[j] = '\0';
	return (i);
}

static int convert(char spec, char *buf, int i, va_list args)
{
	if (spec == 's')
		return (read_string(buf, skip(buf, i), va_arg(args, char *)));
	else if (spec == 'd')
		return (read_int(buf, skip(buf, i), va_arg(args, int *)))
}

int	ft_scanf(const char *fmt, ...)
{
	char *buf[5000];
	va_list args;
	int read_bytes;
	int i;
	int count;

	read_bytes = read(0, buf, sizeof(buf) - 1);
	if (read_bytes <= 0)
		return (-1);
	buf[read_bytes] = '\0';

	i = 0;
	count = 0;
	va_start(args, fmt);

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			i = convert(*fmt, buf, i, args);
			if (i < 0)
				break;
			count++;
		}
		else if (isspace(*fmt))
			i = skip(buf, i);
		else 
		{
			if (buf[i++] != *fmt)
				break;

		}
		fmt++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	int res;
	char str[100];
	int n;

	res = ft_scanf("%d %s", &n, str);
	printf("n= %d, str= %s, res= %d", n, str, res);
	return (0);
}
