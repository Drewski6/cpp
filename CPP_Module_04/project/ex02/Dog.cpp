/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:24:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors , Copy Constructor, Destructor
Dog::Dog(void) : AAnimal() {
  std::cout << "Constructor for Dog" << std::endl;
  AAnimal::type = "Dog";
  brain = new Brain();
};

Dog::Dog(Dog const &source) : AAnimal(source) {
  std::cout << "Copy Constructor for Dog" << std::endl;
  brain = new Brain(*(source.brain));
};

Dog::~Dog(void) {
  std::cout << "Destructor for Dog" << std::endl;
  delete brain;
};

// Overloaded Operators
Dog &Dog::operator=(Dog const &rhs) {
  std::cout << "Overloaded operator= for Dog" << std::endl;
  if (this == &rhs)
    return (*this);
  delete brain;
  brain = new Brain(*(rhs.brain));
  return (*this);
};

// Public Methods
void Dog::makeSound(void) const { std::cout << "Woof Woof!" << std::endl; };

std::string &Dog::getIdea(int idea_index) {
  return brain->getIdea(idea_index);
};

void Dog::setIdea(int idea_index, std::string idea_content) {
  brain->setIdea(idea_index, idea_content);
};

// Private Methods
