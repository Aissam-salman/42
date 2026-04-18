/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 10:48:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 11:05:05 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#define BRAIN_IDEAS 100

#include <string>

class Brain {
public:
  Brain(void);
  Brain(Brain const &src);
  Brain &operator=(Brain const &rhs);
  ~Brain(void);

private:
  std::string ideas[BRAIN_IDEAS];
};

#endif
