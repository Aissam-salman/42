/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:42:51 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 20:17:38 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

class Parent {
public:
  virtual ~Parent(void) {};
};
class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int main(void) {
  Child1 a;
  Parent *b = &a;

  // Explicit downcast > suspens...
  Child1 *c = dynamic_cast<Child1 *>(b);
  if (!c)
    std::cout << "Conversion is Not ok" << std::endl;
  else
    std::cout << "Conversion ok" << std::endl;

  try {
    Child2 &d = dynamic_cast<Child2 &>(*b);
    std::cout << "Conversion ok" << std::endl;

  } catch (std::bad_cast &bc) {
    std::cout << "Conversion is not ok: " << bc.what() << std::endl;
  }

  return (0);
}
