/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/20 16:17:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  PmergeMe pme;
  std::vector<int> vec;
  std::deque<int> deq;


  {
    struct timeval start, end;

    gettimeofday(&start, NULL);
    try {
      pme.parseNumsIntoContainer(vec, argc, argv);
    } catch (std::exception & ex) {
      std::cout << ex.what() << std::endl;
      return (1);
    }
    pme.printVector("Before", vec, 0);
    pme.merge_insert_vec(vec, 0);
    pme.printVector("After", vec, 0);
    gettimeofday(&end, NULL);
    long long duration_us = 
      (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << duration_us 
              << " us" << std::endl;
  }

  {
    struct timeval start, end;

    gettimeofday(&start, NULL);
    try {
      pme.parseNumsIntoContainer(deq, argc, argv);
    } catch (std::exception & ex) {
      std::cout << ex.what() << std::endl;
      return (1);
    }
    pme.merge_insert_deq(deq, 0);
    gettimeofday(&end, NULL);
    long long duration_us = 
      (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << duration_us 
              << " us" << std::endl;
  }

  {
    // Full print of vector
    pme.printVector("Vector", vec, 1);
    pme.printDeque(deq);
  }

  return (0);
}
