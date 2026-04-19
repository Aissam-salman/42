/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:38:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:38:54 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void) {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  std::cout << meta->getType() << " " << std::endl;
  delete meta;
  delete j;
  delete i;

  const WrongAnimal *WrongMeta = new WrongAnimal();
  const WrongAnimal *wc = new WrongCat();

  std::cout << WrongMeta->getType() << " " << std::endl;
  std::cout << wc->getType() << " " << std::endl;
  WrongMeta->makeSound();
  wc->makeSound();
  delete WrongMeta;
  delete wc;
  return 0;
}
