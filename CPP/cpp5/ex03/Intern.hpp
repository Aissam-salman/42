/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:30:52 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/21 20:18:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
// #include <exception>
#include <string>

class Intern {
public:
  Intern(void);
  Intern(const Intern &src);
  Intern &operator=(const Intern &rhs);
  ~Intern(void);

  AForm *makeForm(std::string nameForm, std::string targetForm);
	// class FormNotFoundException : public std::exception {
	// private:
	// 	std::string _message;
	// public:
	// 	FormNotFoundException(std::string target);
	// 	~FormNotFoundException(void) throw();
	// 	virtual const char *what() const throw();
	// };

private:
	AForm *makePresidential(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makeShrubbery(std::string target);
};

#endif
