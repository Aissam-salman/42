/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 19:00:35 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/01 20:06:48 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <set>
#include <sys/time.h>
#include <utility>
#include <vector>

PmergeMe::PmergeMe()
    : _timeStartD(0), _timeEndD(0), _timeStartV(0), _timeEndV(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av)
    : _timeStartD(0), _timeEndD(0), _timeStartV(0), _timeEndV(0) {
  for (int i = 1; i < ac; i++)
    this->_params.push_back(av[i]);
}

PmergeMe::PmergeMe(const PmergeMe &src) {
  std::vector<std::string>::const_iterator it = src._params.begin();
  std::vector<std::string>::const_iterator ite = src._params.end();
  for (; it != ite; ++it) {
    this->_params.push_back(*it);
  }
  std::vector<int>::const_iterator it1 = src._originV.begin();
  std::vector<int>::const_iterator ite1 = src._originV.end();
  for (; it1 != ite1; ++it1) {
    this->_originV.push_back(*it1);
    this->_originD.push_back(*it1);
  }
  this->_timeStartD = src._timeStartD;
  this->_timeEndD = src._timeEndD;
  this->_timeStartV = src._timeStartV;
  this->_timeEndV = src._timeEndV;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    this->_originV.clear();
    this->_originD.clear();
    this->_params.clear();
    std::vector<std::string>::const_iterator it = rhs._params.begin();
    std::vector<std::string>::const_iterator ite = rhs._params.end();
    for (; it != ite; ++it) {
      this->_params.push_back(*it);
    }
    std::vector<int>::const_iterator it1 = rhs._originV.begin();
    std::vector<int>::const_iterator ite1 = rhs._originV.end();
    for (; it1 != ite1; ++it1) {
      this->_originV.push_back(*it1);
      this->_originD.push_back(*it1);
    }
    this->_timeStartD = rhs._timeStartD;
    this->_timeEndD = rhs._timeEndD;
    this->_timeStartV = rhs._timeStartV;
    this->_timeEndV = rhs._timeEndV;
  }
  return *this;
}

