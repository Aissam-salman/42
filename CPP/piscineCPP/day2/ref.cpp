/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:50:25 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 11:57:46 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void byPtr(std::string *str)
{
	*str += " and ponies";
}

void byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;
}

void byRef(std::string &str)
{
	str += " and ponies";
}

void byRefConst(std::string const &str)
{
	std::cout << str << std::endl;
}

int main()
{
	std::string str = "i like butter";
	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);
	str = "i like choco";
	byRef(str);
	byRefConst(str);
	return (0);
}

