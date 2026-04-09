/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:53:22 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/09 18:00:31 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	// <name>: BraiiiiiiinnnzzzZ...
	// Foo: BraiiiiiiinnnzzzZ...
	void announce(void);

private:
	std::string _name;
};

#endif
