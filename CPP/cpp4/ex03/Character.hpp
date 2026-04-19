/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:13:46 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 18:23:28 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
  AMateria *_materials[4];
  std::string _name;
  int _idx;
  AMateria **_garbage;
  int _g_idx;

public:
  Character(void);
  Character(std::string const name);
  Character(Character const &src);
  Character &operator=(Character const &rhs);
  virtual ~Character(void);

  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
  void cleanGarbage();
};

#endif
