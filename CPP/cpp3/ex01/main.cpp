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
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ct = ClapTrap("foo");
	ClapTrap copya = ct;
	ClapTrap cp = ClapTrap(ct);

	std::cout << "PARENT CONSTRUCTOR BASE" << std::endl;
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
	std::cout << "PARENT ASSIGNMENT =" << std::endl;
	std::cout << "hitPoints: " << cp.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << cp.getEnergyPoints() << std::endl;
	std::cout << "PARENT CONSTRUCTOR COPY" << std::endl;
	std::cout << "hitPoints: " << copya.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << copya.getEnergyPoints() << std::endl;

	ClapTrap child = ScavTrap("tim");

	std::cout << "PARENT CONSTRUCTOR BASE" << std::endl;
	std::cout << "Name: " << child.getName() << std::endl;
	std::cout << "hitPoints: " << child.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << child.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << child.getAttackDamage() << std::endl;

	return (0);
}
