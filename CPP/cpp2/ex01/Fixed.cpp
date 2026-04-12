/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:16:32 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/12 15:17:30 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() {
	
}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this != &rhs) {
		// TODO: Assign properties
	}
	return *this;
}

Fixed::~Fixed() {
}
