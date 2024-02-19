/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/18 15:55:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
public:
  // Constructors , Copy Constructor, Destructor
  MateriaSource(void);

  MateriaSource(MateriaSource const &source);
  ~MateriaSource(void);

  // Overloaded Operators
  MateriaSource &operator=(MateriaSource const &rhs);

  // Public Methods
  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
  void printMateria(void);

private:
  AMateria *_materias[4];
};
