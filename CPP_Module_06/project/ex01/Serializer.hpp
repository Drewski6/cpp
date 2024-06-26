/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:09:49 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/05 20:36:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"

typedef unsigned long int uintptr_t;

class Serializer {
public:
  // Static Methods
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  // Constructors , Copy Constructor, Destructor
  Serializer(void);
  Serializer(Serializer const &source);
  ~Serializer(void);

  // Overloaded Operators
  Serializer &operator=(Serializer const &rhs);
};
