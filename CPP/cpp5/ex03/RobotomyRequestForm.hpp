/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:46:27 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/21 16:59:02 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm(void);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
