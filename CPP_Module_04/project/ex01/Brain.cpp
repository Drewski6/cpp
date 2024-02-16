/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:11 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 20:43:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors , Copy Constructor, Destructor
Brain::Brain(void) { std::cout << "Constructor for Brain" << std::endl; };

Brain::Brain(Brain const &source) {
  std::cout << "Copy Constructor for Brain" << std::endl;
  *this = source;
};

Brain::~Brain(void) { std::cout << "Destructor for Brain" << std::endl; };

// Overloaded Operators
Brain &Brain::operator=(Brain const &rhs) {
  if (this == &rhs)
    return (*this);
  // Deep copy implementation via copying each string in ideas array.
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = rhs.ideas[i];
  }
  return (*this);
};

// Public Methods
std::string &Brain::getIdea(int idea_index) { return ideas[idea_index]; };

void Brain::setIdea(int idea_index, std::string idea_content) {
  ideas[idea_index] = idea_content;
};
