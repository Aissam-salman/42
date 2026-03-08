#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	char	buf[4096];
	int		len = strlen(av[1]);
	int		i = 0;
	char	c;

	while (read(0, &c, 1) != 0)
		buf[i++] = c;
	buf[i] = 0;

	i = 0;
	while (buf[i])
	{
		if (strncmp(&buf[i], av[1], len) == 0)
		{
			for (int j = 0; j < len; j++)
				write(1, "*", 1);
			i += len;
		}
		else
			write(1, &buf[i++], 1);
	}
	return (0);
}
