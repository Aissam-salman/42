/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 21:53:50 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/10 18:25:08 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>

// avance i tant qu'il y a des espaces
static int	skip(char *buf, int i)
{
	while (buf[i] && isspace(buf[i]))
		i++;
	return (i);
}

// lit un entier depuis buf[i], stocke dans *n, retourne le nouvel i
static int	read_int(char *buf, int i, int *n)
{
	int	sign;

	sign = (buf[i] == '-') ? -1 : 1;
	if (buf[i] == '-' || buf[i] == '+')
		i++;
	if (!isdigit(buf[i]))
		return (-1);
	*n = 0;
	while (isdigit(buf[i]))
		*n = *n * 10 + (buf[i++] - '0');
	*n *= sign;
	return (i);
}

// lit un mot depuis buf[i], stocke dans dest, retourne le nouvel i
static int	read_str(char *buf, int i, char *dest)
{
	int	j;

	j = 0;
	while (buf[i] && !isspace(buf[i]))
		dest[j++] = buf[i++];
	dest[j] = '\0';
	return (i);
}

// gere un specifier % : recupere le pointeur via va_arg et ecrit dedans
static int	convert(char spec, char *buf, int i, va_list args)
{
	if (spec == 'd' || spec == 'i')
		return (read_int(buf, skip(buf, i), va_arg(args, int *)));
	if (spec == 's')
		return (read_str(buf, skip(buf, i), va_arg(args, char *)));
	if (spec == 'c')
	{
		if (!buf[i])
			return (-1);
		*va_arg(args, char *) = buf[i];  // %c ne skippe PAS les espaces
		return (i + 1);
	}
	return (i);
}

int	ft_scanf(const char *fmt, ...)
{
	va_list	args;
	char	buf[4096];
	int		n;
	int		i;
	int		count;

	n = read(0, buf, sizeof(buf) - 1);
	if (n <= 0)
		return (-1);
	buf[n] = '\0';
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
				break ;
			count++;
		}
		else if (isspace(*fmt))
			i = skip(buf, i);
		else
		{
			if (buf[i++] != *fmt)
				break ;
		}
		fmt++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int main(void)
{
	int		n;
	char	s[100];

	int res = ft_scanf("%d %s", &n, s);
	printf("n=%d s=%s res=%d\n", n, s, res);
	return (0);
}
