/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:52:55 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 16:47:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
  std::cout << "Default constructor Child Frag" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->setHitPoints(100);
  this->setEnergyPoints(100);
  this->setAttackDamage(30);
  std::cout << name << " constructor Child Frag" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src.getName()) {
  *this = src;
}

FragTrap::~FragTrap(void) {
  std::cout << this->getName() << " destructor Child Trag" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return (*this);
}

void FragTrap::attack(std::string const &target) {
  if (this->getEnergyPoints() == 0)
    return;
  this->setEnergyPoints(this->getEnergyPoints() - 1);
  std::cout << "FRAGTRAP: " << this->getName() << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
}

void highFivesGuys(void) {
  std::cout << " FragTrap call high fives Guys!" << std::endl;
}
