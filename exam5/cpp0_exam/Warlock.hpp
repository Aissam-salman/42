/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:12:27 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/11 14:32:08 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#pragma once

class Warlock {
	private:
		std::string name;
		std::string title;
		Warlock(void);
		Warlock(const Warlock &src);
		Warlock &operator=(const Warlock &rhs);

	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);

		std::string &getName(void) const;
		std::string &getTitle(void) const;

		void setTitle(const std::string &title);

		void introduce(void) const;
};
