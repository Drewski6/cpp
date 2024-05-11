/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:41:11 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/11 13:16:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>

class RPN {
public:
  // Constructors , Copy Constructor, Destructor
  RPN(std::string input_val);
  RPN(RPN const &source);
  ~RPN(void);
  
  // Overloaded Operators
  RPN &operator=(RPN const &rhs);

  // Public Methods
  std::string getInput();
  void parseInput();
  int evaluate();

  // Exception Classes
  class InvalidFormException : public std::exception {
  public:
    InvalidFormException();
    virtual ~InvalidFormException() throw();
    virtual const char *what() const throw();
  };

  class StackTooSmallException : public std::exception {
  public:
    StackTooSmallException();
    virtual ~StackTooSmallException() throw();
    virtual const char *what() const throw();
  };

  class NotEnoughOperatorsException : public std::exception {
  public:
    NotEnoughOperatorsException();
    virtual ~NotEnoughOperatorsException() throw();
    virtual const char *what() const throw();
  };

  // Functor for VerifyNoDoubleDigitsPred
  class VerifyNoDoubleDigitsPred {
  public:
    VerifyNoDoubleDigitsPred();
    bool operator()(int a, int b) const;
  };

private:
  std::string _input;
  std::stack<int> _stack;

  void _applyOperator(char c);
};
