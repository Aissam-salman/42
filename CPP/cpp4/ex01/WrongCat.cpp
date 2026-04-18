/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:30:36 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:37:48 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal() {
	std::cout << "Default Constructor WrongCat" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal() {
	std::cout << "Copy Constructor WrongCat" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs){
	std::cout << "Assignment operator WrongCat" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat(void){
	std::cout << "Destructor WrongCat" << std::endl;
}
