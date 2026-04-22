/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:37:54 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 16:38:54 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	if (this != &rhs) {
		// TODO: Assign properties
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
}
