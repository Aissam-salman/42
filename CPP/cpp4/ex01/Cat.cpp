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

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : Animal() {
  std::cout << "Default Constructor Cat" << std::endl;
  this->_type = "Cat";
  this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal() {
  std::cout << "Copy Constructor Cat" << std::endl;
  // *this = src;
  this->_brain = NULL;
  if (src._brain)
    this->_brain = new Brain(*src._brain);
  this->_type = src._type;
}

Cat &Cat::operator=(Cat const &rhs) {
  std::cout << "Assignment operator Cat" << std::endl;
  if (this != &rhs) {
    if (this->_brain) {
      delete this->_brain;
      this->_brain = NULL;
    }
    this->_brain = new Brain(*rhs._brain);
    this->_type = rhs._type;
  }
  return (*this);
}

Cat::~Cat(void) {
  std::cout << "Destructor Cat" << std::endl;
  delete this->_brain;
}

void Cat::makeSound(void) const { std::cout << "Cat: Miaaouuuu" << std::endl; }
