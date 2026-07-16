/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:29:39 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 12:41:03 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

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

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(Bureaucrat::FormNotSignedException &e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high !!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low !!");
}

const char *Bureaucrat::FormNotSignedException::what() const throw() {
  return ("Form not signed");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return (o);
}