bool onlyDigit(std::string const &item) {
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

double getTime(void) {
  struct timeval tv;

  if (gettimeofday(&tv, NULL) == -1)
    return (-1);
  return (double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000;
}

void PmergeMe::printEnd(void) {
  double timeV = this->_timeEndV - this->_timeStartV;
  double timeD = this->_timeEndD - this->_timeStartD;

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
    std::cout << "After: " << *this->_params.begin() << std::endl;
  } else {
    std::vector<int>::const_iterator it1 = this->_sortedV.begin();
    std::vector<int>::const_iterator ite1 = this->_sortedV.end();
    std::cout << "After: ";
    for (; it1 != ite1; ++it1) {
      std::cout << *it1;
      std::vector<int>::const_iterator next = it1;
      ++next;
      if (next != ite1)
        std::cout << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "Time to process a range of " << this->_params.size()
            << " elements with std::vector: " << std::fixed
            << std::setprecision(8) << timeV << " ms" << std::endl;
  std::cout << "Time to process a range of " << std::fixed
            << std::setprecision(8) << this->_params.size()
            << " elements with std::deque: " << timeD << " ms" << std::endl;
}

bool PmergeMe::prepare(void) {
  std::vector<std::string>::iterator it = this->_params.begin();
  std::vector<std::string>::iterator ite = this->_params.end();

  for (; it != ite; ++it) {
    long r = strtol(it->c_str(), NULL, 10);
    if (r > INT_MAX || r < 0)
      return false;
    this->_originV.push_back(static_cast<int>(r));
    this->_originD.push_back(static_cast<int>(r));
  }
  return true;
}


void PmergeMe::sort(void) {
  if (!this->checkParams()) {
    PmergeMe::err();
    return;
  }
  if (this->_params.size() == 1) {
    this->printEnd();
    return;
  }
  if (!this->prepare()) {
    PmergeMe::err();
    return;
  }
  if (this->isSorted(this->_originV)) {
    std::cout << "Already sort" << std::endl;
    this->printEnd();
    return;
  }
  this->_timeStartV = getTime();
  this->_sortedV = this->mergeInsertV(this->_originV);
  this->_timeEndV = getTime();

  this->_timeStartD = getTime();
  this->mergeInsertD(this->_originD);
  this->_timeEndD = getTime();
  this->printEnd();
  if (this->isSorted(this->_sortedV))
    std::cout << "WINNNN !!!" << std::endl;
}

std::vector< std::pair<int, int> > createPair(const std::vector<int> &lst,
                                            std::vector<int> &orp) {
  std::vector< std::pair<int, int> > pair;
  for (size_t i = 0; i + 1 < lst.size(); i += 2) {
    int a = lst[i];
    int b = lst[i + 1];
    if (a > b)
      pair.push_back(std::make_pair(b, a));
    else
      pair.push_back(std::make_pair(a, b));
  }
  if (lst.size() % 2 != 0)
    orp.push_back(lst.back());
  return pair;
}

std::vector<int> extractWinners(const std::vector< std::pair<int, int> > &pairs) {
  std::vector<int> win;
  std::vector< std::pair<int, int> >::const_iterator it = pairs.begin();
  std::vector< std::pair<int, int> >::const_iterator ed = pairs.end();
  for (; it != ed; ++it)
    win.push_back(it->second);
  return win;
}

std::vector<int> extractLosers(const std::vector<int> &mainChain, const std::vector< std::pair<int, int> > &pairs) {
  std::vector<int> losers;
  losers.reserve(mainChain.size());
  for (size_t i = 0; i < mainChain.size(); i++) {
    for (size_t j = 0; j < pairs.size(); j++) {
      if (pairs[j].second == mainChain[i]) {
        losers.push_back(pairs[j].first);
        break;
      }
    }
  }
  return losers;
}

std::vector<int> jacobsthal(const int &n) {
  std::vector<int> jacob;
  jacob.push_back(1);
  jacob.push_back(3);
  while (jacob.back() < n)
  {
    int next = jacob.back() + 2 * jacob[jacob.size() - 2];
    jacob.push_back(next);
  }
  return jacob;
}

std::vector<int> generateOrder(const int &loserLen) {
  std::vector<int> order;

  if (loserLen == 0)
    return order;

  order.push_back(0);

  if (loserLen > 1) {
    std::vector<int> jacobSuite = jacobsthal(loserLen);
    int prevIndex = 1;
    for (size_t i = 0; i < jacobSuite.size(); ++i) {
      int curJ = jacobSuite[i];
      for (int k = (curJ  < loserLen ? curJ : loserLen - 1); k >= prevIndex; --k) {
        if (k < loserLen)
          order.push_back(k);
      }
      prevIndex = curJ + 1;
      if (prevIndex >= loserLen)
        break;
    }
  }

  return order;
}

std::vector<int>::iterator binarySearch(std::vector<int>::iterator &start,
                                        std::vector<int>::iterator &end,
                                        const int val) {
  while (start != end) {
    std::vector<int>::iterator mid = start + (std::distance(start, end) / 2);
    if (*mid < val)
      start = ++mid;
    else
      end = mid;
  }
  return start;
}

int findPairsOfLower(std::vector< std::pair<int, int> >::iterator begin, std::vector< std::pair<int, int> >::iterator end, const int &val) {
	for (; begin != end; ++begin) {
		if (begin->first == val)
			return begin->second;
	}
	return -1;
}

std::vector<int> PmergeMe::mergeInsertV(std::vector<int> &lst) {
  if (lst.size() < 2)
    return lst;
	std::vector<int> orp;
	orp.reserve(1);
  std::vector< std::pair<int, int> > pairs;
	pairs = createPair(lst, orp);
  std::vector<int> winners;
	winners = extractWinners(pairs);
  std::vector<int> mainChain;
	mainChain = this->mergeInsertV(winners);
  std::vector<int> losers;
  losers.reserve(mainChain.size());
  losers = extractLosers(mainChain, pairs);
  std::vector<int> order;
	order = generateOrder(losers.size());
	mainChain.insert(mainChain.begin(), losers[0]);
  for (size_t i = 1; i < order.size(); i++) {
    int v = losers[order[i]];
    int maxP = findPairsOfLower(pairs.begin(), pairs.end(), v);
    std::vector<int>::iterator ma =
        std::find(mainChain.begin(), mainChain.end(), maxP);
    std::vector<int>::iterator it =
        std::lower_bound(mainChain.begin(), ma, v);
    mainChain.insert(it, v);
  }
	std::vector<int>::iterator o = orp.begin();
	std::vector<int>::iterator g = orp.end();
	for (; o != g; ++o) {
      std::vector<int>::iterator it =
          std::lower_bound(mainChain.begin(), mainChain.end(), *o);
      mainChain.insert(it, *o);
	}
  return mainChain;
}

std::deque<int> PmergeMe::mergeInsertD(std::deque<int> &lst) { return lst; }

void PmergeMe::err(void) { std::cout << "Error" << std::endl; }
