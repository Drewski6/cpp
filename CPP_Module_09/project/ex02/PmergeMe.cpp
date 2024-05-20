/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/20 16:49:11 by dpentlan         ###   ########.fr       */
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

void PmergeMe::printDeque(std::deque<int> &deq) {
  std::deque<int>::iterator it = deq.begin();

  std::cout << "Deque :\t ";
  for (size_t i = 0; i < deq.size(); i++) {
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

// deque sort functions
void print_deq_gs(std::deque<int> &v1, int depth) {
  int groupSize = 1 << depth;

  std::cout << std::endl;
  for (int i = 0; i < static_cast<int>(v1.size()); i++) {
    if (i % groupSize == groupSize - 1) {
      std::cout << "\ndeq[" << (i) << "]: " << v1.at(i);
    }
  }
  std::cout << "number of groups: " << v1.size() / groupSize << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

void print_deq(std::deque<int> &v1, int depth) {
  int groupSize = 1 << depth;

  for (int i = 0; i < static_cast<int>(v1.size()); i++) {
    if (i % groupSize == 0) {
      std::cout << "\ndeq: ";
    }
    std::cout << v1.at(i) << " ";
  }
  std::cout << std::endl;
}

void print_deq2(std::deque<int> &v1, std::deque<int> &v2, int depth) {
  (void) depth;

  for (int i = 0; i < static_cast<int>(v1.size()); i++) {
    std::cout << "\ndeq[" << i << "]: ";
    try {
      std::cout << "\t" << v1.at(i);
      std::cout << "\t" << v2.at(i);
    } catch (std::exception & ex) {
      continue ;
    }
  }
  std::cout << std::endl;
}

void swap_sort(std::deque<int> &v1, int depth) {
  int groupSize = 1 << depth;

  if (groupSize == 1)
    return ;
  std::cout << "groupSize: " << groupSize << std::endl;
  std::cout << "groupSize >> 1: " << (groupSize >> 1) << std::endl;

  for (int i = groupSize - 1; i < static_cast<int>(v1.size()); i += groupSize) {
    std::cout << "swap looking at: " << v1.at(i - (groupSize >> 1)) << " and " 
              << v1.at(i);
    if (v1.at(i) < v1.at(i - (groupSize >> 1))) {
      std::cout << " yup gonna swap";
      
      std::deque<int>::iterator first_range_start = v1.begin() + (i - (groupSize >> 1) + 1);
      std::deque<int>::iterator first_range_end = v1.begin() + (i + 1);
      std::deque<int>::iterator second_range_start = v1.begin() + (i - (groupSize - 1));

      std::swap_ranges(first_range_start, first_range_end, second_range_start);
    }
    std::cout << std::endl;
  }

  return ;
}

template <typename C>
void move_range(C &c1, C &c2, int inputGroupNum, int outputGroupNum, int groupSize) {

  for (int i = 0; i < groupSize ; i++) {
    c2.push_back(-1);
  }

  typename C::iterator it1 = c1.begin();
  typename C::iterator it2 = c2.begin();

  std::cout << "outputGroupNum: " << outputGroupNum << std::endl;
  std::cout << "inputGroupNum: " << inputGroupNum << std::endl;
  std::cout << "groupSize: " << groupSize << std::endl;

  std::swap_ranges(
      it1 + groupSize * inputGroupNum,
      it1 + groupSize * (inputGroupNum + 1),
      it2 + groupSize * outputGroupNum);
}

template <typename C, typename MainChainIt, typename SideChainIt>
void insert_group(C &c1, MainChainIt start, SideChainIt cpyStart, int depth) {
  int groupSize = 1 << depth;

  int dist = std::distance(c1.begin(), start);

  std::cout << "In insert_group" << std::endl;
  std::cout << "going to transfer behind: " << *start << std::endl;
  for (int i = 0; i < groupSize; i++) {
    std::cout << "inserting " << *(cpyStart - i) << " at " << *start << std::endl;
    c1.insert(c1.begin() + dist, *(cpyStart - i));
  }

  std::cout << "post insert:" << std::endl;
  print_deq(c1, depth);

  print_deq_gs(c1, depth);

  return ;
}

template <typename C, typename MainChainIt, typename SideChainIt>
void binary_sort(C &c1, MainChainIt start, SideChainIt cpyStart, int depth, int jTIndex) {
  int groupSize = 1 << depth;
  int numGroups = 0;

  if ((1 << jTIndex) - 1 < ((c1.end() - start) / groupSize))
    numGroups = (1 << jTIndex) - 1;
  else
    numGroups = (c1.end() - start) / groupSize;
  //numGroups should be either 2^jTIndex or the actual number of groups in c1 whichever is less.
  //This causes a problem in the last return when depths == 0
  MainChainIt middle = start + (groupSize - 1) + (groupSize * (numGroups / 2));

  std::cout << "=======================" << std::endl;
  std::cout << "binarySort: " << std::endl;
  std::cout << "depth: " << depth << std::endl;
  std::cout << "jTIndex: " << jTIndex << std::endl;
  std::cout << "groupSize: " << groupSize << std::endl;
  std::cout << "numGroups: " << numGroups << std::endl;
  std::cout << "*cpyStart: " << *cpyStart << std::endl;
  std::cout << "*start: " << *start << std::endl;
  std::cout << "*middle: " << *middle << std::endl;
  std::cout << "=======================" << std::endl;

  if (jTIndex == 0 || *middle == -1) // check for another way rather than dereferencing middle
    insert_group(c1, start, cpyStart, depth);
  else {
    if (*cpyStart > *middle) {
      std::cout << "*cpyStart > *middle" << std::endl;
      binary_sort(c1, middle + 1, cpyStart, depth, jTIndex -1);
    }
    else {
      std::cout << "*cpyStart < *middle" << std::endl;
      binary_sort(c1, start, cpyStart, depth, jTIndex -1);
    }
  }

  return ;
}

void PmergeMe::_jacobsthal_order_deq(std::deque<int> &v1, std::deque<int> &v2, int depth) {
  int groupSize = 1 << depth;

  std::cout << "Num of groups in main chain: " << (v1.size() / groupSize) << std::endl;
  std::cout << "Groups to sort: " << (v2.size() / groupSize) << std::endl;

  int closestJTIndex = 0;
  for (int i = 0; i < 19; i++) {
    closestJTIndex = i;
    if (jacobsthalNums[i] >= static_cast<int>(v2.size() / groupSize) + 1)
      break ;
  }
  
  std::cout << "closestJTIndex: " << closestJTIndex << std::endl;

  for (int jTIndex = 1; jTIndex <= closestJTIndex; jTIndex++) {
    for (int bn = jacobsthalNums[jTIndex]; bn > jacobsthalNums[jTIndex - 1]; bn--) {
      std::cout << "Looking at b" << bn << "; jTIndex: " << jTIndex << std::endl;
      if ((bn - 1) > static_cast<int>(v2.size() / groupSize)) {
        std::cout << "Skipping b" << bn << std::endl;
        continue;
      }
      binary_sort(
          v1,
          v1.begin(), // Start of v1
          v2.begin() + (groupSize - 1) + ((bn - 2) * groupSize), // 
          depth, 
          jTIndex);
    }
  }

  return ;
}

void PmergeMe::merge_insert_deq(std::deque<int> &v1, int depth) {
  int groupSize = 1 << depth;

  // print statements are fun
  std::cout << "\nNew call. Current depth: " << depth << std::endl;

  std::cout << "\nPre-sort" << std::endl;
  print_deq(v1, depth);

  // swap sort by group size
  swap_sort(v1, depth);

  std::cout << "\nPost-sort" << std::endl;
  print_deq(v1, depth);

  // Check if we need to do recursion
  if (v1.size() / groupSize == 1) // return if there is only one group
    return ;

  merge_insert_deq(v1, depth + 1);

  if (v1.size() / groupSize == 2) {// group size of 2 is already sorted
    std::cout << "skipping call with only 2 groups. Already sorted." << std::endl;
    return ;
  }

  std::cout << "Finished with merge_insert call." 
            << "Number of groups: " << (v1.size() / groupSize)
            << std::endl;

  std::deque<int> v2;

  std::cout << "Begin:";
  print_deq2(v1, v2, depth);
  
  int j = 0;
  for (int i = 2; i < static_cast<int>(v1.size() / groupSize); i++) {
    if (i % 2 == 0) {
      std::cout << "j: " << j << std::endl;
      move_range(v1, v2, i, j, groupSize);
      print_deq2(v1, v2, depth);
      j++;
    }
  }

  std::deque<int>::iterator newEnd = std::remove(v1.begin(), v1.end(), -1);
  v1.erase(newEnd, v1.end());

  std::cout << "Divide:";
  print_deq2(v1, v2, depth);

  _jacobsthal_order_deq(v1, v2, depth);

  std::cout << "Sort:";
  print_deq2(v1, v2, depth);

  return ;
}
