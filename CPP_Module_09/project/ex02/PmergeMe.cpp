/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/19 15:58:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

// Constructors , Copy Constructor, Destructor
PmergeMe::PmergeMe(void){
  int jTNums[20] = {1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
  for (int i = 0; i < 20; i++) {
    jacobsthalNums[i] = jTNums[i];
  }
};
PmergeMe::PmergeMe(PmergeMe const &source) { 
  int jTNums[20] = {1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
  for (int i = 0; i < 20; i++) {
    jacobsthalNums[i] = jTNums[i];
  }
  *this = source; 
};
PmergeMe::~PmergeMe(void){};

// Overloaded Operators
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
void PmergeMe::parseNumsIntoVector(std::vector<int> &vec, int argc, char **argv) {
  std::string allowedChars = "0123456789";

  for (int i = 1; i < argc; i++) {
    std::string input = argv[i];
    char c = 0;

    for (size_t j = 0; j < input.size(); j++) {
      c = input.at(j);
      if (std::find(allowedChars.begin(), allowedChars.end(), c) == allowedChars.end())
        throw ParseException();
    }
  vec.push_back(atoi(argv[i]));
  }
}

void PmergeMe::printVector(std::vector<int> &vec) {
  std::cout << "Vector: ";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec.at(i) << " ";
  }
  std::cout << std::endl;
}

// Exception Implementations
PmergeMe::ParseException::ParseException(){};
PmergeMe::ParseException::~ParseException() throw(){};
const char *PmergeMe::ParseException::what() const throw() {
  return ("Error: parsing error.");
}
