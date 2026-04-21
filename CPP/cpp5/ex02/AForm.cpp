/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:53:05 by salman            #+#    #+#             */
/*   Updated: 2026/04/21 17:46:06 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

AForm::AForm(void)
    : _name(""), _isSigned(false), _gradeRequiredToSign(1),
      _gradeRequiredToEx(1) {}

AForm::AForm(std::string name, int gradeRToS, int gradeRToE)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRToS),
      _gradeRequiredToEx(gradeRToE) {}

AForm::AForm(const AForm &src)
    : _name(src.getName()), _isSigned(src.getIsSigned()),
      _gradeRequiredToSign(src.getGradeRequiredToSign()),
      _gradeRequiredToEx(src.getGradeRequiredToEx()) {}

AForm &AForm::operator=(const AForm &rhs) {
  if (this != &rhs) {
    this->_isSigned = rhs.getIsSigned();
  }
  return *this;
}

AForm::~AForm() {}

std::string AForm::getName(void) const { return (this->_name); }

bool AForm::getIsSigned(void) const { return (this->_isSigned); }

int AForm::getGradeRequiredToSign(void) const {
  return (this->_gradeRequiredToSign);
}

int AForm::getGradeRequiredToEx(void) const {
  return (this->_gradeRequiredToEx);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() <= this->_gradeRequiredToSign)
    this->_isSigned = true;
  else
    throw AForm::GradeTooLowException();
}

void AForm::signAForm(Bureaucrat const &bureaucrat) {
  try {
    this->beSigned(bureaucrat);
    std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
  } catch (std::exception &e) {
    std::cout << bureaucrat.getName() << " couldn't sign " << this->_name
              << " because " << e.what() << "." << std::endl;
  }
}

bool AForm::isExecutable(Bureaucrat const &executor) const {
  if (this->getIsSigned() &&
      executor.getGrade() <= this->getGradeRequiredToEx()) {
		return true;
  }
	if (this->getIsSigned() == false)
		throw Bureaucrat::FormNotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToEx())
		throw Bureaucrat::GradeTooLowException();
	return false;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("grade is to high");
}
const char *AForm::GradeTooLowException::what() const throw() {
  return ("grade is to low");
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs) {
  o << "Name: " << rhs.getName() << ", is_signed: " << rhs.getIsSigned()
    << ", grade req sign: " << rhs.getGradeRequiredToSign()
    << ", grade rep ex: " << rhs.getGradeRequiredToEx();
  return (o);
}
