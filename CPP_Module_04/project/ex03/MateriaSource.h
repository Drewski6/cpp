/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 15:28:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource {
public:
  // Constructors , Copy Constructor, Destructor
  MateriaSource(void);
  
  MateriaSource(MateriaSource const &source);
  ~MateriaSource(void);

  // Overloaded Operators
  MateriaSource &operator=(MateriaSource const &rhs);

private:
};

#endif // MATERIASOURCE_H //
