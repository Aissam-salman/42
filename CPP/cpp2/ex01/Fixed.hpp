/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:08:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 14:58:07 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
	Fixed(int const nb); // convert to fixed point value
  Fixed &operator=(Fixed const &rhs);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _fixedPointValue;
  static int const _bits;
};

#endif
