/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:09:49 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/15 15:14:15 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef unsigned long int uintptr_t;

struct Data {
  int data;
};

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
