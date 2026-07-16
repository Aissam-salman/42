#include <stdio.h>

void solve(char *txt, int no, int nc, int score, int i)
{
	char tmp;

	if (no < 0 || nc < 0 || score < 0)
		return ;
	if (txt[i] == '\0')
	{
		if (no == 0 && nc == 0 && score == 0)
			puts(txt);
		return;
	}
	tmp = txt[i];
	if (txt[i] == '(')
		solve(txt, no, nc, score + 1, i + 1);
	else if (txt[i] == ')')
		solve(txt, no, nc, score - 1, i + 1);
	else if (txt[i] != '(' && txt[i] != ')')
		solve(txt, no, nc, score, i + 1);

	if (txt[i] == '(' && no > 0)
	{
		txt[i] = ' ';
		solve(txt, no - 1, nc, score, i + 1);
		txt[i] = tmp;
	}
	else if (txt[i] == ')' && nc > 0)
	{
		txt[i] = ' ';
		solve(txt, no , nc - 1, score, i + 1);
		txt[i] = tmp;
	}
}

void prepa(char* txt, int *no, int *nc)
{
	int score;
	int i;

	i = 0;
	score = 0;
	while (txt[i])
	{
		if (txt[i] == '(')
			score++;
		else if (txt[i] == ')' && score == 0)
			(*nc)++;
		else if (txt[i] == ')')
			score--;
		i++;
	}
	if (score > 0)
		*no = score;
}

int main(int ac, char **av)
{
	int nopen, nclose;

	if (ac != 2)
		return (1);
	prepa(av[1], &nopen, &nclose);
	solve(av[1], nopen, nclose, 0, 0);
	return (0);
}
