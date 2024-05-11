/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:41:01 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/11 13:39:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>

// Constructors , Copy Constructor, Destructor
RPN::RPN(std::string input_val) : _input(input_val), _stack() {};

RPN::RPN(RPN const &source) : _input(source._input), _stack() { *this = source; };

RPN::~RPN(void){};

// Overloaded Operators
RPN &RPN::operator=(RPN const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
std::string RPN::getInput() {
  return _input;
}

void RPN::parseInput() {
  std::string allowedChars = "0123456789 /*-+";
  char c = 0;

  // Verify chars in string are in set.
  for (size_t i = 0; i < _input.size(); i++) {
    c = _input.at(i);
    if (std::find(allowedChars.begin(), allowedChars.end(), c) == allowedChars.end())
      throw InvalidFormException();
  }
  
  // Verify no numbers are greater than 10
  if (std::adjacent_find(_input.begin(), 
    _input.end(), VerifyNoDoubleDigitsPred()) != _input.end()) {
    throw InvalidFormException();
  }
}

int RPN::evaluate() {
  for (std::string::iterator it = _input.begin(); it != _input.end(); it++) {
    if (*it == ' ')
      continue;

    // std::cout << "evaluating: " << *it << std::endl;
    if (std::isdigit(*it))
      _stack.push(std::atoi(&(*it)));
    else {
      if (_stack.size() < 2)
        throw StackTooSmallException();
      _applyOperator(*it);
    }
  }

  if (_stack.size() > 1)
    throw NotEnoughOperatorsException();
  return (_stack.top());
}

// Private Methods
void RPN::_applyOperator(char c) {
  char sel[4] = {'/', '*', '-', '+'};
  int i = 0;

  for (; i < 4; i++) {
    if (c == sel[i])
      break ;
  }

  int b = _stack.top();
  _stack.pop();
  int a = _stack.top();
  _stack.pop();

  // std::cout << "apply: " << c << std::endl;

  switch(i) {
    case 0:
      _stack.push(a / b);
      // std::cout << "pushing: " << (a / b) << std::endl;
      break;
    case 1:
      _stack.push(a * b);
      // std::cout << "pushing: " << (a * b) << std::endl;
      break;
    case 2:
      _stack.push(a - b);
      // std::cout << "pushing: " << (a - b) << std::endl;
      break;
    case 3:
      _stack.push(a + b);
      // std::cout << "pushing: " << (a + b) << std::endl;
      break;
    default:
      throw InvalidFormException();
  }
  return ;
}

// Exception Implementation
RPN::InvalidFormException::InvalidFormException(){};
RPN::InvalidFormException::~InvalidFormException() throw(){};
const char *RPN::InvalidFormException::what() const throw() {
  return ("Error: parsing error.");
}

RPN::StackTooSmallException::StackTooSmallException(){};
RPN::StackTooSmallException::~StackTooSmallException() throw(){};
const char *RPN::StackTooSmallException::what() const throw() {
  return ("Error: cannot perform operation because stack is too small.");
}

RPN::NotEnoughOperatorsException::NotEnoughOperatorsException(){};
RPN::NotEnoughOperatorsException::~NotEnoughOperatorsException() throw(){};
const char *RPN::NotEnoughOperatorsException::what() const throw() {
  return ("Error: expression cannot be evaluated because not enough operators.");
}

RPN::VerifyNoDoubleDigitsPred::VerifyNoDoubleDigitsPred(){};

bool RPN::VerifyNoDoubleDigitsPred::operator()(int a, int b) const {
  if (std::isdigit(a) && std::isdigit(b))
    return (1);
  return (0);
}

