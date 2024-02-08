/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:11 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/08 17:47:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

// Constructors , Copy Constructor, Destructor
Brain::Brain(void){
  std::cout << "Constructor called for Brain" << std::endl;
};

Brain::Brain(Brain const &source) { 
  std::cout << "Copy Constructor called for Brain" << std::endl;
  *this = source; 
};

Brain::~Brain(void){
  std::cout << "Destructor called for Brain" << std::endl;
};

// Overloaded Operators
Brain &Brain::operator=(Brain const &rhs) {
  std::cout << "Overloaded operator= for Brain" << std::endl; 
  if (this == &rhs)
    return (*this);
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = rhs.ideas[i];
  }
  return (*this);
};

// Public Methods
std::string &Brain::getIdea(int idea_index) {
  return ideas[idea_index];
};

void Brain::setIdea(int idea_index, std::string idea_content) {
  ideas[idea_index] = idea_content;
};

// Private Methods

