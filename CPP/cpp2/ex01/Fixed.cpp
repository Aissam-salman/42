/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:16:32 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 15:23:39 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void): _fixedPointValue(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src) {
	std::cout <<"Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(int const nb) {
	std::cout <<"Int constructor called\n";
	this->_fixedPointValue = nb << this->_bits;
}

Fixed::Fixed(float const ft) {
	std::cout <<"Float constructor called\n";
	this->_fixedPointValue = roundf(ft * (1 << this->_bits));
}

Fixed::~Fixed(void){
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &rhs){
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw){
	this->_fixedPointValue = raw;
}

int Fixed::getRawBits(void) const {
	return (this->_fixedPointValue);
}

float Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (1 << this->_bits));
}

int Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs){
	o << rhs.toFloat();
	return (o);
}

int const Fixed::_bits = 8;
