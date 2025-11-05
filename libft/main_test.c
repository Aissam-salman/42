/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:01:55 by alamjada          #+#    #+#             */
/*   Updated: 2025/11/05 14:12:34 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		printf("Need params bro");
		return (0);
	}

	int my = ft_isalpha(av[1][0]);
	printf("ft_isalpha my = %d\n", my);

	int my2 = ft_isalpha(av[1][0]);
	printf("ft_isalpha my = %d\n", my2);
	return (0);
}
