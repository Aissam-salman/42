/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:37:16 by salman            #+#    #+#             */
/*   Updated: 2026/04/20 21:03:09 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("", 145, 137), _target("none") {
  std::ofstream ofs;

  ofs.open("none_shrubbery");
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
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src.getName(), src.getGradeRequiredToSign(),
            src.getGradeRequiredToEx()) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  if (this != &rhs) {
    // TODO: Assign properties
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
