/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:48:04 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 20:05:23 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

// LIFO last in first out
// DEQUE used if not stant
//
// T Type of the elements.
		// Aliased as member type stack::value_type.
// Container
// Type of the internal underlying container object where the elements are stored.
// Its value_type shall be T.
// Aliased as member type stack::container_type.

#include <deque>
template <typename T, typename Container = std::deque<T>>
class MutantStack  {
	public:

	private:


// 	It will be implemented in terms of a std::stack.
// It will offer all its member functions, plus an additional feature: iterators.

};

#endif
