/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:19:21 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/15 18:19:08 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
  std::cout << name << " constructor Parent\n";
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

ClapTrap::~ClapTrap() {
  std::cout << this->getName() << " destructor Parent\n";
}

std::string ClapTrap::getName(void) const { return (this->_name); }

int ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

int ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

int ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }

void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(int hit) { this->_hitPoints = hit; }

void ClapTrap::setEnergyPoints(int energy) { this->_energyPoints = energy; }

void ClapTrap::setAttackDamage(int damage) { this->_attackDamage = damage; }

void ClapTrap::attack(std::string const &target) {
  if (this->getEnergyPoints() == 0)
    return;
  this->_energyPoints--;
  std::cout << "CLAPTRAP: " << this->getName() << " attacks " << target << ", causing "
            << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->getHitPoints() == 0)
    return;
  if ((int)amount > this->getHitPoints())
    this->_hitPoints = 0;
  else
    this->_hitPoints -= amount;
	std::cout << "TAKE DAMAGE: " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->getEnergyPoints() == 0)
    return;
  this->_energyPoints--;
  this->_hitPoints += amount;
	std::cout << "BE REPAIRED: " << amount << std::endl;
}
