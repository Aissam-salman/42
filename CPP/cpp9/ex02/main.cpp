/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:07:30 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/01 08:51:05 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av){
	if (ac < 2 || (av[1] && !*av[1]))
	{
		PmergeMe::err();
		return 1;
	}
	PmergeMe pm = PmergeMe(ac, av);
	pm.sort();
	return 0;
}
