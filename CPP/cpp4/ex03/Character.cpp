/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:30:26 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 18:13:45 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

Character::Character(void){
	std::cout << "Default Constructor Character" << std::endl;
	this->_materials = new AMateria*[4];
}

Character::Character(std::string const name): _name(name) {
	std::cout << name << " Constructor Character" << std::endl;
	this->_materials = new AMateria*[4];
}

Character::Character(Character const &src){
	std::cout << "Copy Constructor Character" << std::endl;
	*this = src;
}

Character &Character::operator=(Character const &rhs){
	if (this != &rhs){
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			this->_materials[i] = rhs._materials[i];
			delete rhs._materials[i];
		}
		delete [] rhs._materials;
	}
	return (*this);
}

Character::~Character(void){
	for (int i = 0; i < 4; i++) {
		this->_materials[i] = this->_materials[i];
		delete this->_materials[i];
	}
	delete [] this->_materials;
	std::cout << "Destructor Character" << std::endl;
}

std::string const &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria &m){}
void Character::unequip(int idx){}
void Character::use(int idx, ICharacter &target){}
