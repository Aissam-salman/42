/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:49:44 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 18:05:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap() {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Default constructor Child Scav" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << name << " constructor Child Scav" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src.getName()) { *this = src; }

ScavTrap::~ScavTrap() {
	std::cout << this->getName() << " destructor Child Scav" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    if (this != &rhs) {
			this->setName(rhs.getName());
			this->setHitPoints(rhs.getHitPoints());
			this->setEnergyPoints(rhs.getEnergyPoints());
			this->setAttackDamage(rhs.getAttackDamage());
    }
    return *this;
}

void ScavTrap::guardGate(void){
		std::cout << " ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  if (this->getEnergyPoints() == 0)
    return;
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "SCAVTRAP: " <<this->getName() << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}
