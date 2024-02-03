/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 19:42:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"
#include <iostream>

int main() {

  std::cout << "\n===================================\n"
            << "Example: 1\n"
            << std::endl;

  {
    // Showing Constructors, Destructors and Methods for Animal class.
    Animal animal1;
    std::cout << "Type: " << animal1.getType() << std::endl;
    animal1.makeSound();
  }

  std::cout << "\n===================================\n"
            << "Example: 2\n"
            << std::endl;

  {
    // Showing Constructors, Destructors and Methods for Dog class.
    Dog dog1;
    std::cout << "Type: " << dog1.getType() << std::endl;
    dog1.makeSound();
  }

  std::cout << "\n===================================\n"
            << "Example: 3\n"
            << std::endl;

  {
    // Showing Constructors, Destructors and Methods for Cat class.
    Cat cat1;
    std::cout << "Type: " << cat1.getType() << std::endl;
    cat1.makeSound();
  }

  std::cout << "\n===================================\n"
            << "Example: 4\n"
            << std::endl;

  {
    // Showing Copy Constructors.
    Dog dog1;
    Dog dog2 = dog1;
    dog2.makeSound();
  }

  std::cout << "\n===================================\n"
            << "Example: 5\n"
            << std::endl;

  {
    // Example from the subject
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
  }

  std::cout << "\n===================================\n"
            << "Example: 6\n"
            << std::endl;

  {
    // Animal and Cat classes use virtual keyword for makeSound.
    const Animal *i = new Cat();
    const Cat *j = new Cat();

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();

    std::cout << j->getType() << " " << std::endl;
    j->makeSound();

    delete i;
    delete j;
  }

  std::cout << "\n===================================\n"
            << "Example: 7\n"
            << std::endl;

  {
    // WrongClasses do not use virtual keyword.
    const WrongAnimal *i = new WrongCat();
    const WrongCat *j = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();

    std::cout << j->getType() << " " << std::endl;
    j->makeSound();

    delete i;
    delete j;
  }

  return 0;
}
