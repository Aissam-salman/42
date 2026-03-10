#include <unistd.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int main(int ac, char **av)
{
	char buffer[4096];
	char c;
	int i;
	int len;

	if (ac != 2 || !av[1])
		return (1);
	i = 0;
	while (read(0, &c, 1) != 0)
		buffer[i++] = c;
	buffer[i] = 0;

	i = 0;
	len = ft_strlen(av[1]);
	while (buffer[i])
	{
		if (ft_strncmp(&buffer[i], av[1], len) == 0)
		{
			for(int j = 0; j < len; j++)
				write(1, "*", 1);
			i += len;
		}
		else
			write(1, &buffer[i++], 1);
	}
	return (0);
}
