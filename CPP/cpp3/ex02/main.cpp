/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:40:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 16:47:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

	ScavTrap child = ScavTrap("tim");
	std::cout << "CHILD CONSTRUCTOR BASE" << std::endl;
	std::cout << "Name: " << child.getName() << std::endl;
	std::cout << "hitPoints: " << child.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << child.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << child.getAttackDamage() << std::endl;
	child.attack("tt");
	std::cout << "EnergyPoints: " << child.getEnergyPoints() << std::endl;
	child.takeDamage(100);
	std::cout << "hitPoints: " << child.getHitPoints() << std::endl;
	child.beRepaired(42);
	std::cout << "hitPoints: " << child.getHitPoints() << std::endl;

	FragTrap childfrag = FragTrap("lilou");
	std::cout << "CHILD CONSTRUCTOR BASE" << std::endl;
	std::cout << "Name: " << childfrag.getName() << std::endl;
	std::cout << "hitPoints: " << childfrag.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << childfrag.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << childfrag.getAttackDamage() << std::endl;
	childfrag.attack("toro");
	std::cout << "EnergyPoints: " << childfrag.getEnergyPoints() << std::endl;
	childfrag.takeDamage(100);
	std::cout << "hitPoints: " << childfrag.getHitPoints() << std::endl;
	childfrag.beRepaired(42);
	std::cout << "hitPoints: " << childfrag.getHitPoints() << std::endl;
	return (0);
}
