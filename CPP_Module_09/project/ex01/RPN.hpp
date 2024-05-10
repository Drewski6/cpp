/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:41:11 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/10 12:51:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include <algorithm>
#include <iostream>

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

  class InvalidFormException : public std::exception {
  public:
    InvalidFormException();
    virtual ~InvalidFormException() throw();
    virtual const char *what() const throw();
  };

private:
  std::string _input;
};
