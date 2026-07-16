/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:24:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/19 12:27:45 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _idx(0) {
  std::cout << "Default Constructor MateriaSource" << std::endl;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource &src) {
  std::cout << "Copy Constructor MateriaSource" << std::endl;
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
  this->_idx = src._idx;
  for (int i = 0; i < 4; i++) {
    if (src._inventory[i])
      this->_inventory[i] = src._inventory[i]->clone();
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  std::cout << "Assignment operator MateriaSource" << std::endl;
  if (this != &rhs) {
    // clean le current avant de deeep copy
    for (int i = 0; i < 4; i++) {
      if (this->_inventory[i]) {
        delete this->_inventory[i];
        this->_inventory[i] = NULL;
      }
      if (rhs._inventory[i])
        this->_inventory[i] = rhs._inventory[i]->clone();
    }
    this->_idx = rhs._idx;
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << "Destructor MateriaSource" << std::endl;
  for (int i = 0; i < 4; i++) {
    delete this->_inventory[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (this->_idx == 4)
    return;
  this->_inventory[this->_idx++] = m->clone();
  delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] && this->_inventory[i]->getType() == type)
      return (this->_inventory[i]->clone());
  }
  return (0);
}
