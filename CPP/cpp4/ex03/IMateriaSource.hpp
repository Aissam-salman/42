/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:18:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 20:31:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *m) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
