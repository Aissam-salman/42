/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:07:10 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 16:08:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>

template <typename T> int easyfind(T &container, int const needle) {

  typename T::iterator it =
      std::find(container.begin(), container.end(), needle);
  if (it != container.end())
    return *it;
  else
    throw std::exception();
}

template <typename T> void print(T const &container) {
  typename T::const_iterator it = container.begin();
  typename T::const_iterator ite = container.end();
  for (; it != ite; ++it) {
    std::cout << *it;
    typename T::const_iterator next = it;
    ++next;
    if (next != ite)
      std::cout << ", ";
  }
  std::cout << std::endl;
}

#endif
