/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:19:11 by salman            #+#    #+#             */
/*   Updated: 2026/04/25 16:07:16 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
// #include <iostream>
// #include <typeinfo>

int main(void) {
  std::srand(time(0));
  Base b;

  Base *random1 = b.generate();
  b.identify(random1);

  // const std::type_info &tid = typeid(*random1);

  // std::cout << tid.name() << std::endl;

  Base *ran2 = b.generate();
  b.identify(*ran2);

  // const std::type_info &tid2 = typeid(*ran2);

  // std::cout << tid2.name() << std::endl;

  return 0;
}
