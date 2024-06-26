/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:49:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/20 17:43:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
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
  void printVector(std::string str, std::vector<int> &vec, int debug);
  void printDeque(std::deque<int> &deq);
  void merge_insert_vec(std::vector<int> &v1, int depth);
  void merge_insert_deq(std::deque<int> &d1, int depth);

  // Templated Methods
  template <typename C>
  void parseNumsIntoContainer(C &c, int argc, char **argv) {
    std::string allowedChars = "0123456789";

    for (int i = 1; i < argc; i++) {
      std::string input = argv[i];
      char ch = 0;

      for (size_t j = 0; j < input.size(); j++) {
        ch = input.at(j);
        if (std::find(allowedChars.begin(), allowedChars.end(), ch) == allowedChars.end())
          throw ParseException();
      }
    c.push_back(atoi(argv[i]));
    }
  }

  template <typename C, typename MainChainIt, typename SideChainIt>
  void _insert_group_deq(C &c1, MainChainIt start, SideChainIt cpyStart, int depth) {
    int groupSize = 1 << depth;

    int dist = std::distance(c1.begin(), start);

    for (int i = 0; i < groupSize; i++) {
      c1.insert(c1.begin() + dist, *(cpyStart - i));
    }
    return ;
  }

  // Exception Classes
  class ParseException : public std::exception {
  public:
    ParseException();
    virtual ~ParseException() throw();
    virtual const char *what() const throw();
  };

private:
  int jacobsthalNums[20];

  // Private Methods
  void _jacobsthal_order_vec(
      std::vector<int> &v1, 
      std::vector<int> &v2, 
      int depth);
  void _binary_sort_vec(
      std::vector<int> &c1, 
      std::vector<int>::iterator start, 
      std::vector<int>::iterator cpyStart, 
      int depth, 
      int jTIndex);
  void _insert_group_vec(
      std::vector<int> &c1, 
      std::vector<int>::iterator start, 
      std::vector<int>::iterator cpyStart, 
      int depth);
  void _move_range_vec(
      std::vector<int> &c1, 
      std::vector<int> &c2, 
      int inputGroupNum, 
      int outputGroupNum, 
      int groupSize);
  void _swap_sort_vec(std::vector<int> &v1, int depth);
  void _jacobsthal_order_deq(
      std::deque<int> &l1, 
      std::deque<int> &l2, 
      int depth);
  void _binary_sort_deq(
      std::deque<int> &c1, 
      std::deque<int>::iterator start, 
      std::deque<int>::iterator cpyStart, 
      int depth, 
      int jTIndex);
  void _move_range_deq(
      std::deque<int> &c1, 
      std::deque<int> &c2, 
      int inputGroupNum, 
      int outputGroupNum, 
      int groupSize);
  void _swap_sort_deq(std::deque<int> &l1, int depth);
};
