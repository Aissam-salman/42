/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman </var/spool/mail/salman>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:01:25 by salman            #+#    #+#             */
/*   Updated: 2026/04/24 17:12:15 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER
#define SERIALIZER

#include <stdint.h>
#include "Data.hpp"



class Serializer {
private:
  Serializer(void);
  Serializer(const Serializer &src);
  Serializer &operator=(const Serializer &rhs);
  ~Serializer(void);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
