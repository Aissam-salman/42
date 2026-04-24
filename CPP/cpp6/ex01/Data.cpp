/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:21:19 by salman            #+#    #+#             */
/*   Updated: 2026/04/24 17:40:50 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <cstddef>
#include <iostream>

Data::Data() : _head(NULL), _tail(NULL), _node(""), _next(NULL) {}

Data::Data(const Data &src) { *this = src; }

Data &Data::operator=(const Data &rhs) {
  if (this != &rhs) {
    this->_head = rhs._head;
    this->_tail = rhs._tail;
    this->_node = rhs._node;
    this->_next = NULL;
    this->_next = rhs._next;
  }
  return *this;
}

Data::~Data() {}

void Data::pushBack(Data *ptr) {
  if (this->_head == NULL) {
    this->_head = ptr;
    this->_tail = ptr;
  } else
    this->_tail->_next = ptr;
}

void Data::pushFirst(Data *ptr) {
  if (this->_head == NULL) {
    this->_head = ptr;
    this->_tail = ptr;
  } else {
    Data *tmp = this->_head;
    this->_head = ptr;
    this->_head->_next = tmp;
  }
}

void Data::printData(void) {
  Data *head = this->_head;
  int i = 0;
  while (head) {
    std::cout << "node [" << i << "] = " << head->_node << std::endl;
    i++;
    head = head->_next;
  }
}
