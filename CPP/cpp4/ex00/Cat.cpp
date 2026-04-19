/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:06:07 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:31:41 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : Animal() {
  std::cout << "Default Constructor Cat" << std::endl;
  this->_type = "Cat";
}

Cat::Cat(Cat const &src) : Animal() {
  std::cout << "Copy Constructor Cat" << std::endl;
  *this = src;
}

Cat &Cat::operator=(Cat const &rhs) {
  std::cout << "Assignment operator Cat" << std::endl;
  if (this != &rhs)
    this->_type = rhs._type;
  return (*this);
}

Cat::~Cat(void) { std::cout << "Destructor Cat" << std::endl; }

void Cat::makeSound(void) const { std::cout << "Cat: Miaaouuuu" << std::endl; }
