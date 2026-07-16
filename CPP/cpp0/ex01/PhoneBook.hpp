/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:26:05 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:26:08 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook(void);
  ~PhoneBook(void);

  void start(void);
  void builder(std::string fn, std::string ln, std::string nn, std::string nb,
               std::string ds);
  void add(void);
  void search(void);
  void exit(void);

  void generate(void);
  void increaseNbContact(void);
  int getNbContact(void) const;

private:
  int _decal;
  int _nbContact;
  Contact _contacts[8];
};

#endif
