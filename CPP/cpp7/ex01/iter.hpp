/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:06:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/26 17:41:11 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <string>
#include <iostream>


template <typename T>
void print(T const &val) {
	std::cout << val << std::endl;
}

template <typename T, typename F>
void iter(T *arr, size_t const lengthArr, F callback) {
  for (size_t i = 0; i < lengthArr; i++) {
    callback(arr[i]);
  }
}


#endif


