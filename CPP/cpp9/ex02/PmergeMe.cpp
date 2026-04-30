/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:00:35 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/30 20:05:12 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

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


bool PmergeMe::checkParams(void) {
	//TODO: 
	// check only digit
	// no doublon
	// si len string > 10 depasse int_max sur
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

void PmergeMe::sort(void) {
  std::vector<std::string>::iterator it = this->_params.begin();
  std::vector<std::string>::iterator ite = this->_params.end();
  for (; it != ite; ++it)
    std::cout << *it << std::endl;
	if (!checkParams())
		return this->err();
	//TODO:
	// convertir string en long 
	// controler pas overflow int_max 
	// remplir origin en static_cast<int>
	// call mergeInsert();
}

void PmergeMe::err(void){
	std::cout << "Error" << std::endl;
}
