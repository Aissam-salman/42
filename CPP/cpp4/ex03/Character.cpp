/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:30:26 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 18:24:02 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

Character::Character(void) {
  std::cout << "Default Constructor Character" << std::endl;
  this->_garbage = new AMateria *[200];
}

Character::Character(std::string const name) : _name(name), _idx(0), _g_idx(0) {
  std::cout << name << " Constructor Character" << std::endl;
  this->_garbage = new AMateria *[200];
}

Character::Character(Character const &src) {
  std::cout << "Copy Constructor Character" << std::endl;
  this->_name = src._name;
  this->_idx = src._idx;
  for (int i = 0; i < 4; i++) {
		this->_materials[i] = NULL;
		if (src._materials[i])
			this->_materials[i] = src._materials[i]->clone();
  }
}

Character &Character::operator=(Character const &rhs) {
  if (this != &rhs) {
		this->cleanGarbage();
		for (int i = 0; i < 4; i++) {
			if (this->_materials[i])
			{
				delete this->_materials[i];
				this->_materials[i] = NULL;
			}
		}
    this->_name = rhs._name;
    this->_idx = rhs._idx;
    for (int i = 0; i < 4; i++) {
			this->_materials[i] = NULL;
			if (rhs._materials[i])
				this->_materials[i] = rhs._materials[i]->clone();
    }
  }
  return (*this);
}

Character::~Character(void) {
  for (int i = 0; i < 4; i++) {
    delete this->_materials[i];
  }
  cleanGarbage();
  delete[] this->_garbage;
  std::cout << "Destructor Character" << std::endl;
}

std::string const &Character::getName() const { return (this->_name); }

void Character::equip(AMateria &m) {
  for (int i = 0; i < 4; i++) {
    if (this->_materials[i] && this->_materials[i]->getType() == m.getType())
      return;
  }
  if (this->_idx == 3)
    return;
  this->_materials[this->_idx] = m.clone();
  this->_idx++;
}

void Character::cleanGarbage(void) {
  for (int i = 0; i < 200; i++) {
    if (this->_garbage[i])
      delete this->_garbage[i];
  }
  this->_g_idx = 0;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3)
    return;
  if (this->_materials[idx]) {
    AMateria *tmp = this->_materials[idx];
    if (this->_g_idx == 199)
      cleanGarbage();
    this->_garbage[this->_g_idx++] = tmp;
    delete tmp;
    this->_materials[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > 3)
    return;
  if (this->_materials[idx])
    this->_materials[idx]->use(target);
}
