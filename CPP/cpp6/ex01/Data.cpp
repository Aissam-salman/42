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

Data::Data(void) : _head(NULL), _tail(NULL), _size(0) {}

Data::Node::Node(const std::string &value): _value(value), _next(NULL){}

Data::Data(const Data &src) : _head(NULL), _tail(NULL), _size(0) {
  Node *cur = src._head;
  while (cur) {
    this->pushBack(cur->_value);
    cur = cur->_next;
  }
}

Data &Data::operator=(const Data &rhs) {
  if (this != &rhs) {
    this->clear();
    Node *cur = rhs._head;
    while (cur) {
      this->pushBack(cur->_value);
      cur = cur->_next;
    }
  }
  return (*this);
}

Data::~Data() { this->clear(); }

void Data::pushBack(const std::string &value) {
  Node *newNode = new Node(value);
  if (this->_head == NULL) {
    this->_head = newNode;
    this->_tail = newNode;
  } else {
    this->_tail->_next = newNode;
    this->_tail = newNode;
  }
  this->_size++;
}

void Data::pushFirst(const std::string &value) {
  Node *newNode = new Node(value);
  if (this->_head == NULL) {
    this->_head = newNode;
    this->_tail = newNode;
  } else {
		newNode->_next = this->_head;
    this->_head = newNode;
  }
	this->_size++;
}

void Data::printData(void) const {
  Node *head = this->_head;
  int i = 0;
  while (head) {
		std::cout << head->_value;
		if (head->_next)
			std::cout << " -> ";
    i++;
    head = head->_next;
  }
	std::cout << std::endl;
}

void Data::clear(void) {
	Node *cur = this->_head;
	while (cur)
	{
		Node *tmp = cur->_next;
		delete cur;
		cur = tmp;
	}
	_head = NULL;
	_tail = NULL;
	_size = 0;
}
