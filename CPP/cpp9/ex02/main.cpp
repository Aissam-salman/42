/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:07:30 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/30 19:24:51 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av){
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	PmergeMe pm = PmergeMe(ac, av);
	pm.sort();
	return 0;
}
