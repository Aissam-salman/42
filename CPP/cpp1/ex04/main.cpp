/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:05:28 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 20:57:11 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

std::string ft_replace(std::string line, char *s1, char *s2) {
  std::string newLine;

  if (!s1 && !s2)
    return (line);
  std::string s = s1;
  std::string st = s2;
  size_t match;
  size_t pos = 0;
  while ((match = line.find(s1, pos)) != std::string::npos) {
    if (match != pos)
      newLine.append(line, pos, match);
    newLine.append(s2);
    pos = match + s.length();
  }
  newLine.append(line, pos);
  return (newLine);
}

int main(int ac, char **av) {
  std::ifstream ifs;
  std::ofstream ofs;
  size_t extensionPos;
  std::string line;
  std::string path = av[1];
  std::string destPath;
  std::string modifLine;

  if (ac != 4) {
    std::cerr << "Error: ./loser_sed <filename> <s1> <s2>" << std::endl;
    return (1);
  }
  if (path.empty()) {
    std::cerr << "Error: enter valid filename!" << std::endl;
    return (1);
  }
  extensionPos = path.find_last_of('.');
  destPath = path.substr(0, extensionPos).append(".replace");
  ifs.open(av[1], std::ifstream::in);
  if (ifs.is_open()) {
    ofs.open(destPath.c_str(), std::ofstream::out);
    if (ofs.is_open()) {
      while (std::getline(ifs, line, '\n')) {
        modifLine = ft_replace(line, av[2], av[3]);
        ofs << modifLine << "\n";
      }
      ofs.close();
    } else {
      std::cerr << "Error: open & create fileout" << std::endl;
    }
    ifs.close();
  } else {
    std::cerr << "Error: open filein ->" << av[1] << std::endl;
  }
  return (0);
}
