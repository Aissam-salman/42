/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 15:10:16 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/26 17:41:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <cstdio>
#include <iostream>

void ft_db(int &z) { z *= 2; }

void prt(const std::string &msg)
{
	std::cout << msg << std::endl;
}

int main(void) {

  int arr[5] = {1, 2, 3, 4, 5};

  ::iter(arr, 5, ft_db);

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << std::endl;
  }

	std::string const list[5] = {"pomme", "nan", "banane", "flex", "foo"};
	::iter(list, 5 , prt);


	// take template
	::iter(list, 5, ::print<std::string>);
}
