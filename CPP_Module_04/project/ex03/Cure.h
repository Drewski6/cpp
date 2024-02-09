/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:22 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 15:29:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

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

#endif // CURE_H //
