/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:02:59 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 19:19:34 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <vector>

class Span {
	public:
		Span(unsigned int n);
		Span(const Span &src);
		Span(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		Span &operator=(const Span &rhs);
		~Span(void);

		void addNumber(int nbr);
		void print(void);

		int shortestSpan(void) ;
		
		int longestSpan(void) const;

	private:
		Span(void);
		std::vector<int> _span;
		unsigned int _N;
		std::size_t _size;
};

#endif
