/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:06:07 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 11:07:11 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat(void): AAnimal() {
	std::cout << "Default Constructor Cat" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src): AAnimal() {
	std::cout << "Copy Constructor Cat" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &rhs){
	std::cout << "Assignment operator Cat" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Cat::~Cat(void){
	std::cout << "Destructor Cat" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const {
	std::cout << "Cat: Miaaouuuu" << std::endl;
}

