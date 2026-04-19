/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:38:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/19 12:13:39 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void) {
  const AAnimal *j = new Dog();
  const AAnimal *i = new Cat();
  delete j; // should not create a leak
  delete i;
  // AAnimal animal = AAnimal(); you can't make this because class is abstract

  AAnimal **animals = new AAnimal *[10];
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
