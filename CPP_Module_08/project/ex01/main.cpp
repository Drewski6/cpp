/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/28 21:37:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {

  {
    std::cout << "===== Test 1 : GOOD Fill Span =====" << std::endl;

    Span mySpan = Span(5);

    mySpan.addNumber(0);
    mySpan.addNumber(1);
    mySpan.addNumber(2);
    mySpan.addNumber(3);
    mySpan.addNumber(4);

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 2 : BAD Fill Span =====" << std::endl;

    Span mySpan = Span(4);

    try {
      mySpan.addNumber(0);
      mySpan.addNumber(1);
      mySpan.addNumber(2);
      mySpan.addNumber(3);
      mySpan.addNumber(4); // one too many
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 3 : GOOD Fill Range Span =====" << std::endl;

    Span mySpan = Span(5);
    std::vector<int> myVec;

    myVec.push_back(0);
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.push_back(4);

    mySpan.addRange<std::vector<int> >(myVec.begin(), myVec.end());

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 4 : BAD Fill Range Span =====" << std::endl;

    Span mySpan = Span(4);
    std::vector<int> myVec;

    myVec.push_back(0);
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.push_back(4);

    try {
      mySpan.addRange<std::vector<int> >(myVec.begin(), myVec.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  // left off here. need to make my shortestSpan function and longestSpan function
  // need to add tests for both of those
  // test in subject and check output
  // test at least 10000 elements and searching for spans.
  //
  // make a function to create random numbers between 1 and 100,000 and use that to fill vectors, then spans
  // test all functions with this.

  return (0);
}
