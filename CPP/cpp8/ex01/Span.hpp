/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:02:59 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 17:09:04 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
	public:
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span(void);

		void addNumber(int nbr);

		int shortestSpan(void) const;
		int longestSpan(void) const;

	private:
		Span(void);
		unsigned int N;

};


#endif
