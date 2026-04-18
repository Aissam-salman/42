/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:14:36 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 11:08:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog(void): Animal() {
	std::cout << "Default Constructor Dog" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src): Animal() {
	std::cout << "Copy Constructor Dog" << std::endl;
	*this = src;
}

Dog& Dog::operator=(Dog const &rhs) {
	std::cout << "Copy Constructor Dog" << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Destructor Dog" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const {
	std::cout << "Dog: WHouuuffff" << std::endl;
}
