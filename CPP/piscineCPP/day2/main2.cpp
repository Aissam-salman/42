/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:42:53 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 11:45:35 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// REFERENCE : pointer constant, toujours dereferencer et jamais null

#include <iostream>

int main(void)
{
	int nbOfBalls = 42;

	int *ballPtr = &nbOfBalls;
	int &ballsRef = nbOfBalls;

	std::cout << nbOfBalls << " " << *ballPtr << " " << ballsRef << std::endl;

	*ballPtr = 21;
	std::cout << nbOfBalls << std::endl;
	ballsRef = 84;
	std::cout << nbOfBalls << std::endl;
	return (0);
}
