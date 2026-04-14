/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:52:28 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 14:52:58 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

	// Fixed x(12);
	// Fixed y (3);
	//
	// std::cout << (x < y ? "true" : "false") << std::endl;
	// std::cout << (x > y ? "true" : "false") << std::endl;
	// std::cout << (x >= y ? "true" : "false") << std::endl;
	// std::cout << (x <= y ? "true" : "false") << std::endl;
	// std::cout << (x == y ? "true" : "false") << std::endl;
	// std::cout << (x != y ? "true" : "false") << std::endl;
	//
	// std::cout << Fixed(x / y) << std::endl;
	// std::cout << Fixed(x * y) << std::endl;
	// std::cout << Fixed(x + y) << std::endl;
	// std::cout << Fixed(x - y) << std::endl;
	//
	// std::cout << x-- << std::endl;
	// std::cout << x << std::endl;
	// std::cout << --x << std::endl;
	// std::cout << x << std::endl;
  return 0;
}
