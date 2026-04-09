/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:26:39 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/09 21:41:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie {
public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie();

  Zombie *zombieHorde(int N, std::string name);

private:
	std::string _name;
};
