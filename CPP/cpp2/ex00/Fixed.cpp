/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:50:31 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/12 13:04:35 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _rawBits(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src) {
	std::cout <<"Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &rhs){
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw){
	this->_rawBits = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->_rawBits);
}

int const Fixed::_nbFractionalBits = 8;
