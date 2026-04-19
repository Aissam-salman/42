/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:23:02 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 18:07:42 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
  std::cout << "Default Constructor Ice" << std::endl;
  this->_type = "ice";
}

Ice::Ice(std::string const name) : AMateria(name) {
  std::cout << name << " Constructor Ice" << std::endl;
  this->_type = "ice";
}

Ice::Ice(Ice const &src) : AMateria(src._name) {
  std::cout << "Copy Constructor Ice" << std::endl;
  *this = src;
}

Ice &Ice::operator=(Ice const &rhs) {
  std::cout << "Assignment operator Ice" << std::endl;
  if (this != &rhs)
    this->_name = rhs._name;
  return (*this);
}

Ice::~Ice(void) { std::cout << "Destructor Ice" << std::endl; }

AMateria *Ice::clone() const { return (new Ice(this->_name)); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
