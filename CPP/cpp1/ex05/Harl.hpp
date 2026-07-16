/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:38:05 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/11 18:22:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <string>


class Harl {
public:
  Harl(void);
  ~Harl(void);

  void complain(std::string level);

private:
  void _debug(void);
  void _info(void);
  void _warning(void);
  void _error(void);
};

#endif
