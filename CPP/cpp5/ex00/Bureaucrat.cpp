/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:29:39 by salman            #+#    #+#             */
/*   Updated: 2026/04/20 18:54:56 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
}
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::increment(void) {
  if (this->_grade > 1)
    this->_grade--;
  else if (this->_grade <= 1)
    throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement(void) {
  if (this->_grade < 150)
    this->_grade++;
  else if (this->_grade >= 150)
    throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high !!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low !!");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return (o);
}
