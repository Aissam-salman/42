/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:50:47 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 19:51:54 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "top: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "size: " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  // std::cout << "like lst = mutanstack" << std::endl;
  //  std::list<int> lst;
  //  lst.push_back(5);
  //  lst.push_back(17);
  //  std::cout << "back: " << lst.back() << std::endl;
  //  lst.pop_back();
  //  std::cout << "size: " << lst.size() << std::endl;
  //  lst.push_back(3);
  //  lst.push_back(5);
  //  lst.push_back(737);
  //  lst.push_back(0);
  //
  //  std::list<int>::iterator itt = lst.begin();
  //  std::list<int>::iterator itte = lst.end();
  //  ++itt;
  //  --itte;
  //  while (itt != itte) {
  //    std::cout << *itt << std::endl;
  //    ++itt;
  //  }
  //
  //  std::stack<int, std::list<int> > e(lst);

  MutantStack<std::string, std::list<std::string> > sstack;

  sstack.push("foo");
  sstack.push("loo");

  MutantStack<std::string, std::list<std::string> >::iterator i =
  sstack.begin(); MutantStack<std::string, std::list<std::string> >::iterator
  iter = sstack.end();

  for (; i != iter; ++i) {
  	std::cout << *i << std::endl;
  }

  return 0;
}
