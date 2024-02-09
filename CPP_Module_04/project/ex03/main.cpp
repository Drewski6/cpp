/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 18:14:15 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"
#include "Character.h"
#include "MateriaSource.h"

int main() {

  {
    // AMateria
    // AMateria mat;
    Ice ice;
  }

  // {
  //   // Example from subject:
  //   IMateriaSource* src = new MateriaSource();
  //   src->learnMateria(new Ice());
  //   src->learnMateria(new Cure());
  //
  //   ICharacter* me = new Character("me");
  //
  //   AMateria* tmp;
  //   tmp = src->createMateria("ice");
  //   me->equip(tmp);
  //   tmp = src->createMateria("cure");
  //   me->equip(tmp);
  //
  //   ICharacter* bob = new Character("bob");
  //
  //   me->use(0, *bob);
  //   me->use(1, *bob);
  //
  //   delete bob;
  //   delete me;
  //   delete src;
  //
  //   // Expected Output:
  //   // * shoots an ice bolt at bob *$
  //   // * heals bob's wounds *$
  // }

  return 0;
}
