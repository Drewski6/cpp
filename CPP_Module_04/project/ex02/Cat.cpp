/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:23:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors , Copy Constructor, Destructor
Cat::Cat(void) : AAnimal() {
  std::cout << "Constructor for Cat" << std::endl;
  AAnimal::type = "Cat";
  brain = new Brain();
};

Cat::Cat(Cat const &source) : AAnimal(source) {
  std::cout << "Copy Constructor for Cat" << std::endl;
  brain = new Brain(*(source.brain));
};

Cat::~Cat(void) {
  std::cout << "Destructor for Cat" << std::endl;
  delete brain;
};

// Overloaded Operators
Cat &Cat::operator=(Cat const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  delete brain;
  brain = new Brain(*(rhs.brain));
  return (*this);
};

// Public Methods
void Cat::makeSound(void) const { std::cout << "Meow....." << std::endl; };

std::string &Cat::getIdea(int idea_index) {
  return brain->getIdea(idea_index);
};

void Cat::setIdea(int idea_index, std::string idea_content) {
  brain->setIdea(idea_index, idea_content);
};
