/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:08:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/12 15:10:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
  Fixed &operator=(Fixed const &rhs);
  ~Fixed(void);

private:

};

#endif
