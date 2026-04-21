/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:15:05 by salman            #+#    #+#             */
/*   Updated: 2026/04/21 17:09:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
protected:
  std::string const _name;
  int _grade;

public:
  Bureaucrat(void);
  Bureaucrat(std::string name);
  Bureaucrat(std::string name, int grade);
  ~Bureaucrat(void);

  std::string getName(void) const;
  int getGrade(void) const;

  void increment(void);
  void decrement(void);
	void executeForm(AForm const & form) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
