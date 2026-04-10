/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestreams.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:10:01 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 12:17:38 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ifs("numbers");
	unsigned int dst;
	unsigned int dst2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	std::ofstream ofs("test.out");
	ofs << "i like a whole dawm" << std::endl;
	ofs.close();
}
