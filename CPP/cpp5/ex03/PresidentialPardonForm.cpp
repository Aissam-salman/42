/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:37:16 by salman            #+#    #+#             */
/*   Updated: 2026/04/21 19:20:14 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("presidential pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src.getName(), src.getGradeRequiredToSign(),
            src.getGradeRequiredToEx()),
      _target(src._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  if (this != &rhs) {
    this->_target = rhs._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (AForm::isExecutable(executor)) {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
  } else {
    throw AForm::GradeTooLowException();
  }
}
