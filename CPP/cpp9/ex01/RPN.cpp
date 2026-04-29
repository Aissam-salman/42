/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:31 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/29 13:13:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <stack>

RPN::RPN() : _line(NULL), _size(0), _c() {}

RPN::RPN(std::string line) : _line(line), _size(0), _c() {}

RPN::RPN(const RPN &src) : _line(src._line), _size(src._size) {
  this->_c = std::stack<std::string>(src._c);
}

RPN &RPN::operator=(const RPN &rhs) {
  if (this != &rhs) {
    while (!this->_c.empty())
      this->_c.pop();
    this->_size = rhs._size;
    this->_c = std::stack<std::string>(rhs._c);
  }
  return *this;
}

RPN::~RPN() {
  while (!this->_c.empty())
    this->_c.pop();
}

bool RPN::parsing(void){
	return true;
}

void RPN::compute(void) {}

void RPN::run(void) {
	if (this->parsing())
		this->compute();
}
