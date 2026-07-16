/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:34:52 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/22 12:43:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &src) { *this = src; }

Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return (*this);
}

Intern::~Intern(void) {}

AForm *Intern::makePresidential(std::string target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string target) {
  return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string target) {
  return (new ShrubberyCreationForm(target));
}

// Intern::FormNotFoundException::FormNotFoundException(std::string target) {
//   this->_message = target + " not found in existing form.";
// }
//
// Intern::FormNotFoundException::~FormNotFoundException(void) throw() {}
//
// const char *Intern::FormNotFoundException::what() const throw() {
//   return (this->_message.c_str());
// }

AForm *Intern::makeForm(std::string nameForm, std::string targetForm) {
  std::string forms[3] = {"presidential pardon", "robotomy request",
                          "shrubbery creation"};

  AForm *(Intern::*make[3])(std::string) = {
      &Intern::makePresidential,
      &Intern::makeRobotomy,
      &Intern::makeShrubbery,
  };

  for (int i = 0; i < 3; i++) {
    if (nameForm == forms[i]) {
      std::cout << "Intern creates " << nameForm << std::endl;
      return (this->*make[i])(targetForm);
    }
  }
  // throw Intern::FormNotFoundException(targetForm);
  std::cout << "Intern cannot create " << nameForm << " is not existing!" << std::endl;
  return NULL;
}
