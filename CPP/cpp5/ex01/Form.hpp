/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:41:48 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 12:27:58 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form {
private:
  std::string const _name;
  bool _isSigned;
  int const _gradeRequiredToSign;
  int const _gradeRequiredToEx;

public:
  Form(void);
  Form(std::string name, int gradeRToS, int gradeRToE);
  Form(Form const &src);
  Form &operator=(Form const &rhs);
  ~Form(void);

  std::string getName(void) const;
  bool getIsSigned(void) const;
  int getGradeRequiredToSign(void) const;
  int getGradeRequiredToEx(void) const;

  void beSigned(Bureaucrat const &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
