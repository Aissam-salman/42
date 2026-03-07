/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:59:12 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/07 18:10:49 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
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

void permutation(char *str, int left, int rigth)
{
	int i;

	if (left == rigth)
		printf("%s\n", str);
	else
	{
		for (i = left; i <= rigth; i++) {
			swap(str + left, str + i);
			permutation(str, left + 1, rigth);

			swap(str + left, str + i);
		}
	}
}

int main(void)
{
	char str[] = "abc";
	permutation(str, 0, ft_strlen(str) - 1);
	return (0);
}
