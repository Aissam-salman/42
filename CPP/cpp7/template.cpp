/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:40:31 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/25 19:55:06 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename U> class Pair {
public:
  Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Generic template" << std::endl;
  }
  ~Pair<T, U>() {}

  T const &fst(void) const { return this->_lhs; }
  U const &snd(void) const { return this->_rhs; }

private:
  T const &_lhs;
  U const &_rhs;

  Pair<T, U>(void);
};

// specialisation partial

template <typename U> class Pair<int, U> {
public:
  Pair<int, U>(int lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Int partial spe template" << std::endl;
  }
  ~Pair<int, U>() {}

  int fst(void) const { return this->_lhs; }
  U const &snd(void) const { return this->_rhs; }

private:
  int _lhs;
  U const &_rhs;

  Pair<int, U>(void);
};

// specialization complet
template <> class Pair<bool, bool> {
public:
  Pair<bool, bool>(bool lhs, bool rhs) {
    std::cout << "Complet spe template" << std::endl;
    this->_n = 0;
    this->_n |= static_cast<int>(lhs) << 0;
    this->_n |= static_cast<int>(rhs) << 1;
  }

  ~Pair<bool, bool>() {}

  bool fst(void) const { return this->_n & 0x01; }
  bool snd(void) const { return this->_n & 0x02; }

private:
  int _n;

  Pair<bool, bool>(void);
};

int main() { return 0; }
