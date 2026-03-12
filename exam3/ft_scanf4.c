#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int skip(char *buf, int i)
{
	while (buf[i] && isspace(buf[i]))
		i++;
	return (i);
}

int read_str(char *buf, int i, char *dest)
{
	int j = 0;
	while (buf[i] && !isspace(buf[i]))
		dest[j++] = buf[i++];
	dest[j] = '\n';
	return (i);
}

int read_int(char *buf, int i, int *nbr)
{
	int sign;

	sign = buf[i] == '-' ? -1 : 1;
	if (buf[i] == '-' || buf[i] == '+')
		i++;
	if (!isdigit(buf[i]))
		return (-1);
	*nbr = 0;
	while (isdigit(buf[i]))
		*nbr = *nbr * 10 + (buf[i++] - '0');
	*nbr *= sign;
	return (i);
}

int convert(char spec, char *buf, va_list args, int i)
{
	if (spec == 's')
		return (read_str(buf, skip(buf, i), va_arg(args, char *)));
	else if (spec == 'd')
		return (read_int(buf, skip(buf, i), va_arg(args, int *)));
	else if (spec == 'c')
	{
		if (!buf[i])
			return (-1);
		*va_arg(args, char *) = buf[i];
		return (i + 1);
	}
	return (i);
}

int ft_scanf(const char *fmt, ...)
{
	va_list args;
	int i;
	int count;
	char buf[4096];
	int rb;

	rb  = read(STDIN_FILENO, buf, sizeof(buf) - 1);
	if (rb <= 0)
		return (-1);
	buf[rb] = '\0';
	i = 0;
	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			i = convert(*fmt, buf, args, i);
			if (i < 0)
				break;
			count++;
		}
		else if (isspace(*fmt))
			i = skip(buf, i);
		else
			if (buf[i++] != *fmt)
				break;
		fmt++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	char str[100];
	int n;
	int res;

	res = ft_scanf("%d %s", &n, str);
	printf("n= %d, str= %s, res= %d", n, str, res);
	return (0);
}
