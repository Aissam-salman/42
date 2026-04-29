/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:31 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/29 15:10:17 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

#define CHARSET

RPN::RPN() : _line(NULL), _size(0) {}

RPN::RPN(std::string line) : _line(line), _size(0) {}

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

bool inCharset(char c) {
  std::string charset = "+-*/ ";
  if (charset.find(c) == std::string::npos)
    return false;
  return true;
}

bool haveOther(std::string line) {
  for (size_t i = 0; i < line.size(); i++) {
    if (!std::isdigit(line[i]) && !inCharset(line[i]))
      return false;
    if (i != line.size() - 1 && std::isdigit(line[i]) &&
        std::isdigit(line[i + 1]))
      return false;
  }
  return true;
}

bool haveOnlySpace(std::string line) {
  for (size_t i = 0; i < line.size(); i++) {
    if (!std::isspace(line[i]))
      return false;
  }
  return true;
}

bool RPN::parsing(void) {
  if (this->_line.empty())
    return false;
  if (haveOnlySpace(this->_line))
    return false;
  if (!haveOther(this->_line))
    return false;
  return true;
}

std::string choiceC(int first, int second, char charset){
	int r = 0;

	if (charset == '*')
		r = first * second;
	else if (charset == '+')
		r = first + second;
	else if (charset == '-')
		r = first - second;
	else if (charset == '/')
		r = std::floor(first / second);
	return std::to_string(r);
}

void RPN::compute(void) { 
	std::cout << this->_line << std::endl; 
	int second = 0;
	int first = 0;

	for (size_t i = 0; i < this->_line.size(); i++) {
		if (!std::isspace(this->_line[i]) && !inCharset(this->_line[i]))
			this->_c.push(&this->_line[i]);
		if (inCharset(this->_line[i]))
		{
			second = std::stoi(this->_c.top());
			this->_c.pop();
			first = std::stoi(this->_c.top());
			this->_c.push(choiceC(first, second, this->_line[i]));
		}
	}
	if (this->_c.size() > 1)
    std::cout << "Error" << std::endl;
	else
		std::cout << this->_c.top() << std::endl;
}

void RPN::run(void) {
  if (this->parsing())
    this->compute();
  else
    std::cout << "Error" << std::endl;
}
