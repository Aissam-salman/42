/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:26:44 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:37:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print_upper(int ac, char **av)
{
	int i = 1;

	while (i < ac)
	{
		int y = 0;
		while (av[i][y])
		{
			if (av[i][y] >= 'a' && av[i][y] <= 'z')
				av[i][y] -= 32;
			std::cout << av[i][y];
			y++;
		}
		i++;
	}
	std::cout << "" << std::endl;
}

int main(int ac, char **av) {
	if (ac > 1)
		print_upper(ac, av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
