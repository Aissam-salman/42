/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:24:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 20:31:41 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "Default Constructor MateriaSource";
	
}
/*
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
*/
MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cout << "Copy Constructor MateriaSource";
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	std::cout << "Assignment operator MateriaSource";
	if (this != &rhs) {
// clean le current avant de deeep copy
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "Destructor MateriaSource";
}

void MateriaSource::learnMateria(AMateria *m){
// 	Copies the Materia passed as a parameter and stores it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique
}

AMateria *MateriaSource::createMateria(std::string const &type){
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.
	return (NULL);
}


