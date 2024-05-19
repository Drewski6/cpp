/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:49:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/19 15:49:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>

class PmergeMe {
public:
  // Constructors , Copy Constructor, Destructor
  PmergeMe(void);
  PmergeMe(PmergeMe const &source);
  ~PmergeMe(void);
  
  // Overloaded Operators
  PmergeMe &operator=(PmergeMe const &rhs);

  // Public Methods
  void parseNumsIntoVector(std::vector<int> &vec, int argc, char **argv);
  void printVector(std::vector<int> &vec);

  // Exception Classes
  class ParseException : public std::exception {
  public:
    ParseException();
    virtual ~ParseException() throw();
    virtual const char *what() const throw();
  };

private:
  int jacobsthalNums[20];
};
