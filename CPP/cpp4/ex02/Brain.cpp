/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 10:52:26 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 11:05:10 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain(void) { std::cout << "Default Constructor Brain" << std::endl; }

Brain::Brain(Brain const &src) {
  std::cout << "Copy Constructor Brain" << std::endl;
  *this = src;
}

Brain &Brain::operator=(Brain const &rhs) {
  std::cout << "Assignment operator Brain" << std::endl;
  if (this != &rhs) {
    for (int i = 0; i < BRAIN_IDEAS; i++) {
      this->ideas[i] = rhs.ideas[i];
    }
  }
  return (*this);
}

Brain::~Brain(void) { std::cout << "Destructor Brain" << std::endl; }
