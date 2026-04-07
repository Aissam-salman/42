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
  void add(void);
  void search(void);
  void exit(void);

  void increaseNbContact(void);
  int getNbContact(void) const;

private:
  int _nbContact;
  Contact _contacts[8];
};

#endif
