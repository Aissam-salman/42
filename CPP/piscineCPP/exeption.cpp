/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeption.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:13:24 by salman            #+#    #+#             */
/*   Updated: 2026/04/20 16:03:15 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stdexcept>
#include <iostream>

void test1()
{
	try {
		if (1)
		{
			throw std::exception();
		}
		else
		{
			std::cout << "somestuff" << std::endl;
			// do some stuff
		}
	} catch (std::exception e) {
		// handle error
		e.what();
	}
}

void test2()
{
	if (1)
	{
		throw std::exception();
	}
	else
	{
		// some stuff
	}
}

void test3()
{
	try
	{
		test2();
	} catch (std::exception &e)
	{
		// hanlde error
	}
}

void test4()
{
	class CUSTOMException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Pb with something");
			}
	};

	try {
		test3();
	}
	catch (CUSTOMException &e){
		// handle custom error
	}
	catch (std::exception &e)
	{
		// handle error
	}
}
