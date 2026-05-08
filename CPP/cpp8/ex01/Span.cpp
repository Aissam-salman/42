/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:48:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 19:46:19 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>

Span::Span(void) : _N(0), _size(0) {}

Span::Span(unsigned int n) : _N(n), _size(0) {}

Span::Span(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  this->_span.assign(begin, end);
  this->_N = std::distance(begin, end);
  this->_size = std::distance(begin, end);
}

Span::Span(const Span &src) : _N(src._N), _size(src._size) {
  std::vector<int>::const_iterator itr = src._span.begin();

  for (; itr != src._span.end(); ++itr) {
    this->_span.push_back(*itr);
  }
}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    this->_span.clear();
    this->_span = std::vector<int>();
    this->_size = rhs._size;
    this->_N = rhs._N;

    std::vector<int>::const_iterator itr = rhs._span.begin();

    for (; itr != rhs._span.end(); ++itr) {
      this->_span.push_back(*itr);
    }
  }
  return *this;
}

Span::~Span() {}

void Span::print(void) {
  std::vector<int>::iterator it = this->_span.begin();
  for (; it != this->_span.end(); ++it) {
    std::cout << *it;
    std::vector<int>::iterator next = it;
    ++next;
    if (next != this->_span.end())
      std::cout << ", ";
  }
  std::cout << std::endl;
}

void Span::addNumber(int nbr) {
  if (this->_size == this->_N)
    throw std::exception();
  else {
    this->_span.push_back(nbr);
    this->_size++;
  }
}

int Span::shortestSpan(void) {
  if (this->_size <= 1)
    throw std::exception();
  Span cp = Span(*this);
  std::sort(cp._span.begin(), cp._span.end());

  int min = INT_MAX;
  for (size_t i = 0; i < cp._size - 1; i++) {
    int res = cp._span[i + 1] - cp._span[i];
    if (res < min)
      min = res;
  }
  return min;
}

int Span::longestSpan(void) const {
  if (this->_size <= 1)
    throw std::exception();
  return *std::max_element(this->_span.begin(), this->_span.end()) -
         *std::min_element(this->_span.begin(), this->_span.end());
}
