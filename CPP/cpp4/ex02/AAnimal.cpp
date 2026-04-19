/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:47:30 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:40:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal(void) : _type("None") {
  std::cout << "Default Constructor AAnimal" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
  std::cout << "Copy Constructor AAnimal" << std::endl;
  *this = src;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
  std::cout << "Assignment operator AAnimal" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return (*this);
}

AAnimal::~AAnimal(void) { std::cout << "Destructor AAnimal" << std::endl; }

void AAnimal::makeSound(void) const {
  std::cout << "Whaaaaa i'm animal" << std::endl;
}

std::string AAnimal::getType(void) const { return (this->_type); }
