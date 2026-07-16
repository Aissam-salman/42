/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:54:14 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 12:46:24 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>


int main(void) {
	std::srand(std::time(0));
	AForm *f =  new RobotomyRequestForm("baa");
	Bureaucrat a = Bureaucrat("bob", 5);

	a.signForm(*f);
	a.executeForm(*f);

	delete f;
  return (0);
}
