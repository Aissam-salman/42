/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:03:11 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 20:34:19 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const &src);
		Point& operator=(Point const &rhs);
		~Point();

		Fixed const getX(void) const;
		Fixed const getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};


#endif
