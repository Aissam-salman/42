/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:21:02 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 20:31:40 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSouce {
	protected:
		AMateria *_inventory[4];
		int _idx;
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		MateriaSource &operator=(MateriaSource const &rhs);
		~MateriaSource(void);

		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
