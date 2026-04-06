/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:21:33 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/06 18:36:57 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"
#include <iostream>

Sample::Sample(void) {
  std::cout << "constructor call" << std::endl;
	this->foo = 0;
  return;
}

Sample::~Sample(void) {
  std::cout << "destructor call" << std::endl;
  return;
}

void Sample::bar(void) const {
	std::cout << "bar" << std::endl;
}

