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

PhoneBook::PhoneBook(void) : _decal(0), _nbContact(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::start(void) {
  std::cout << "\n";
  std::cout << "PHONE" << std::endl;
  std::cout << "|" << std::setw(10) << "SEARCH" << "|";
  std::cout << std::setw(10) << "ADD" << "|\n";
  std::cout << "|" << std::setw(10) << "EXIT" << "|";
  std::cout << std::setw(10) << "GENERATE" << "|\n";
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
    if (this->_decal == 7)
      this->_decal = 0;
    newContact.setIndex(this->_decal);
    this->_contacts[this->_decal] = newContact;
    this->_decal += 1;
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
    std::cout << contact.getFirstname().substr(0, 9) << "." << "|";
  else
    std::cout << std::setw(10) << contact.getFirstname() << "|";
  if (contact.getLastname().length() > 10)
    std::cout << contact.getLastname().substr(0, 9) << "." << "|";
  else
    std::cout << std::setw(10) << contact.getLastname() << "|";
  if (contact.getNickname().length() > 10)
    std::cout << contact.getNickname().substr(0, 9) << "." << "|";
  else
    std::cout << std::setw(10) << contact.getNickname() << "|";
  std::cout << "\n";
}

static void print_contact(Contact contact) {
  if (contact.getFirstname().empty())
    return;
  std::cout << "First name: " << contact.getFirstname() << std::endl;
  std::cout << "Last name: " << contact.getLastname() << std::endl;
  std::cout << "Nickname: " << contact.getNickname() << std::endl;
  std::cout << "Number: " << contact.getNumber() << std::endl;
  std::cout << "Darksecret: " << contact.getDarkSecret() << std::endl;
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
    if (!(std::cin >> choice))
			return ;
    if (std::cin.fail() || std::cin.eof())
      return ;
    if (choice < 0 || choice > 7) {
      std::cout << "Outside ! pls enter under 0.7\n";
      return;
    }
    print_contact(this->_contacts[choice]);
  }
}

void PhoneBook::builder(std::string fn, std::string ln, std::string nn,
                        std::string nb) {
  if (this->getNbContact() == 8) {
    if (this->_decal == 7)
      this->_decal = 0;
    this->_contacts[this->_decal].generate(fn, ln, nn, nb);
    this->_contacts[this->_decal].setIndex(this->_decal);
    this->_decal += 1;
  } else if (this->getNbContact() < 8 && this->getNbContact() >= 0) {
    this->_contacts[this->_nbContact].generate(fn, ln, nn, nb);
    this->_contacts[this->_nbContact].setIndex(this->_nbContact);
    this->increaseNbContact();
  }
}

void PhoneBook::generate(void) {
  this->builder("Aissam", "Lamjadab", "salman", "0620200220", "foo");
  this->builder("Jean", "Dupont", "jdupont", "0102030405", "loi");
  this->builder("Marie", "Curie", "radium", "0612345678", "doo");
  this->builder("Montgomery", "Scott", "scotty", "0789456123", "boo");
  this->builder("Lara", "Croft", "tombraider", "0147258369", "asd");
  this->builder("Elon", "Musk", "xman", "0000000001", "qwec");
  this->builder("Ada", "Lovelace", "firstdev", "1010101010", "asdaf");
  this->builder("Foo", "Boo", "fooboo", "1010101010", "klj");
}

void PhoneBook::exit(void) { std::exit(0); }
