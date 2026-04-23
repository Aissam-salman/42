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

#include <cmath>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac !=2)
		return 1;

	ScalarConverter::convert(av[1]);
	return 0;
}
