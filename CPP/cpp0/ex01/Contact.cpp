/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:27:06 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:27:07 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getNumber(void) const { return this->_number; }
std::string Contact::getFirstname(void) const { return this->_firstname; }
std::string Contact::getLastname(void) const { return this->_lastname; }
std::string Contact::getNickname(void) const { return this->_nickname; }
int Contact::getIndex(void) const { return this->_index; }

int Contact::setNumber(std::string newNumber) {
  if (newNumber.length() != 10)
	{
		std::cout << "Invalid number!\n";
    return (1);
	}
  this->_number = newNumber;
  return (0);
}
int Contact::setFirstname(std::string newFirstname) {
  if (newFirstname.empty())
		return (1);
	this->_firstname = newFirstname;
  return (0);
}
int Contact::setLastname(std::string newLastname) {
  if (newLastname.empty())
		return (1);
	this->_lastname = newLastname;
  return (0);
}
int Contact::setNickname(std::string newNickname) {
  if (newNickname.empty())
		return (1);
	this->_nickname = newNickname;
  return (0);
}
int Contact::setIndex(int newIndex) {
  if (newIndex >= 0 && newIndex <= 8)
	{
    this->_index = newIndex;
		return (0);
	}
  return (1);
}

void Contact::create(void) {
	std::string fn;
	std::string ln;
	std::string nn;
	std::string nb;

  std::cout << "Firstname: ";
  std::cin >> fn;
  std::cout << "Lastname: ";
  std::cin >> ln;
  std::cout << "Nickname: ";
  std::cin >> nn;
  std::cout << "Numero: ";
  std::cin >> nb;
	this->setFirstname(fn);
	this->setLastname(ln);
	this->setNickname(nn);
	this->setNumber(nb);
}
