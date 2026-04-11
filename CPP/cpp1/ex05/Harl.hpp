/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:38:05 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/11 17:13:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
	Harl(void);
	~Harl(void);

	void complain(std::string level) const;

private:
	void _debug(void) const;
	void _info(void) const;
	void _warning(void) const;
	void _error(void) const;
};

#endif
