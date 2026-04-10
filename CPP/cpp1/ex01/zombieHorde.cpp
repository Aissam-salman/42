/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:19:56 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 12:30:36 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie *zbs = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zbs[i].setName(name);
	}
	return zbs;
}
