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

Contact::Contact(void)
{
  std::cout << "constructor Contact" << std::endl;
  return;
}

Contact::~Contact(void) {
  std::cout << "destructor Contact" << std::endl;
  return;
}

std::string Contact::getNumber(void) const { return this->_number; }
std::string Contact::getFirstname(void) const { return this->_firstname; }
std::string Contact::getLastname(void) const { return this->_lastname; }
std::string Contact::getNickname(void) const { return this->_nickname; }
int Contact::getIndex(void) const { return this->_index; }

void Contact::setNumber(std::string newNumber){
	if (newNumber.length() != 10)
		return;
	this->_number = newNumber;
	return;
}
void Contact::setFirstname(std::string newFirstname){
	if (!newFirstname.empty())
		this->_firstname = newFirstname;
	return;
}
void Contact::setLastname(std::string newLastname){
	if (!newLastname.empty())
		this->_lastname = newLastname;
	return;
}
void Contact::setNickname(std::string newNickname){
	if (!newNickname.empty())
		this->_nickname = newNickname;
	return;
}
void Contact::setIndex(int newIndex){
	if (newIndex >= 0 && newIndex <= 8)
		this->_index = newIndex;
	return;
}
