/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:00:24 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 18:04:50 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void): AMateria("ice") {
	std::cout << "Default Constructor Cure" << std::endl;
	this->_type = "ice";
}

Cure::Cure(std::string const name): AMateria(name) {
	std::cout << name << " Constructor Cure" << std::endl;
	this->_type = "ice";
}

Cure::Cure(Cure const &src) {
	std::cout << "Copy Constructor Cure" << std::endl;
	*this = src;
}

Cure &Cure::operator=(Cure const &rhs){
	std::cout << "Assignment operator Cure" << std::endl;
	if (this != &rhs)
		this->_name = rhs._name;
	return (*this);
}

Cure::~Cure(void){
	std::cout << "Destructor Cure" << std::endl;
}

AMateria *Cure::clone() const {
	return (new Cure(this->_name));
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << this->_name << "'s wounds *" std::endl;
}


