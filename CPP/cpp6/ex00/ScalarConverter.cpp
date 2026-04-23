/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:37:54 by salman            #+#    #+#             */
/*   Updated: 2026/04/23 16:54:12 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}


void displayNaN(std::string str) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;

  std::cout << "double: nan" << std::endl;

  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  // -inff +inff
  // -inf +inf


void ScalarConverter::convert(std::string str) {
  //-inff,+inff, nanf
  //-inf, +inf, nan
  if (str == "nan" || str == "nanf")
    return displayNaN(str);
  else if (str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf" ||
           str == "inf")
    return displayInf(str);

  // char
  // if non printable return
  // int
  if (d > std::numeric_limits<double>::max() ||
      d < -std::numeric_limits<double>::max()) {
  }
  //  if > INT_MAX or < INT_MIN return
  // float
  // double
  // std::stringstream convert to scalar
  // strtod if str is valide nb
}
