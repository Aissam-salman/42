/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:15:05 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 12:52:37 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
protected:
  std::string const _name;
  int _grade;

public:
  Bureaucrat(void);
  Bureaucrat(std::string name);
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &rhs);
  ~Bureaucrat(void);

  std::string getName(void) const;
  int getGrade(void) const;

  void increment(void);
  void decrement(void);
  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
