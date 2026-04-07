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
#include <ios>
#include <iostream>

PhoneBook::PhoneBook(void) : _nbContact(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::start(void) {
	std::cout << "\n";
  std::cout << "PHONE" << std::endl;
  std::cout << "||" << std::setw(10) << "1 Contact" << "||";
  std::cout << std::setw(10) << "2 add Contact" << "||\n";
  std::cout << "||" << std::setw(10) << "3 Exit" << "||\n";
  std::cout << "Input: ";
}

void PhoneBook::increaseNbContact(void) {
  if (this->getNbContact() < 8)
    this->_nbContact += 1;
  else if (this->getNbContact() == 8)
    return;
  return;
}

int PhoneBook::getNbContact(void) const { return this->_nbContact; }

void PhoneBook::add(void) {
  Contact newContact;

  newContact.create();
  if (this->getNbContact() == 8) {
    newContact.setIndex(0);
    this->_contacts[0] = newContact;
  } else if (this->getNbContact() < 8 && this->getNbContact() >= 0) {
    newContact.setIndex(this->getNbContact());
    this->_contacts[this->getNbContact()] = newContact;
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

static void print_contacts(Contact contact) {
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

static void print_contact(Contact contact) {
  if (contact.getFirstname().empty())
    return;
  std::cout << contact.getFirstname() << std::endl;
  std::cout << contact.getLastname() << std::endl;
  std::cout << contact.getNickname() << std::endl;
  std::cout << contact.getNumber() << std::endl;
	std::cout << "\n";
  return;
}

void PhoneBook::search(void) {
  std::setiosflags(std::ios_base::right);
  print_header();
  for (int i = 0; i < this->_nbContact; i++) {
    print_contacts(this->_contacts[i]);
  }
  std::cout << "\n";
  std::resetiosflags(std::ios_base::right);
  if (this->getNbContact() > 0) {
    int choice = 0;
    std::cout << "What contact you want to display? ";
    std::cin >> choice;
    if (choice < 0 || choice > 7) {
      std::cout << "Outside ! pls enter under 0.7\n";
      return;
    }
    print_contact(this->_contacts[choice]);
  }
}

void PhoneBook::exit(void) { std::exit(0); }
