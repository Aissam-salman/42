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

Fixed::Fixed(void): _rawBits(0) {}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::~Fixed(void){}

Fixed &Fixed::operator=(Fixed const &rhs){
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw){
	this->_rawBits = raw;
}

int Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

int const Fixed::_nbFractionalBits = 8;
