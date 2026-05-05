/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:54:14 by salman            #+#    #+#             */
/*   Updated: 2026/05/05 14:28:51 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>

int main(void) {
  try {
  	Bureaucrat br("bob", 150);
  	br.decrement();
  } catch (std::exception &e) {
  	std::cout << e.what() << std::endl;
  }
  try {
  	Bureaucrat be("tim", 1);
  	be.increment();
  } catch (std::exception &e) {
  	std::cout << e.what() << std::endl;
  }
  try {
  	Bureaucrat b("foo", 30);
  	b.decrement();
  	std::cout << b << std::endl;
  	b.increment();
  	std::cout << b << std::endl;
  } catch (std::exception &e) {
  	std::cout << e.what() << std::endl;
  }

  Form f = Form("sub", 5, 50);

  Bureaucrat bb("lama", 6); // change grade here
  bb.signForm(f);

  try {
    Form c = Form("c", 1, 12);

    Bureaucrat e("pigeon", 120); // change grade here
    c.beSigned(e);
  } catch (Form::GradeTooLowException &e) {
    std::cout << "other way: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
