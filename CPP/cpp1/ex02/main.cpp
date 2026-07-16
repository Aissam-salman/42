/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:15:37 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 15:23:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string A = "HI THIS IS BRAIN";
	std::string *stringPTR = &A;
	std::string &stringREF = A;

	std::cout << std::endl;
	std::cout << "MEMORY ADDRESS" << std::endl;
	std::cout << &A << " " << stringPTR << " " << &stringREF << " " << std::endl;
	std::cout << std::endl;
	
	std::cout << "VALUE OF STRING" << std::endl;
	std::cout << A << " " << *stringPTR << " " << stringREF << " " << std::endl;

	return (0);
}
