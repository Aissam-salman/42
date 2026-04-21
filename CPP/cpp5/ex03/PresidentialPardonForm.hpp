/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:46:27 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/21 16:58:55 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP 
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
