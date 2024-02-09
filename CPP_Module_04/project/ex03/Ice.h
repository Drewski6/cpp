/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:48 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 18:14:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria {
public:
  // Constructors , Copy Constructor, Destructor
  Ice(void);
  
  Ice(Ice const &source);
  ~Ice(void);

  // Overloaded Operators
  Ice &operator=(Ice const &rhs);

private:
};

#endif // ICE_H //
