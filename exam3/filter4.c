#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strncmp(char *s1, char *s2, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	char buf[4096];
	int rb;
	int len;
	int i;

	if (ac != 2) return (1);
	len = ft_strlen(av[1]);
	rb = read(STDIN_FILENO, buf, sizeof(buf) - 1);
	if (rb <= 0)
		return (1);
	buf[rb] = '\0';
	i = 0;
	while (buf[i])
	{
		if (ft_strncmp(&buf[i], av[1], len) == 0)
		{
			for (int j = 0; j < len; j++) {
				write(1, "*", 1);
			}
			i += len;
		}
		else
			write(1, &buf[i++], 1);
	}
	return (0);
}
