/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:26:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:26:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:

  Contact(void);
  ~Contact(void);

  std::string getNumber(void) const;
  std::string getFirstname(void) const;
  std::string getLastname(void) const;
  std::string getNickname(void) const;
  int getIndex(void) const;
	std::string getDarkSecret(void) const;

  int setNumber(std::string newNumber);
  int setFirstname(std::string newFirstname);
  int setLastname(std::string newLastname);
  int setNickname(std::string newNickname);
  int setIndex(int newIndex);
	int setDarkSecret(std::string secret);
	void create(void);
	void generate(std::string fn, std::string ln, std::string nn, std::string nb);

private:
  std::string _number;
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
	std::string _darkSecret;
  int _index;
};

#endif
