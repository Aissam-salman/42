/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:46:54 by salman            #+#    #+#             */
/*   Updated: 2026/04/23 16:48:27 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac !=2)
	{
		std::cerr << "Error: need param" << std::endl;

		return 1;
	}

	ScalarConverter::convert(av[1]);
	return 0;
}
