/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:22 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:30:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure {
public:
  // Constructors , Copy Constructor, Destructor
  Cure(void);

  Cure(Cure const &source);
  ~Cure(void);

  // Overloaded Operators
  Cure &operator=(Cure const &rhs);

private:
};
