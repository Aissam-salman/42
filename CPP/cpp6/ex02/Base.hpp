/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:58:47 by salman            #+#    #+#             */
/*   Updated: 2026/04/25 12:29:32 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public:
		virtual ~Base(void);

		Base *generate(void);
		void identify(Base *p);
		void identify(Base &p);
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

#endif
