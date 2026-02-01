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

void bin_ok(int digits, char *value)
{
	
	while (1)
	{
		printf("%s\n", value);
		int idx;

		for (idx = digits - 1; idx >= 0; --idx)
		{
			if (value[idx] == '0')
			{
				value[idx]++;
				break;
			}
			value[idx] = '0';
		}
		if (idx < 0)
			break;
	}
}

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
			bin_naruto(index + 1, digits, value, 10);
		}
	}
}

void  binary_four(int digits)
{
	char *val;
	int i ;

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


