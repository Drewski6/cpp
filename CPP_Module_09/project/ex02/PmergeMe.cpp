/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/12 19:50:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors , Copy Constructor, Destructor
PmergeMe::PmergeMe(void){};
PmergeMe::PmergeMe(PmergeMe const &source) { *this = source; };
PmergeMe::~PmergeMe(void){};

// Overloaded Operators
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};
