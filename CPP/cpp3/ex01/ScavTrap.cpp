/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:49:44 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/15 18:20:25 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
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

void ClapTrap::attack(std::string const &target) {
  if (this->getEnergyPoints() == 0)
    return;
  this->_energyPoints--;
  std::cout << "SCAVTRAP: " <<this->getName() << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}
