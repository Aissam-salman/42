/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:12 by salman            #+#    #+#             */
/*   Updated: 2026/04/24 17:21:09 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 *
Implement a class Serializer, which will not be initializable by the user in any way,
with the following static methods:

uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.

Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer to Data.
Write a program to test that your class works as expected.

You must create a non-empty (meaning it has data members) Data structure.
Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.

Do not forget to turn in the files of your Data structure.

*/
#include "Data.hpp"

int main()
{
	Data *linkedList;

	linkedList->pushBack(Data *ptr)
}
