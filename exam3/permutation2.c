#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
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

void permutation(char *str, int start, int end)
{
	int i;

	if (start == end)
		printf("%s\n", str);
	else
	{
		for (i = start; i <= end; i++) {
			swap(str + start, str + i);
			permutation(str, start + 1, end);
			swap(str + start, str + i);
		}
	}
}

int main(int ac, char **av)
{
	int len;

	if (ac != 2 || !av[1])
		return (1);
	len = ft_strlen(av[1]) - 1;
	permutation(av[1], 0, len);
	return (0);
}
