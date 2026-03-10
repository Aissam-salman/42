#include <stdio.h>

void solve(char *src, int i, int nopen, int nclose, int score)
{
	char tmp;

	if (score < 0 || nopen < 0 || nclose < 0)
		return ;
	if (src[i] == '\0')
	{
		if (score == 0 && nopen == 0 && nclose == 0)
			puts(src);
		return ;
	}
	tmp = src[i];
	if (src[i] == '(')
		solve(src, i + 1, nopen, nclose, score + 1);
	else if (src[i] == ')')
		solve(src, i + 1, nopen, nclose, score - 1);
	else if (src[i] != '(' && src[i] != ')')
		solve(src, i + 1, nopen, nclose, score);

	if (src[i] == '(' && nopen > 0)
	{
		src[i] = ' ';
		solve(src, i + 1, nopen - 1, nclose, score);
		src[i] = tmp;
	}
	else if (src[i] == ')' && nclose > 0)
	{
		src[i] = ' ';
		solve(src, i + 1, nopen, nclose - 1, score);
		src[i] = tmp;
	}
}

void prepa(char *source, int *score, int *nbopen, int *nbclose)
{
	int i;

	i = 0;
	while (source[i])
	{
		if (source[i] == '(')
			(*score)++;
		else if (source[i] == ')' && *score == 0)
			(*nbclose)++;
		else if (source[i] == ')')
			(*score)--;
		i++;
	}
	if (*score > 0)
		*nbopen = *score;
}

int main(int ac, char **av)
{
	int score;
	int nbclose;
	int nbopen;

	if (ac != 2)
		return (1);
	else if (!av[1])
		return (1);
	prepa(av[1], &score, &nbopen, &nbclose);
	solve(av[1], 0, nbopen, nbclose, 0);
	return (0);
}
