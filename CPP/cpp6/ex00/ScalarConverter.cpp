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
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

// nanf nan
void displayNaN(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}

// -inff +inff
// -inf +inf
void displayInf(std::string str) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (str.compare(0, 1, std::string("-")) == 0) {
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  } else if (str.compare(0, 1, std::string("+")) == 0) {
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else {
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
  }
}

bool my_isprint(char ch) {
  return std::isprint(static_cast<unsigned char>(ch));
}

void ScalarConverter::convert(std::string str) {
  (void)str;
  if (str.empty()) {
    std::cerr << "Empty not allowed!" << std::endl;
    return;
  }
  if (str == "nan" || str == "nanf")
    return displayNaN();
  else if (str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf" ||
           str == "inf")
    return displayInf(str);
  double d;
  float f;
  int nb;
  unsigned char c;

  if (str.length() == 1) {
    if (my_isprint(str[0]) == false) {
      std::cerr << "Not printable char" << std::endl;
      return;
    }
    if (!std::isdigit(str[0])) {
      c = static_cast<unsigned char>(str[0]);
      d = static_cast<double>(c);
      f = static_cast<float>(d);
      nb = static_cast<int>(c);
    } else {
      d = strtod(str.c_str(), NULL);
      f = static_cast<float>(d);
      nb = static_cast<int>(d);
      c = static_cast<char>(d);
    }
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
    return;
  }

  char *end;

  d = strtod(str.c_str(), &end);
  if (*end != '\0' && std::string(end) != "f") {
    std::cerr << "Input not convertible !" << std::endl;
    return;
  }
  f = static_cast<float>(d);
  nb = static_cast<int>(d);
  c = static_cast<char>(d);

  std::cout << "char: ";
  if (d < 0 || d > 127)
    std::cout << "impossible" << std::endl;
  else
    std::cout << c << std::endl;
  std::cout << "int: " << nb << std::endl;
  std::cout << "float: " << f << std::endl;
  std::cout << "double: " << d << std::endl;
}
