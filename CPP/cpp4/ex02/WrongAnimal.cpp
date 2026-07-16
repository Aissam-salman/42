/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:27:29 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:34:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void) : _type("WNone") {
  std::cout << "Default Constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
  std::cout << "Copy Constructor WrongAnimal" << std::endl;
  *this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
  std::cout << "Assignment operator WrongAnimal" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return (*this);
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "Destructor WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "Wronggghaaaaa i'm WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const { return (this->_type); }
