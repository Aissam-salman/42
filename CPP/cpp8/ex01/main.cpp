/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:08:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/27 19:46:18 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

struct Incr {
	int operator()(){
		return ++i;
	}

	static int i ;
};

int Incr::i = 0;

int main()  {
	std::srand(time(0));
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.print();


		std::vector<int> s(100000);
		std::generate(s.begin(), s.end(), Incr());
		
		Span ra = Span(s.begin(), s.end());
		std::cout << ra.shortestSpan() << std::endl;
		std::cout << ra.longestSpan() << std::endl;
		

		Span one = Span(1);
		one.addNumber(12);
		std::cout << one.shortestSpan() << std::endl;
		std::cout << one.longestSpan() << std::endl;
		
	} catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
