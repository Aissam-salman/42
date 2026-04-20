/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:53:05 by salman            #+#    #+#             */
/*   Updated: 2026/04/20 18:58:32 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

Form::Form(void)
    : _name(""), _isSigned(false), _gradeRequiredToSign(1),
      _gradeRequiredToEx(1) {}

Form::Form(std::string name, int gradeRToS, int gradeRToE)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRToS),
      _gradeRequiredToEx(gradeRToE) {}

Form::Form(const Form &src)
    : _name(src.getName()), _isSigned(src.getIsSigned()),
      _gradeRequiredToSign(src.getGradeRequiredToSign()),
      _gradeRequiredToEx(src.getGradeRequiredToEx()) {}

Form &Form::operator=(const Form &rhs) {
  if (this != &rhs) {
    this->_isSigned = rhs.getIsSigned();
  }
  return *this;
}

Form::~Form() {}

std::string Form::getName(void) const { return (this->_name); }

bool Form::getIsSigned(void) const { return (this->_isSigned); }

int Form::getGradeRequiredToSign(void) const {
  return (this->_gradeRequiredToSign);
}

int Form::getGradeRequiredToEx(void) const {
  return (this->_gradeRequiredToEx);
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() <= this->_gradeRequiredToSign)
    this->_isSigned = true;
  else
    throw Form::GradeTooLowException();
}

void Form::signForm(Bureaucrat const &bureaucrat) {
  try {
    this->beSigned(bureaucrat);
    std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
  } catch (std::exception &e) {
    std::cout << bureaucrat.getName() << " couldn't sign " << this->_name
              << " because " << e.what() << "." << std::endl;
  }
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("grade is to high");
}
const char *Form::GradeTooLowException::what() const throw() {
  return ("grade is to low");
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
  o << "Name: " << rhs.getName() << ", is_signed: " << rhs.getIsSigned()
    << ", grade req sign: " << rhs.getGradeRequiredToSign()
    << ", grade rep ex: " << rhs.getGradeRequiredToEx();
  return (o);
}
