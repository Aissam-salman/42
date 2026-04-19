/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:38:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/19 12:12:03 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void) {
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  delete j; // should not create a leak
  delete i;

  Animal **animals = new Animal *[10];
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0)
      animals[i] = new Cat();
    else
      animals[i] = new Dog();
  }

  // test deep copy
  Dog d;
  {
    Dog tmp = d;
  }
  d.makeSound();

  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }
  delete[] animals;
  return 0;
}
