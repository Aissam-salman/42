/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:54:14 by salman            #+#    #+#             */
/*   Updated: 2026/04/21 17:50:52 by alamjada         ###   ########.fr       */
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

	f->signAForm(a);
	a.executeForm(*f);

	delete f;
  return (0);
}
