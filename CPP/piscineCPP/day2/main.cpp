/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:00:02 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/09 17:23:14 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student {
private:
  std::string _login;

public:
  Student(std::string login) : _login(login) {
    std::cout << "Student: " << this->_login << " is born" << std::endl;
  }

  ~Student() {
    std::cout << "Student: " << this->_login << " died" << std::endl;
  }
};

int main()
{
	
}
