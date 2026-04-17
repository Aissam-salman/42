/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:47:30 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:28:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void): _type("None"){
	std::cout << "Default Constructor Animal" << std::endl;
}

Animal::Animal(Animal const &src){
	std::cout << "Copy Constructor Animal" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs){
	std::cout << "Assignment operator Animal" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Destructor Animal" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Whaaaaa i'm animal" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->_type);
}
