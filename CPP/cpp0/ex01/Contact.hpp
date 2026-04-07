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

  void setNumber(std::string newNumber);
  void setFirstname(std::string newFirstname);
  void setLastname(std::string newLastname);
  void setNickname(std::string newNickname);
  void setIndex(int newIndex);

private:
  std::string _number;
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  int _index;
};

#endif
