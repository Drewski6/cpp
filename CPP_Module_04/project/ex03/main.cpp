/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 22:04:26 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {

  {
    std::cout << "\n===== Test 1 : Subject =====\n" << std::endl;
    // Example from subject:
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // Expected Output:
    // * shoots an ice bolt at bob *$
    // * heals bob's wounds *$
  }

  {
    std::cout << "\n===== Test 2: AMateria Tests : Ice =====\n" << std::endl;
    // Tests for creating Ice via clone method
    // NOTE: More extensive materia testing is in Character tests
    Ice ice;
    ICharacter *me = new Character("me");
    // Should return a new instance of ice object.
    Ice *newIce = ice.clone();

    std::cout << "newIce: " << newIce << std::endl;

    delete newIce;
    delete me;
  }

  {
    std::cout << "\n===== Test 3: AMateria Tests : Cure =====\n" << std::endl;
    // Tests for creating Cure via clone method
    // NOTE: More extensive materia testing is in Character tests
    Cure cure;
    // Should return a new instance of cure object.
    Cure *newCure = cure.clone();

    std::cout << "newCure: " << newCure << std::endl;

    delete newCure;
  }

  {
    std::cout << "\n===== Test 4: MateriaSource Tests =====\n" << std::endl;
    // MateriaSource class tests
    IMateriaSource *src = new MateriaSource();

    // need to dynamically cast because src is of type IMateriaSource which
    // should not have a print funciton (per subject).
    dynamic_cast<MateriaSource *>(src)->printMateria();
    std::cout << std::endl;

    // Tests learnMateria function adding to the MateriaSource _materias array
    // Can use different types if needed
    src->learnMateria(new Ice);
    src->learnMateria(new Ice);
    src->learnMateria(new Cure);

    dynamic_cast<MateriaSource *>(src)->printMateria();

    // Test createMateria. note it calls .clone for the AMateria instance,
    // effectively making a copy of whatever is in the MateriaSource array.
    AMateria *newice = src->createMateria("ice");
    std::cout << "\nret createMateria: " << newice << "\n" << std::endl;

    // Create a copy of src to verify deep copy.
    // Again dynamic_cast required due to using interface type
    IMateriaSource *src2 =
        new MateriaSource(*dynamic_cast<MateriaSource *>(src));

    *src2 = *src;

    dynamic_cast<MateriaSource *>(src2)->printMateria();

    delete src;
    delete src2;
    delete newice;
  }

  {
    std::cout << "\n===== Test 5: Character Tests =====\n" << std::endl;
    // Character class tests
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Cure);
    AMateria *temp = src->createMateria("cure");

    ICharacter *me = new Character("me");
    ICharacter *jimbo = new Character("jimbo");

    dynamic_cast<Character *>(me)->printInventory();

    // Test for equip
    std::cout << "\nAdding item to inventory test" << std::endl;
    me->equip(temp);
    dynamic_cast<Character *>(me)->printInventory();

    // Does nothing with NULL
    std::cout << "\nequip(NULL) test" << std::endl;
    me->equip(NULL);
    dynamic_cast<Character *>(me)->printInventory();

    // Test for unequip
    // me->unequip(8);

    // Create a copy of me to verify deep copy.
    // Again dynamic_cast required due to using interface type
    std::cout
        << "\nBELOW is a copy of me (me_copy). Name for character is still 'me'"
        << std::endl;
    ICharacter *me_copy = new Character(*dynamic_cast<Character *>(me));
    *me_copy = *me;
    dynamic_cast<Character *>(me_copy)->printInventory();

    // Test use
    std::cout << "\nuse() test" << std::endl;
    me->use(0, *jimbo);
    // Test use out of range (should print nothing).
    me->use(9, *jimbo);

    // Note after use, the materia is deleted and array member set to NULL
    dynamic_cast<Character *>(me)->printInventory();

    delete me;
    delete me_copy;
    delete jimbo;
    delete src;
  }

  {
    std::cout << "\n===== Test 6: Character Tests cont. =====\n" << std::endl;
    // Character class tests continued
    IMateriaSource *src = new MateriaSource();
    ICharacter *me = new Character("me");
    AMateria *floor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    src->learnMateria(new Cure);
    src->learnMateria(new Ice);
    // Inventory starts empty
    dynamic_cast<Character *>(me)->printInventory();

    // newline for keeping things clean and organized
    std::cout << std::endl;

    AMateria *temp = NULL;
    temp = src->createMateria("cure");
    me->equip(temp);
    temp = src->createMateria("ice");
    me->equip(temp);
    temp = src->createMateria("cure");
    me->equip(temp);
    temp = src->createMateria("ice");
    me->equip(temp);

    // Inventory is now full. print inventory to see
    dynamic_cast<Character *>(me)->printInventory();
    std::cout << std::endl;

    // Test if you try to add a matria to a full inventory
    temp = src->createMateria("ice");
    me->equip(temp); // Intentionally 'does nothing' so we need to delete it.
    delete temp;

    // Test unequip and puting on the floor.
    floor[0] = dynamic_cast<Character *>(me)->putOnFloor(0);
    me->unequip(0);
    floor[1] = dynamic_cast<Character *>(me)->putOnFloor(2);
    me->unequip(2);

    dynamic_cast<Character *>(me)->printInventory();
    std::cout << std::endl;

    // Test using use or unequip on non-existant materia
    std::cout << "<<<BELOW: Should be nothing>>>" << std::endl;
    me->use(0, *me); // "Dont do anything" per subject.
    me->unequip(0);  // "Dont do anything" per subject.
    std::cout << "<<<ABOVE: Should be nothing>>>" << std::endl;

    // newline for keeping things clean and organized
    std::cout << std::endl;

    // Print inventory again to see nothing has changed.
    dynamic_cast<Character *>(me)->printInventory();
    std::cout << std::endl;

    // Clean up
    for (int i = 0; i < 10; i++) {
      if (floor[i]) {
        delete floor[i];
        floor[i] = NULL;
      }
    }
    delete me;
    delete src;
  }

  {
    std::cout << "\n===== Test 7 : AMateria =====\n" << std::endl;
    // Testing for AMateria

    AMateria *newMat = NULL;
    AMateria *newIce = new Ice();

    *newMat = *newIce;

    (void)newMat;

    delete newIce;
  }

  return 0;
}
