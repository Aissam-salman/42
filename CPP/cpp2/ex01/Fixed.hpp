/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:08:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 15:23:38 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
	Fixed(int const nb);
	Fixed(float const ft);
  Fixed &operator=(Fixed const &rhs);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
  int _fixedPointValue;
  static int const _bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
#endif
