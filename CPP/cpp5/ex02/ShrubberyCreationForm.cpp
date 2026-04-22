/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:37:16 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 13:05:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src.getName(), src.getGradeRequiredToSign(),
            src.getGradeRequiredToEx()), _target(src._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  if (this != &rhs) {
    this->_target = rhs._target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (AForm::isExecutable(executor)) {
    std::ofstream ofs;

		std::string filename = this->_target + "_shrubbery";

    ofs.open(filename.c_str());
    if (ofs.is_open()) {
      ofs << "\n\n";
      ofs << "	   \\/ |    |/   \n";
      ofs << "      \\/ / \\||/  /_/___/_   \n";
      ofs << "       \\/   |/ \\/           \n";
      ofs << "  _\\__\\_\\   |  /_____/_     \n";
      ofs << "         \\  | /          /  \n";
      ofs << "__ _-----`  |{,-----------~ \n";
      ofs << "          \\ }{              \n";
      ofs << "           }{{              \n";
      ofs << "           }}{              \n";
      ofs << "           {{}              \n";
      ofs << "     , -=-~{ .-^- _         \n";
      ofs.close();
    }

  } else {
    throw AForm::GradeTooLowException();
  }
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
