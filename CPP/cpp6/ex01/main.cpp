/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:12 by salman            #+#    #+#             */
/*   Updated: 2026/04/24 17:21:09 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

void pp(std::string const msg) {
  std::cout << std::endl;
  std::cout << msg << std::endl;
}

int main() {
  Data *linkedList = new Data();

  linkedList->pushBack("pomme");
  linkedList->pushBack("banane");
  linkedList->pushBack("fraise");
  pp("==== ORIGINAL ====");
	std::cout << "original ptr: " << linkedList << std::endl;
  linkedList->printData();

  uintptr_t serialPtr = Serializer::serialize(linkedList);
	std::cout << "serial: " << serialPtr << std::endl;

  Data *deserialPtr = Serializer::deserialize(serialPtr);

  pp("==== SERIAL ====");
	std::cout << "deserial ptr: " << deserialPtr << std::endl;
  deserialPtr->printData();

  pp("==== COMPARE ORIGINAL AND SERIAL ====");
  if (deserialPtr == linkedList)
	{
    std::cout << "Ptr equal!" << std::endl;
		std::cout << "original ptr: " << linkedList << std::endl;
		std::cout << "deserial ptr: " << deserialPtr << std::endl;
	}

  deserialPtr->pushFirst("kiwi");

  pp("==== SERIAL MODIF ====");
  deserialPtr->printData();

  pp("==== COMPARE ORIGINAL AND SERIAL AFTER MODIF ====");
  if (deserialPtr == linkedList)
	{
    std::cout << "Same object" << std::endl;
		std::cout << "original ptr: " << linkedList << std::endl;
		std::cout << "deserial ptr: " << deserialPtr << std::endl;
	}
  deserialPtr->clear();
  return 0;
}
