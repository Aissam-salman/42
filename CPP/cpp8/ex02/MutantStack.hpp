/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:48:04 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 20:06:16 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack(void) : std::stack<T, Container>() {}

  MutantStack(const MutantStack<T, Container> &src)
      : std::stack<T, Container>(src) {}

  virtual ~MutantStack(void) {}

  MutantStack<T, Container> &operator=(const MutantStack<T, Container> &rhs) {
    if (this != &rhs)
      std::stack<T, Container>::operator=(rhs);
    return *this;
  }

  typedef typename std::stack<T, Container>::container_type::iterator iterator;
  typedef typename std::stack<T, Container>::container_type::const_iterator
      const_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
};

#endif
