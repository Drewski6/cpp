/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:10:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/15 15:05:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors , Copy Constructor, Destructor
Serializer::Serializer(void){};
Serializer::Serializer(Serializer const &source) { *this = source; };
Serializer::~Serializer(void){};

// Overloaded Operators
Serializer &Serializer::operator=(Serializer const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
};

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
};
