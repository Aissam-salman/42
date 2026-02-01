/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:51:55 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/29 14:53:26 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SYMBOL "0123456789abcdef"

void bin_naruto(int index, int digits, char *value, int base)
{
	if (index == digits)
		printf("%s\n", value);
	else
	{
		for (int i = 0; i < base; i++)
		{
			value[index] = SYMBOL[i];
			bin_naruto(index + 1, digits, value, base);
		}
	}
}

void  que(int digits)
{
	char *val;
	int i;

	val = calloc(digits + 1, sizeof(*val));
	if (!val)
	{
		perror("Calloc");
		return;
	}
	i = 0;
	while (i < digits)
		val[i++] = '0';
	bin_naruto(0, digits, val, 10);
	free(val);
}


int main(void)
{
	binary_four(10);
	return (0);
}


