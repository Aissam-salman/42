/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:57:53 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 12:09:48 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student {
private:
  std::string _login;

public:
  Student(std::string const &login) : _login(login) {}
  std::string &getLoginRef() { return this->_login; }
  std::string const &getLoginRefConst() const { return this->_login; }
	std::string *getLoginPtr(){ return &(this->_login);}
	std::string const *getLoginPtrConst() const { return &(this->_login);}
};

int main()
{
	Student st = Student("foo");
	Student st2 = Student("boo");

	std::cout << st.getLoginRefConst() << " " << st2.getLoginRefConst() << std::endl;
	std::cout << *(st.getLoginPtrConst()) << " " << *(st2.getLoginPtrConst()) << std::endl;

	st.getLoginRef() = "baa";
	std::cout << st.getLoginRefConst() << std::endl;

	*(st.getLoginPtr()) = "asd";
	std::cout << st.getLoginRefConst() << std::endl;
}
