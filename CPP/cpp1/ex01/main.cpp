/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:18:52 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 12:19:07 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int const N = 10;

	Zombie *zbs = Zombie().zombieHorde(N, "bob");
	for (int i = 0; i < N ; i++) {
		zbs[i].announce();
	}
	return (0);
}
