/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:13:32 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 18:08:23 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
      _name(name) {
  this->setHitPoints(100);
  this->setEnergyPoints(50);
  this->setAttackDamage(30);
  std::cout << name << " constructor Diamond\n";
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << this->getName() << " destructor Child Trag" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src.getName()) {
  *this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

void DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
}
