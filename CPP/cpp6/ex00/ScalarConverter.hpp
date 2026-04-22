/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:33:21 by salman            #+#    #+#             */
/*   Updated: 2026/04/22 17:35:20 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter(void);
	static void convert(std::string str);

};

#endif 
