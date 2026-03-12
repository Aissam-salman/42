#include <stdio.h>

void solve(char *txt, int nopen, int nclose, int i, int score)
{
	char tmp;

	if (score < 0 || nopen < 0 || nclose < 0)
		return ;
	if (txt[i] == '\0')
	{
		if (score == 0 && nopen == 0 && nclose == 0)
			puts(txt);
		return ;
	}
	tmp = txt[i];
	if (txt[i] == '(')
		solve(txt, nopen, nclose, i + 1, score + 1);
	else if (txt[i] == ')')
		solve(txt, nopen, nclose, i + 1, score - 1);
	else if (txt[i] != '(' && txt[i] != ')')
		solve(txt, nopen, nclose, i + 1, score);

	if (txt[i] == '(' && nopen > 0)
	{
		txt[i] = ' ';
		solve(txt, nopen - 1, nclose, i + 1, score);
		txt[i] = tmp;
	}
	else if (txt[i] == ')' && nclose > 0)
	{
		txt[i] = ' ';
		solve(txt, nopen, nclose - 1, i + 1, score);
		txt[i] = tmp;
	}
}

void prepa(char *txt, int *nbopen, int *nbclose)
{
	int score = 0;
	int i = 0;
	while (txt[i])
	{
		if (txt[i] == '(')
			score++;
		else if (txt[i] == ')' && score == 0)
			(*nbclose)++;
		else if (txt[i] == ')')
			score--;
		i++;
	}
	if (score > 0)
		(*nbopen) = score;
}

int main(int ac, char **av)
{
	int nbopen, nbclose;

	if (ac != 2)
		return (1);
	prepa(av[1], &nbopen, &nbclose);
	solve(av[1], nbopen, nbclose, 0, 0);
	return (1);
}
