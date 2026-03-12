#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void solve(char *base, int start, int end)
{
	int i;

	if (start == end)
		printf("%s\n", base);
	else
	{
		for (i = start; i <= end; i++) {
			swap(base + start, base + i);
			solve(base, start + 1, end);
			swap(base + start, base + i);
		}
	}
}

int main(int ac, char **av)
{
	int len;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]) - 1;
	solve(av[1], 0, len);
	return (0);
}
