/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:00:35 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/01 09:28:35 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <set>
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {
  for (int i = 1; i < ac; i++)
    this->_params.push_back(av[i]);
}

PmergeMe::PmergeMe(const PmergeMe &src) {
  std::vector<std::string>::const_iterator it = src._params.begin();
  std::vector<std::string>::const_iterator ite = src._params.end();
  for (; it != ite; ++it) {
    this->_params.push_back(*it);
  }
  std::vector<int>::const_iterator it1 = src._origin.begin();
  std::vector<int>::const_iterator ite1 = src._origin.end();
  for (; it1 != ite1; ++it1) {
    this->_origin.push_back(*it1);
  }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    this->_origin.clear();
    this->_params.clear();
    std::vector<std::string>::const_iterator it = rhs._params.begin();
    std::vector<std::string>::const_iterator ite = rhs._params.end();
    for (; it != ite; ++it) {
      this->_params.push_back(*it);
    }
    std::vector<int>::const_iterator it1 = rhs._origin.begin();
    std::vector<int>::const_iterator ite1 = rhs._origin.end();
    for (; it1 != ite1; ++it1) {
      this->_origin.push_back(*it1);
    }
  }
  return *this;
}

bool onlyDigit(std::string item) {
  for (size_t i = 0; i < item.length(); i++) {
    if (!std::isdigit(item[i]))
      return false;
  }
  return true;
}

bool PmergeMe::checkParams(void) {
  std::vector<std::string>::const_iterator it = this->_params.begin();
  std::vector<std::string>::const_iterator ite = this->_params.end();
  for (; it != ite; ++it) {
    if (it->empty() || !onlyDigit(*it) || it->length() > 10)
      return false;
  }
  std::set<std::string> tmp =
      std::set<std::string>(this->_params.begin(), this->_params.end());
  if (this->_params.size() != tmp.size())
    return false;
  return true;
}

// void mergeInsert(void){}
// TODO:
// Fonction tri(liste_input) :
//     Si taille(liste_input) < 2 :
//         retourner liste_input
//
//     // 1. Pairage et séparation
//     Paires = créer_paires(liste_input)
//     Gagnants = extraire_gagnants(Paires)
//     Perdants = extraire_perdants(Paires)
//
//     // 2. La récursivité
//     Main_Chain = tri(Gagnants) // <--- C'est ici que la magie opère
//
//     // 3. Insertion des perdants (La partie non récursive)
//     Tant que Pend n'est pas vide :
//         // Logique de Jacobsthal + Binary Search
//         ... insérer perdant dans Main_Chain ...
//
//     retourner Main_Chain
double getTime(void) {
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return (double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000;
}

void PmergeMe::printEnd(void) {
	//FIX: move this after algo
  this->_timeEnd = getTime();
	double time = this->_timeEnd - this->_timeStart;

  std::vector<std::string>::const_iterator it = this->_params.begin();
  std::vector<std::string>::const_iterator ite = this->_params.end();
  std::cout << "Before: ";
  for (; it != ite; ++it) {
    std::cout << *it;
    std::vector<std::string>::const_iterator next = it;
    ++next;
    if (next != ite)
      std::cout << " ";
  }
  std::cout << std::endl;
  if (this->_params.size() == 1) {
    std::cout << "Before: " << *this->_params.begin() << std::endl;
  } else {
    std::vector<int>::iterator it1 = this->_origin.begin();
    std::vector<int>::iterator ite1 = this->_origin.end();
    std::cout << "Before: ";
    for (; it1 != ite1; ++it1) {
      std::cout << *it1;
      std::vector<int>::iterator next = it1;
      ++next;
      if (next != ite1)
        std::cout << " ";
    }
  }
  std::cout << "Time to process a range of " << this->_params.size()
            << " elements with std::vector: " << std::fixed << std::setprecision(8) << time << " ms"
            << std::endl;
  std::cout << "Time to process a range of " << std::fixed <<  std::setprecision(8) << this->_params.size()
            << " elements with std::deque: " << time << " ms"
            << std::endl;
}

bool PmergeMe::prepare(void) {
  std::vector<std::string>::const_iterator it = this->_params.begin();
  std::vector<std::string>::const_iterator ite = this->_params.end();

	for (; it != ite; ++it) {
		long r = std::strtol(*it, NULL);
		if (r > INT_MAX || r < 0)
			return false;
	}
	
	return true;

}

void PmergeMe::sort(void) {
  this->_timeStart = getTime();
  if (!this->checkParams())
    return this->err();
  if (this->_params.size() == 1)
    this->printEnd();
	if (!this->prepare())
    return this->err();
  // TODO:
  //  convertir string en long
  //  controler pas overflow int_max
  //  remplir origin en static_cast<int>
  //  call mergeInsert();
}

void PmergeMe::err(void) { std::cout << "Error" << std::endl; }
