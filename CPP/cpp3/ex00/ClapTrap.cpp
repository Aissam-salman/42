/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:19:21 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/15 15:52:26 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << name << " constructor\n";
}

ClapTrap::ClapTrap(ClapTrap const &src) { *this = src; }

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
  if (this != &rhs) {
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();
  }
  return *this;
}

ClapTrap::~ClapTrap() { std::cout << this->getName() << " destructor\n"; }

std::string ClapTrap::getName(void) const { return (this->_name); }

int ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

int ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

int ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }

void ClapTrap::attack(std::string const &target) {
  if (this->getEnergyPoints() == 0)
    return;
  this->_energyPoints--;
  std::cout << this->getName() << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() == 0)
    return;
  if ((int)amount > this->getHitPoints())
    this->_hitPoints = 0;
  else
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->getEnergyPoints() == 0)
    return;
  this->_energyPoints--;
  this->_hitPoints += amount;
}
