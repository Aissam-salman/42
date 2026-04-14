/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:04:13 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 20:34:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): _x(0), _y(0) {
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y){
}

Point::Point(Point const &src) {
	*this = src;
}

Point& Point::operator=(Point const &rhs) {
	return *this;
}

Point::~Point() {
}

Fixed const Point::getX() const{
	return (this->_x);
}

Fixed const Point::getY() const{
	return (this->_y);
}

