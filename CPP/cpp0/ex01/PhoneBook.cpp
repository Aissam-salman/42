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
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void) : _nbContact(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::increaseNbContact(void) {
  if (this->getNbContact() < 8)
    this->_nbContact += 1;
  else if (this->getNbContact() == 8)
    return;
  return;
}

int PhoneBook::getNbContact(void) const { return this->_nbContact; }

void PhoneBook::add(Contact newContact) {
  if (this->_nbContact == 8)
    this->_contacts[0] = newContact;
  else if (this->_nbContact < 8 && this->_nbContact >= 0) {
    this->_contacts[this->_nbContact] = newContact;
    this->increaseNbContact();
  }
  return;
}

static void print_header(void) {
  std::cout << "|     index|first name| last name|  nickname|\n";
  std::cout << std::setfill('-') << std::setw(46) << "\n";
  std::cout << std::setfill(' ');
  return;
}

static void print_contact(Contact contact) {
  std::cout << "|" << std::setw(10) << contact.getIndex() << "|";
  if (contact.getFirstname().length() > 10)
    std::cout << contact.getFirstname().substr(0, 7) << "..." << "|";
  else
    std::cout << std::setw(10) << contact.getFirstname() << "|";
  if (contact.getLastname().length() > 10)
    std::cout << contact.getLastname().substr(0, 7) << "..." << "|";
  else
    std::cout << std::setw(10) << contact.getLastname() << "|";
  if (contact.getNickname().length() > 10)
    std::cout << contact.getNickname().substr(0, 7) << "..." << "|";
  else
    std::cout << std::setw(10) << contact.getNickname() << "|";
}

/*
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
| number     |  0620202002|
---------------------------
*/
void PhoneBook::search(void) {
  std::setiosflags(std::ios_base::right);
  print_header();
  for (int i = 0; i < this->_nbContact; i++) {
    print_contact(this->_contacts[i]);
  }
  std::cout << "\n";
  return;
}

void PhoneBook::exit(void) { std::exit(0); }
