/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:31:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

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
