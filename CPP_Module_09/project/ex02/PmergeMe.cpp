/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/19 17:44:28 by dpentlan         ###   ########.fr       */
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
void PmergeMe::printVector(std::string str, std::vector<int> &vec, int debug) {
  std::cout << str << ":\t ";
  for (size_t i = 0; i < vec.size(); i++) {
    if (i == 5 && debug == 0)
      break;
    if (i == 4 && vec.size() > 5 && debug == 0)
      std::cout << "[...]" << " ";
    else
      std::cout << vec.at(i) << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printList(std::list<int> &lst) {
  std::list<int>::iterator it = lst.begin();

  std::cout << "List  : ";
  for (size_t i = 0; i < lst.size(); i++) {
    std::cout << *it << " ";
    std::advance(it, 1);
  }
  std::cout << std::endl;
}

// Exception Implementations
PmergeMe::ParseException::ParseException(){};
PmergeMe::ParseException::~ParseException() throw(){};
const char *PmergeMe::ParseException::what() const throw() {
  return ("Error: parsing error.");
}

// Vector Sort Functions
void PmergeMe::merge_insert_vec(std::vector<int> &v1, int depth) {
  int groupSize = 1 << depth;

  _swap_sort_vec(v1, depth);
  // Check if we need to do recursion
  if (v1.size() / groupSize == 1) // return if there is only one group
    return ;
  merge_insert_vec(v1, depth + 1);
  if (v1.size() / groupSize == 2) // group size of 2 is already sorted
    return ;

  std::vector<int> v2;
  int j = 0;

  for (int i = 2; i < static_cast<int>(v1.size() / groupSize); i++) {
    if (i % 2 == 0) {
      _move_range_vec(v1, v2, i, j, groupSize);
      j++;
    }
  }
  std::vector<int>::iterator newEnd = std::remove(v1.begin(), v1.end(), -1);
  v1.erase(newEnd, v1.end());
  _jacobsthal_order_vec(v1, v2, depth);
  return ;
}

void PmergeMe::_jacobsthal_order_vec(std::vector<int> &v1, std::vector<int> &v2, int depth) {
  int groupSize = 1 << depth;
  int closestJTIndex = 0;

  for (int i = 0; i < 19; i++) {
    closestJTIndex = i;
    if (jacobsthalNums[i] >= static_cast<int>(v2.size() / groupSize) + 1)
      break ;
  }

  for (int jTIndex = 1; jTIndex <= closestJTIndex; jTIndex++) {
    for (int bn = jacobsthalNums[jTIndex]; bn > jacobsthalNums[jTIndex - 1]; bn--) {
      if ((bn - 1) > static_cast<int>(v2.size() / groupSize)) {
        continue;
      }
      _binary_sort_vec(
          v1,
          v1.begin(), // Start of v1
          v2.begin() + (groupSize - 1) + ((bn - 2) * groupSize),
          depth, 
          jTIndex);
    }
  }
  return ;
}

void PmergeMe::_binary_sort_vec(std::vector<int> &c1, std::vector<int>::iterator start, std::vector<int>::iterator cpyStart, int depth, int jTIndex) {
  int groupSize = 1 << depth;
  int numGroups = 0;

  if ((1 << jTIndex) - 1 < ((c1.end() - start) / groupSize))
    numGroups = (1 << jTIndex) - 1;
  else
    numGroups = (c1.end() - start) / groupSize;

  std::vector<int>::iterator middle = start + (groupSize - 1) + (groupSize * (numGroups / 2));
  if (jTIndex == 0 || *middle == -1) // check for another way rather than dereferencing middle
    _insert_group_vec(c1, start, cpyStart, depth);
  else {
    if (*cpyStart > *middle)
      _binary_sort_vec(c1, middle + 1, cpyStart, depth, jTIndex -1);
    else
      _binary_sort_vec(c1, start, cpyStart, depth, jTIndex -1);
  }
  return ;
}

void PmergeMe::_insert_group_vec(std::vector<int> &c1, std::vector<int>::iterator start, std::vector<int>::iterator cpyStart, int depth) {
  int groupSize = 1 << depth;

  for (int i = 0; i < groupSize; i++) {
    c1.insert(start, *(cpyStart - i));
  }
  return ;
}

void PmergeMe::_move_range_vec(std::vector<int> &c1, std::vector<int> &c2, int inputGroupNum, int outputGroupNum, int groupSize) {

  for (int i = 0; i < groupSize ; i++) {
    c2.push_back(-1);
  }

  std::vector<int>::iterator it1 = c1.begin();
  std::vector<int>::iterator it2 = c2.begin();

  std::swap_ranges(
      it1 + groupSize * inputGroupNum,
      it1 + groupSize * (inputGroupNum + 1),
      it2 + groupSize * outputGroupNum);
}

void PmergeMe::_swap_sort_vec(std::vector<int> &v1, int depth) {
  int groupSize = 1 << depth;

  if (groupSize == 1)
    return ;

  for (int i = groupSize - 1; i < static_cast<int>(v1.size()); i += groupSize) {
    if (v1.at(i) < v1.at(i - (groupSize >> 1))) {
      std::vector<int>::iterator first_range_start = v1.begin() + (i - (groupSize >> 1) + 1);
      std::vector<int>::iterator first_range_end = v1.begin() + (i + 1);
      std::vector<int>::iterator second_range_start = v1.begin() + (i - (groupSize - 1));

      std::swap_ranges(first_range_start, first_range_end, second_range_start);
    }
  }
  return ;
}
