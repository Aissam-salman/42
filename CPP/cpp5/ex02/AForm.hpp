/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:25:54 by salman            #+#    #+#             */
/*   Updated: 2026/05/04 21:39:57 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class AForm {
private:
  std::string const _name;
  bool _isSigned;
  int const _gradeRequiredToSign;
  int const _gradeRequiredToEx;

public:
  AForm(void);
  AForm(std::string name, int gradeRToS, int gradeRToE);
  AForm(AForm const &src);
  AForm &operator=(AForm const &rhs);
  virtual ~AForm(void);

  std::string getName(void) const;
  bool getIsSigned(void) const;
  int getGradeRequiredToSign(void) const;
  int getGradeRequiredToEx(void) const;

  void beSigned(Bureaucrat const &bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;
	bool isExecutable(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
