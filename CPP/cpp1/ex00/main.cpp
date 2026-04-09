/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:52:12 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/09 21:20:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "---ZOMBIE---\n\n";

	Zombie *z = Zombie::newZombie("timo");
	Zombie::randomChump("zed");

	delete  z;
	return (0);
}
