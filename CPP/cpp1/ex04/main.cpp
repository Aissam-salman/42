/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:05:28 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 20:46:33 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ./loser_sed <filename> <s1> <s2> (two string)
 *
 *
 * open filename and copy to filename.replace, and replace every s1 with s2
 */
#include <fstream>
#include <iostream>
#include <string>
// #include <system_error>

int main(int ac, char **av) {
  if (ac != 4) {
    std::cerr << "Error: ./loser_sed <filename> <s1> <s2>" << std::endl;
    return (1);
  }
  if (!av[1] || !av[1][0]) {
    std::cerr << "Error: enter valid filename!" << std::endl;
    return (1);
  }
  std::ifstream ifs(av[1], std::ifstream::in);


  return (0);
}

// int main()
// {
// 	//read
// 	std::ifstream ifs("numbers");
// 	unsigned int dst;
// 	unsigned int dst2;
// 	ifs >> dst >> dst2;
//
// 	std::cout << dst << " " << dst2 << std::endl;
// 	ifs.close();
//
// 	// write
// 	std::ofstream ofs("test.out");
// 	ofs << "i like a whole dawm" << std::endl;
// 	ofs.close();
// }
