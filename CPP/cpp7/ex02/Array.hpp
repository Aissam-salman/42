/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:42:02 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/26 19:13:44 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>

template <typename T> class Array {
public:
  Array(void) : _size(1) { this->_arr = new T[1](); }

  Array(unsigned int n) : _size(n) { this->_arr = new T[n](); }

  Array(Array<T> const &src) : _size(src._size) {
    this->_arr = new T[src._size]();
    for (size_t i = 0; i < src._size; i++) {
      this->_arr[i] = src._arr[i];
    }
  }

  Array<T> &operator=(Array<T> const &rhs) {
    if (this != &rhs) {
      T *tmp = new T[rhs.size()];
      delete[] this->_arr;
      for (size_t i = 0; i < rhs.size(); i++)
        tmp[i] = rhs._arr[i];
      this->_arr = tmp;
    }
    return *this;
  }

  ~Array(void) {
    delete[] this->_arr;
    this->_arr = 0;
  }

  size_t size(void) { return this->_size; }

  T &operator[](int const index) {
    if (static_cast<size_t>(index) < 0 ||
        static_cast<size_t>(index) >= this->_size)
      throw std::exception();
    else
      return this->_arr[index];
  }

  T &operator[](int const index) const {
    if (static_cast<size_t>(index) < 0 ||
        static_cast<size_t>(index) >= this->_size)
      throw std::exception();
    else
      return this->_arr[index];
  }

private:
  T *_arr;
  size_t _size;
};

#endif
