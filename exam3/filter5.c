#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char buf[4096];
	int rb;
	int len;
	int i;

	if (ac != 2)
		return (1);
	len = strlen(av[1]);
	rb = read(0, buf, sizeof(buf) - 1);
	if (rb <= 0)
		return (1);
	buf[rb] = '\0';
	i = 0;
	while (buf[i])
	{
		if (strncmp(&buf[i], av[1], len) == 0)
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
