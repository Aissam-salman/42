/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:53:22 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/09 21:20:33 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

  void announce(void);
  static Zombie *newZombie(std::string name);
  static void randomChump(std::string name);

private:
  std::string _name;
};

#endif
