/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:57:53 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/01 09:27:44 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <string>
#include <vector>

class PmergeMe {
public:
  PmergeMe(void);
  PmergeMe(int ac, char **av);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &rhs);
  ~PmergeMe(void);

  void sort(void);
	static void err(void);

private:
	//TODO: maybe _size need
  std::vector<std::string> _params;
	double _timeStartD;
	double _timeEndD;
	double _timeStartV;
	double _timeEndV;
  std::vector<int> _originV;
	std::vector<int> _orphelinV;
  std::deque<int> _originD;
	std::deque<int> _orphelinD;
	void printEnd();
  bool checkParams(void);
	bool prepare(void);
	bool isSorted(void);
	std::vector<int> mergeInsertV(std::vector<int> lst);
	std::deque<int> mergeInsertD(std::deque<int> lst);
};

#endif
