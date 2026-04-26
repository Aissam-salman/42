/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:25:02 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/26 13:58:20 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T> T min(T const &a, T const &b) { return (a <= b ? a : b); }

template <typename>
std::string min(std::string const &a, std::string const &b) {
  int r = a.compare(b);
  if (r == 0)
    return a;
  else if (r > 0)
    return b;
  else
    return a;
}

template <typename T> T max(T const &a, T const &b) { return (a >= b ? a : b); }

template <typename>
std::string max(std::string const &a, std::string const &b) {
  int r = a.compare(b);
  if (r == 0)
    return a;
  else if (r > 0)
    return a;
  else
    return b;
}

#endif
