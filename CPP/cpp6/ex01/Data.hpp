/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:12:21 by salman            #+#    #+#             */
/*   Updated: 2026/04/24 17:39:50 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
public:
  Data();
  Data(const Data &src);
  Data &operator=(const Data &rhs);
  ~Data();


  void pushBack(const std::string &value);
  void pushFirst(const std::string &value);
  void printData(void) const;

private:
	struct Node {
			std::string _value;
			Node *_next;

			Node(const std::string &value);
	};

  Node *_head;
  Node *_tail;
	int _size;

	void _clear(void);
};

#endif
