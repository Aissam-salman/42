/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:16:32 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 14:56:03 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _fixedPointValue(0) {
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
	std::cout << "Copy assigment operator called\n";
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw){
	this->_fixedPointValue = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->_fixedPointValue);
}

int const Fixed::_bits = 8;
