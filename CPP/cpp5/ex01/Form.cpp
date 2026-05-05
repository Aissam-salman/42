/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:53:05 by salman            #+#    #+#             */
/*   Updated: 2026/05/05 14:24:07 by alamjada         ###   ########.fr       */
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
      _gradeRequiredToEx(gradeRToE) {
  if (gradeRToS < 1 || gradeRToE < 1)
    throw Form::GradeTooHighException();
  else if (gradeRToS > 150 || gradeRToE > 150)
    throw Form::GradeTooLowException();
}

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
