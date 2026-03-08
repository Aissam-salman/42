/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:21:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/08 20:07:48 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void solve(char *source, int i, int nb_open, int nb_close, int score)
{
	if (score < 0 || nb_open < 0 || nb_close < 0)
		return;
	if (source[i] == '\0')
	{
		if (score == 0 && nb_open == 0 && nb_close == 0)
			puts(source);
		return ;
	}
	char tmp = source[i];
	if (source[i] == '(')
		solve(source, i + 1, nb_open, nb_close, score + 1);
	else if (source[i] == ')' && score > 0)
		solve(source, i + 1, nb_open, nb_close, score - 1);
	else if (source[i] != '(' && source[i] != ')')
		solve(source, i + 1, nb_open, nb_close, score);

	if (source[i] == '(' && nb_open > 0)
	{
		source[i] = ' ';
		solve(source, i + 1, nb_open - 1, nb_close, score);
		source[i] = tmp;
	}
	else if (source[i] == ')' && nb_close > 0)
	{
		source[i] = ' ';
		solve(source, i + 1, nb_open, nb_close - 1, score);
		source[i] = tmp;
	}
}

void prepa(char *source, int *score, int *nb_open, int *nb_close)
{
	int i;

	i = 0;
	while (source[i])
	{
		if (source[i] == '(')
			(*score)++;
		else if (source[i] == ')' && *score == 0)
			(*nb_close)++;
		else if (source[i] == ')')
			(*score)--;
		i++;
	}
	if (*score > 0)
		*nb_open = *score;
}

int main(int argc, char *argv[])
{
	int score = 0;
	int nb_close = 0;
	int nb_open = 0;
	if (argc != 2)
		return (1);
	if (!argv[1])
		return (1);
	prepa(argv[1], &score, &nb_open, &nb_close);
	solve(argv[1], 0, nb_open, nb_close, 0);
	return (0);
}
