/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 20:51:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {

  {
    std::cout << "Example: 1" << std::endl;
    Dog dog1;
    dog1.setIdea(0, "Ball!");
    std::cout << "idea is " << dog1.getIdea(0) << " address is "
              << &dog1.getIdea(0) << std::endl;

    // demonstration of the copy constructor working.
    // prints addresses to show the strings have the same content but different
    // addresses.
    Dog dog2 = dog1;
    std::cout << "idea of copy is " << dog2.getIdea(0) << " address is "
              << &dog2.getIdea(0) << std::endl;
  }

  std::cout << std::endl;

  {
    std::cout << "Example: 2" << std::endl;

    Dog *dog1 = NULL;
    dog1 = new Dog;
    dog1->setIdea(0, "OMG an IDEA!?");
    Dog dog2 = *dog1;
    delete dog1;

    // note the idea is still present for dog2 after dog1 is destroyed.
    // idea was made for dog1 but is present in dog2 after dog1 is destroyed.
    // this shows that this was a deep copy.
    std::cout << "Idea for dog2 is: " << dog2.getIdea(0) << std::endl;
  }

  std::cout << std::endl;

  {
    // Same as exmaple 1 but for the Cat class.
    std::cout << "Example: 3" << std::endl;
    Cat cat1;
    cat1.setIdea(0, "Ball!");
    std::cout << "idea is " << cat1.getIdea(0) << " address is "
              << &cat1.getIdea(0) << std::endl;

    // demonstration of the copy constructor working.
    // prints addresses to show the strings have the same content but different
    // addresses.
    Cat cat2 = cat1;
    std::cout << "idea of copy is " << cat2.getIdea(0) << " address is "
              << &cat2.getIdea(0) << std::endl;
  }

  std::cout << std::endl;

  {
    // Same as exmaple 2 but for the Cat class.
    std::cout << "Example: 4" << std::endl;

    Cat *cat1 = NULL;
    cat1 = new Cat;
    cat1->setIdea(0, "OMG an IDEA!?");
    Cat cat2 = *cat1;
    delete cat1;

    // note the idea is still present for cat2 after cat1 is destroyed.
    // idea was made for cat1 but is present in cat2 after cat1 is destroyed.
    // this shows that this was a deep copy.
    std::cout << "Idea for cat2 is: " << cat2.getIdea(0) << std::endl;
  }

  std::cout << std::endl;

  {
    // Requested in the subject
    std::cout << "Example: 5" << std::endl;
    int num_of_animals = 15;

    Animal *animals[num_of_animals];

    // Create all the animal instances
    for (int i = 0; i < num_of_animals; i++) {
      std::cout << "Creating animal number " << i << std::endl;
      if (i < (num_of_animals / 2))
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
      std::cout << std::endl;
    }

    // Delete the animal instances.
    for (int i = 0; i < num_of_animals; i++) {
      std::cout << "Deleting animal number " << i << std::endl;
      delete animals[i];
      std::cout << std::endl;
    }
  }

  return 0;
}
