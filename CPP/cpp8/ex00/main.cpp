/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:06:20 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 16:09:47 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <set>
#include <vector>

int main() {
  std::cout << "==== VECTOR =====" << std::endl;
  std::vector<int> nbr;
  nbr.push_back(1);
  nbr.push_back(2);
  nbr.push_back(3);
  nbr.push_back(4);
  nbr.push_back(5);
  nbr.push_back(6);
  nbr.push_back(7);
  nbr.push_back(8);
  nbr.push_back(9);

  try {
    ::print(nbr);
    int res = ::easyfind(nbr, 13);
    std::cout << res << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not found: " << e.what() << std::endl;
  }

  std::cout << "==== DEQUE =====" << std::endl;
  std::deque<int> deq;
  deq.push_back(2);
  deq.push_back(3);
  deq.push_back(4);
  deq.push_back(5);
  deq.push_back(6);
  deq.push_back(7);

  try {
    ::print(deq);
    int res = ::easyfind(deq, 4);
    std::cout << "Find: " << res << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not found: " << e.what() << std::endl;
  }

  std::cout << "==== LIST  =====" << std::endl;
  std::list<int> lst;
  lst.push_back(13);
  lst.push_back(14);
  lst.push_back(15);
  lst.push_back(16);
  lst.push_back(17);
  lst.push_back(18);
  lst.push_back(19);
  lst.push_back(20);
  lst.push_back(21);
  lst.push_back(22);
  lst.push_back(23);
  try {
    ::print(lst);
    int res = ::easyfind(lst, 11);
    std::cout << "Find: " << res << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not found: " << e.what() << std::endl;
  }

  std::cout << "==== SET  =====" << std::endl;
  int myI[] = {23, 2434, 54, 5213, 34, 90, 1, 34, 5};

  std::set<int> st(myI, myI + 9);
  try {
    ::print(st);
    int res = ::easyfind(st, 5213);
    std::cout << "Find: " << res << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not found: " << e.what() << std::endl;
  }

  return 0;
}
