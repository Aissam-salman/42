/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:29:39 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 12:39:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include  <iostream>

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
  if (this != &rhs)
    this->_grade = rhs._grade;
  return (*this);
}

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

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
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
