/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:04:43 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/14 21:09:31 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* a,b,c Triangle
 * point to check
 * return true if inside the triangle
 * if point in vertex or edge or outside return false
 */
bool bsp(Point const a, Point const b, Point const c, Point const point){
	//ab composante z du produit vectoriel
	int z = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX());
	if (d > 0)
	return (false);
}
