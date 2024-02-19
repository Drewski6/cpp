/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:28:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 21:38:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors , Copy Constructor, Destructor
MateriaSource::MateriaSource(void) {
  // Initialization of _materias array
  for (int i = 0; i < 4; i++) {
    _materias[i] = NULL;
  }
};

MateriaSource::MateriaSource(MateriaSource const &source) {
  // Initialization of _materias array
  for (int i = 0; i < 4; i++) {
    _materias[i] = NULL;
  }
  *this = source;
};

MateriaSource::~MateriaSource(void) {
  // Delete all active _materias
  for (int i = 0; i < 4; i++) {
    if (_materias[i]) {
      delete _materias[i];
      _materias[i] = NULL;
    }
  }
};

// Overloaded Operators
MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this == &rhs)
    return (*this);
  // clone each _materia item (ie DEEP COPY)
  std::cout << "MateriaSource copy assignment operator" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (rhs._materias[i])
      (*this)._materias[i] = rhs._materias[i]->clone();
  }
  return (*this);
};

// Public Methods
void MateriaSource::learnMateria(AMateria *m) {
  if (m) {
    for (int i = 0; i < 4; i++) {
      if (!_materias[i]) {
        _materias[i] = m;
        return;
      }
    }
  }
};

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (_materias[i]->getType() == type)
      return _materias[i]->clone();
  }
  // "Return 0 if type is unknown"
  return (NULL);
};

// My addition for making evaluations easier :)
void MateriaSource::printMateria(void) {
  for (int i = 0; i < 4; i++) {
    std::cout << "_materias[" << i << "]: " << _materias[i];
    if (_materias[i]) {
      std::cout << " type: " << _materias[i]->getType();
    }
    std::cout << std::endl;
  }
  return;
};
