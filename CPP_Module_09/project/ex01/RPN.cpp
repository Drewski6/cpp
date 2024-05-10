/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:41:01 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/10 12:55:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors , Copy Constructor, Destructor
RPN::RPN(std::string input_val) : _input(input_val) {
  std::string allowedChars = "0123456789 /*-+";
  char c = 0;
  for (size_t i = 0; i < _input.size(); i++) {
    c = _input.at(i);
    if (std::find(allowedChars.begin(), allowedChars.end(), c) == allowedChars.end())
      throw InvalidFormException();
  }
};

RPN::RPN(RPN const &source) { *this = source; };

RPN::~RPN(void){};

// Overloaded Operators
RPN &RPN::operator=(RPN const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
std::string RPN::getInput() {
  return _input;
}

// Exception Implementation
RPN::InvalidFormException::InvalidFormException(){};
RPN::InvalidFormException::~InvalidFormException() throw(){};
const char *RPN::InvalidFormException::what() const throw() {
  return ("Error");
}
