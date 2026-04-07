/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:29:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:37:31 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <unistd.h>

int main() {
  PhoneBook phone;

  Contact contact;
	//  std::string newFirstname;
	//  std::string newLastname;
	//  std::string newNickname;
	// std::string number;
	//
	//  std::cout << "Firstname: ";
	//  std::cin >> newFirstname;
	//  std::cout << "Lastname: ";
	//  std::cin >> newLastname;
	//  std::cout << "Nickname: ";
	//  std::cin >> newNickname;
	//  std::cout << "Numero: ";
	//  std::cin >> number;

	contact.setIndex(0);
  contact.setFirstname("012345678910");
	contact.setLastname("Lamjada");
	contact.setNickname("salman");
	contact.setNumber("0620200203");

	phone.add(contact);
	phone.search();
	// phone.exit();
  return (0);
}
