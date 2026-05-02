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

typedef std::deque<std::pair<int, int> > dequePair;

class PmergeMe {
public:
  PmergeMe(void);
  PmergeMe(int ac, char **av);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &rhs);
  ~PmergeMe(void);

  void sort(void);
  static void err(void);

  template <typename T> bool isSorted(T container) {
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
  std::vector<std::string> _params;
  double _timeStartD;
  double _timeEndD;
  double _timeStartV;
  double _timeEndV;
  std::vector<int> _originV;
  std::vector<int> _sortedV;
  std::deque<int> _sortedD;
  std::deque<int> _originD;
  std::deque<int> _orpD;
  void printEnd();
  bool checkParams(void);
  bool prepare(void);
  bool isSorted(void);
  std::vector<int> mergeInsertV(std::vector<int> &lst);
  std::deque<int> mergeInsertD(std::deque<int> &lst);

  /*-----------------------------------------------------------------
   *
   *  TEMPLATE
   *
   ------------------------------------------------------------------*/
  template <typename T, typename C> T createPairs(const C &lst, C &orp) {
    T pair;
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

  template <typename T, typename C> T extractWinners(const C &pairs) {
    T win;
    typename C::const_iterator it = pairs.begin();
    typename C::const_iterator ed = pairs.end();
    for (; it != ed; ++it)
      win.push_back(it->second);
    return win;
  }

  template <typename T, typename C> T extractLosers(const C &pairs) {
    T losers;
    typename C::const_iterator it = pairs.begin();
    typename C::const_iterator ed = pairs.end();
    for (; it != ed; ++it)
      losers.push_back(it->first);
    return losers;
  }
};

#endif
