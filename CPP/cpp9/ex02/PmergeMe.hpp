/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:57:53 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/01 19:54:16 by alamjada         ###   ########.fr       */
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
	template <typename T>
	bool isSorted(T container) {
		typename T::const_iterator start = container.begin();
		typename T::const_iterator end = container.end();

		typename T::const_iterator next = start;
		while (++next != end) {
			if (*next < *start)
			return false;
			++start;
		}
		return true;
	}

private:
	//TODO: maybe _size need
  std::vector<std::string> _params;
	double _timeStartD;
	double _timeEndD;
	double _timeStartV;
	double _timeEndV;
  std::vector<int> _originV;
	std::vector<int> _sortedV;
	std::vector<int> _sortedD;
  std::deque<int> _originD;
	void printEnd();
  bool checkParams(void);
	bool prepare(void);
	bool isSorted(void);
	std::vector<int> mergeInsertV(std::vector<int> &lst);
	std::deque<int> mergeInsertD(std::deque<int> &lst);
};

#endif
