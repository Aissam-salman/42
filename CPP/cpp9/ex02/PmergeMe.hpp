/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:57:53 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/30 19:58:11 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>

class PmergeMe {
public:
  PmergeMe(void);
  PmergeMe(int ac, char **av);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &rhs);
  ~PmergeMe(void);

  bool checkParams(void);
  void sort(void);
	static void err(void);

private:
	//TODO: maybe _size need
  std::vector<int> _origin;
  std::vector<std::string> _params;
};

#endif
