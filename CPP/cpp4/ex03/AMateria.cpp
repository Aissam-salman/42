/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:30:17 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 18:03:01 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void){
	std::cout << "Default Constructor AMateria" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type) {
	std::cout << type << " Constructor AMateria" << std::endl;
}

AMateria::AMateria(AMateria const &src) {
	std::cout << "Copy Constructor AMateria" << std::endl;
	*this = src;
}

AMateria &AMateria::operator=(AMateria const &rhs){
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "use from AMateria " << target.getName() << std::endl;
}
