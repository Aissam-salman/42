/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:00:16 by salman            #+#    #+#             */
/*   Updated: 2026/04/25 16:05:13 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>

Base::~Base(void) {}

Base *Base::generate(void) {
  Base *b;
  int list[3] = {0, 1, 2};
  int nbRan = std::rand() % 3;
  int res = list[nbRan] ? list[nbRan] : 0;
  switch (res) {
  case 0:
    b = new A();
    break;
  case 1:
    b = new B();
    break;
  case 2:
    b = new C();
    break;
  }
  return b;
}

void Base::identify(Base *p) {
  std::cout << "IDENTIFY WITH POINTER" << std::endl;
  if (dynamic_cast<A *>(p))
    std::cout << "type A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "type B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "type C" << std::endl;
}

void Base::identify(Base &p) {
  std::cout << "IDENTIFY WITH REFERENCE" << std::endl;
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "type A" << std::endl;
    return;
  } catch (std::exception &bc) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "type B" << std::endl;
    return;
  } catch (std::exception &bc) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "type C" << std::endl;
  } catch (std::exception &bc) {
    std::cout << bc.what() << std::endl;
  }
}
