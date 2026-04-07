/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:26:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:26:17 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : _nbContact(0) {
  std::cout << "constructor PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook(void) {
  std::cout << "destructor PhoneBook" << std::endl;
  return;
}

void PhoneBook::add(Contact newContact) {
  std::cout << "add" << std::endl;
  if (this->_nbContact == 8)
    this->_contacts[0] = newContact;
  else if (this->_nbContact < 8 && this->_nbContact >= 0) {
    this->_contacts[this->_nbContact] = newContact;
    this->_nbContact += 1;
  }
  return;
}

void PhoneBook::search(void) {
  std::cout << "search" << std::endl;

	/*
    10 char max  after "aissamd..." sinon trunc 7 and ... after
		align right
	 | index | first name | last name | nickname | 
	 ---------------------------------------------
	 |      0|    aisssam | lamjadab |    salman |
	 ---------------------------------------------
	 |      1|    aisssam | lamjadab |    salman |
	 ---------------------------------------------
	 |      2|    aisssam | lamjadab |    salman |
	 ---------------------------------------------

	 > choice a contact by index : 
	 1

	 ---------------------------
	 | index      |           1|
	 ---------------------------
	 | first name |     aisssam|
	 ---------------------------
	 | last name  |    lamjadab|
	 ---------------------------
	 | nickname   |      salman|
	 ---------------------------
	*/

  return;
}

void exit(void) {
  std::cout << "exit" << std::endl;
  exit(0);
}
