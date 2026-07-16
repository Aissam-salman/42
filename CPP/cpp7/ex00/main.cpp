/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:30:23 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/26 13:57:52 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iomanip>
#include <iostream>

int main(void) {
  // int a = 2;
  // int b = 3;
  // ::swap(a, b);
  // std::cout << "a = " << a << ", b = " << b << std::endl;
  // std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  // std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  // std::string c = "chaine1";
  // std::string d = "chaine2";
  // ::swap(c, d);
  // std::cout << "c = " << c << ", d = " << d << std::endl;
  // std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  // std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  std::cout << "\n CUSTOM TEST \n" << std::endl;

  std::cout << "SWAP" << std::endl;
  char a = 'a';
  char b = 'b';
  std::cout << "char-> a= " << a << ", b= " << b << std::endl;
  swap(a, b);
  std::cout << "char-> a= " << a << ", b= " << b << std::endl;

  int c = 12;
  int d = 99;
  std::cout << "int-> c= " << c << ", d= " << d << std::endl;
  swap(c, d);
  std::cout << "int-> c= " << c << ", d= " << d << std::endl;

  float e = 42.22f;
  float f = 29.0f;
  std::cout << std::fixed << std::setprecision(2) << "float-> e= " << e
            << ", f= " << f << std::endl;
  swap(e, f);
  std::cout << std::fixed << std::setprecision(2) << "float-> e= " << e
            << ", f= " << f << std::endl;

  double g = 40.12421;
  double h = 8.8968;
  std::cout << std::fixed << std::setprecision(4) << "double-> g= " << g
            << ", h= " << h << std::endl;
  swap(g, h);
  std::cout << std::fixed << std::setprecision(4) << "double-> g= " << g
            << ", h= " << h << std::endl;

  std::string i = "foo";
  std::string j = "asd";
  std::cout << "string-> i= " << i << ", j= " << j << std::endl;
  swap(i, j);
  std::cout << "string-> i= " << i << ", j= " << j << std::endl;

  std::cout << "MIN" << std::endl;

  std::cout << a << ", " << b << " min -> " << min<char>(a, b) << std::endl;
  std::cout << c << ", " << d << " min -> " << min<int>(c, d) << std::endl;
  std::cout << e << ", " << f << " min -> " << min<float>(e, f) << std::endl;
  std::cout << g << ", " << h << " min -> " << min<double>(g, h) << std::endl;
  std::cout << i << ", " << j << " min -> " << min<std::string>(i, j)
            << std::endl;

  std::cout << "MAX" << std::endl;

  std::cout << a << ", " << b << " max -> " << max<char>(a, b) << std::endl;
  std::cout << c << ", " << d << " max -> " << max<int>(c, d) << std::endl;
  std::cout << e << ", " << f << " max -> " << max<float>(e, f) << std::endl;
  std::cout << g << ", " << h << " max -> " << max<double>(g, h) << std::endl;
  std::cout << i << ", " << j << " max -> " << max<std::string>(i, j)
            << std::endl;

  return 0;
}
