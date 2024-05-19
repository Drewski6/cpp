/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:49:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/19 19:28:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
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
  void printList(std::list<int> &lst);
  void merge_insert_vec(std::vector<int> &v1, int depth);
  void merge_insert_lst(std::list<int> &l1, int depth);

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
  void _jacobsthal_order_lst(
      std::list<int> &l1, 
      std::list<int> &l2, 
      int depth);
  void _binary_sort_lst(
      std::list<int> &c1, 
      std::list<int>::iterator start, 
      std::list<int>::iterator cpyStart, 
      int depth, 
      int jTIndex);
  void _insert_group_lst(
      std::list<int> &c1, 
      std::list<int>::iterator start, 
      std::list<int>::iterator cpyStart, 
      int depth);
  void _move_range_lst(
      std::list<int> &c1, 
      std::list<int> &c2, 
      int inputGroupNum, 
      int outputGroupNum, 
      int groupSize);
  void _swap_sort_lst(std::list<int> &l1, int depth);
};
