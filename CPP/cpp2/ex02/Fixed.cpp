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

Fixed::Fixed(void) : _fixedPointValue(0) {}

Fixed::Fixed(Fixed const &src) { *this = src; }

Fixed::Fixed(int const nb) { this->_fixedPointValue = nb << this->_bits; }

Fixed::Fixed(float const ft) {
  this->_fixedPointValue = roundf(ft * (1 << this->_bits));
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(Fixed const &rhs) {
  if (this != &rhs)
    this->_fixedPointValue = rhs.getRawBits();
  return *this;
}

bool Fixed::operator>(Fixed const &rhs) const {
  return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const {
  return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const {
  return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const {
  return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const {
  return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const {
  return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs) const {
  Fixed r;

  r.setRawBits(this->getRawBits() + rhs.getRawBits());
  return r;
}

Fixed Fixed::operator-(Fixed const &rhs) const {
  Fixed r;

  r.setRawBits(this->getRawBits() - rhs.getRawBits());
  return r;
}

Fixed Fixed::operator*(Fixed const &rhs) const {
  Fixed r;

  r.setRawBits(this->getRawBits() * rhs.getRawBits());
  return r;
}

Fixed Fixed::operator/(Fixed const &rhs) const {
  Fixed r;

  r.setRawBits(this->getRawBits() / rhs.getRawBits());
  return r;
}

Fixed &Fixed::operator++(void) {
  ++this->_fixedPointValue;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  ++this->_fixedPointValue;
  return (tmp);
}

Fixed &Fixed::operator--(void) {
  --this->_fixedPointValue;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  --this->_fixedPointValue;
  return (tmp);
}

Fixed &Fixed::min(Fixed &r1, Fixed &r2) {
  if (r1.getRawBits() < r2.getRawBits())
    return (r1);
  return (r2);
}

const Fixed &Fixed::min(Fixed const &r1, Fixed const &r2) {
  if (r1.getRawBits() < r2.getRawBits())
    return (r1);
  return (r2);
}

Fixed &Fixed::max(Fixed &r1, Fixed &r2) {
  if (r1.getRawBits() > r2.getRawBits())
    return (r1);
  return (r2);
}

const Fixed &Fixed::max(Fixed const &r1, Fixed const &r2) {
  if (r1.getRawBits() > r2.getRawBits())
    return (r1);
  return (r2);
}

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

int Fixed::getRawBits(void) const { return (this->_fixedPointValue); }

float Fixed::toFloat(void) const {
  return ((float)this->getRawBits() / (1 << this->_bits));
}

int Fixed::toInt(void) const { return (this->getRawBits() >> this->_bits); }

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
  o << rhs.toFloat();
  return (o);
}

int const Fixed::_bits = 8;
