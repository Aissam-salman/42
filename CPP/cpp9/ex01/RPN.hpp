/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:59:38 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/29 15:04:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <stack>

class RPN {
	public:
		RPN(std::string line);
		RPN(const RPN &src);
		RPN &operator=(const  RPN &rhs);
		~RPN(void);

		void run(void);

	private:
		RPN(void);
		bool parsing();
		void compute();
		std::string _line;
		std::stack<std::string> _c;
		int _size;
};

#endif
