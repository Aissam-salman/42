/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:40:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/15 15:51:57 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ct = ClapTrap("foo");
	ClapTrap copya = ct;
	ClapTrap cp = ClapTrap(ct);

	std::cout << "Name: " << ct.getName() << std::endl;
	std::cout << "hitPoints: " << ct.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << ct.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << ct.getAttackDamage() << std::endl;
	ct.takeDamage(3);
	ct.attack("bob");
	std::cout << "hitPoints: " << ct.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << ct.getEnergyPoints() << std::endl;
	ct.beRepaired(3);
	std::cout << "hitPoints: " << ct.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << ct.getEnergyPoints() << std::endl;
	std::cout << "cp\n";
	std::cout << "hitPoints: " << cp.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << cp.getEnergyPoints() << std::endl;
	std::cout << "copya\n";
	std::cout << "hitPoints: " << copya.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << copya.getEnergyPoints() << std::endl;
	return (0);
}
