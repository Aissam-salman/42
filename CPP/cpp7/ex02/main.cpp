/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:57:27 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/26 19:13:45 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstddef>
#include <exception>
#include <iostream>

int main(void) {

  // ARRAY EMPTY
  //
  std::cout << "EMPTY INT ARR" << std::endl;
  Array<int> emp;
  std::cout << "size: " << emp.size() << ", [0]=" << emp[0] << std::endl;

  std::cout << "EMPTY STRING ARR" << std::endl;
  Array<std::string> strs;
  std::cout << "size: " << strs.size()
            << ", [0]=" << (strs[0].empty() ? "\"\"" : strs[0]) << std::endl;

  std::cout << "12 EMPTY INT ARR" << std::endl;
  Array<int> nbrs(12);
  for (size_t i = 0; i < nbrs.size(); i++) {
    if (i != nbrs.size() - 1)
      std::cout << nbrs[i] << ", ";
    else
      std::cout << nbrs[i] << std::endl;
  }

  std::cout << "12 EMPTY STRING ARR" << std::endl;
  Array<std::string> strss(12);
  for (size_t i = 0; i < strss.size(); i++) {
    if (i != strss.size() - 1) {
      if (strss[i].empty()) {
        std::cout << "\"\"" << ", ";
      } else
        std::cout << strss[i] << ", ";
    } else {
      if (strss[i].empty()) {
        std::cout << "\"\"" << std::endl;
      } else
        std::cout << strss[i] << std::endl;
    }
  }

  Array<int> arr(5);

  arr[0] = 12;
  arr[1] = 42;

  for (size_t i = 0; i < arr.size(); i++) {
    if (i != 4)
      std::cout << arr[i] << ", ";
    else
      std::cout << arr[i] << std::endl;
  }

  Array<int> copy = arr;

  std::cout << "ASSIGNATION CONSTRUCTOR" << std::endl;
  for (size_t i = 0; i < copy.size(); i++) {
    if (i != 4)
      std::cout << copy[i] << ", ";
    else
      std::cout << copy[i] << std::endl;
  }

  std::cout << "MODIF ASSIGNATION" << std::endl;

  copy[0] = 99;

  std::cout << "ASSIGNATION CONSTRUCTOR" << std::endl;
  for (size_t i = 0; i < copy.size(); i++) {
    if (i != 4)
      std::cout << copy[i] << ", ";
    else
      std::cout << copy[i] << std::endl;
  }
  std::cout << "ORIGINAL ARR" << std::endl;
  for (size_t i = 0; i < arr.size(); i++) {
    if (i != 4)
      std::cout << arr[i] << ", ";
    else
      std::cout << arr[i] << std::endl;
  }

  Array<std::string> fruits(3);
  fruits[0] = "pomme";
  fruits[1] = "banane";
  fruits[2] = "kiwi";

  for (size_t i = 0; i < fruits.size(); i++) {
    if (i != 2)
      std::cout << fruits[i] << ", ";
    else
      std::cout << fruits[i] << std::endl;
  }

  try {
    std::cout << fruits[3] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << fruits[-12] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  const Array<int> cArr(5);

  std::cout << cArr[0] << std::endl;

  Array<int> a(5);
  a[0] = 42;

  Array<int> b(a);
  a[0] = 100;

  std::cout << "original a[0]= " << a[0] << ", copy b[0]=" << b[0] << std::endl;
}
