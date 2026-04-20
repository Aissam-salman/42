/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:54:14 by salman            #+#    #+#             */
/*   Updated: 2026/04/20 16:58:02 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  return (0);
}
