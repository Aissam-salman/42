/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:25:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/06 16:35:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int main () {
	Sample s;
	Sample *p_s = &s;

	int Sample::*p = NULL;
	void (Sample::*f)(void)const;

	p = &Sample::foo;

	std::cout << "value foo: " << s.foo << std::endl;
	s.*p = 22;
	std::cout << "value foo: " << s.foo << std::endl;
	p_s->*p = 42;
	std::cout << "value foo: " << s.foo << std::endl;

	f = &Sample::bar;

	(s.*f)();
	(p_s->*f)();
	return 0;
}
