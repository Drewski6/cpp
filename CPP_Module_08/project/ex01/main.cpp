/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/29 15:02:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <deque>

int getRandomInt(int max) {
  static int offset = 0;
  std::srand(std::time(0) + (offset * 12));   // seed random num gen
  offset++;
  return std::rand() % (max + 1); // generate and return number between 1 and max.
}

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

  {
    std::cout << "\n===== Test 5 : GOOD longestSpan =====" << std::endl;
    // GOOD LongestSpan //

    int numElements = 2;
    int maxValue = 100;
    int longSpan = 0;
    Span mySpan = Span(numElements);
    std::vector<int> myVec;
    
    for (int i = 0; i < numElements; i++) {
      myVec.push_back(getRandomInt(maxValue));
    }

    try {
      mySpan.addRange<std::vector<int> >(myVec.begin(), myVec.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      longSpan = mySpan.longestSpan();
      std::cout << "Longest Span Found: " << longSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 6 : BAD longestSpan =====" << std::endl;
    // BAD LongestSpan //

    Span mySpan = Span(1);
    int longSpan = 0;

    mySpan.addNumber(7);
    
    try {
      longSpan = mySpan.longestSpan();
      std::cout << "Longest Span Found: " << longSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 7 : GOOD shortestSpan =====" << std::endl;
    // GOOD LongestSpan //

    int numElements = 8;
    int maxValue = 100;
    Span mySpan = Span(numElements);
    int shortSpan = 0;
    std::vector<int> myVec;
    
    for (int i = 0; i < numElements; i++) {
      myVec.push_back(getRandomInt(maxValue));
    }

    try {
      mySpan.addRange<std::vector<int> >(myVec.begin(), myVec.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      shortSpan = mySpan.shortestSpan();
      std::cout << "Shortest Span Found: " << shortSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 7 : BAD shortestSpan =====" << std::endl;
    // BAD LongestSpan //

    int numElements = 1;
    int maxValue = 100;
    Span mySpan = Span(numElements);
    int shortSpan = 0;
    
    mySpan.addNumber(getRandomInt(maxValue));

    try {
      shortSpan = mySpan.shortestSpan();
      std::cout << "Shortest Span Found: " << shortSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  {
    std::cout << "\n===== Test 8 : Test From Subject =====\n" << std::endl;
    // Test From Subject //
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    //return 0;   // not going to return here lol
  }

  {
    std::cout << "\n===== Test 9 : shortestSpan GT 10000 Elements =====\n" << std::endl;
    // Greater than 10000 elements //
    int numElements = 20000;
    int maxValue = 1000000000;
    Span mySpan = Span(numElements);
    int shortSpan = 0;
    std::vector<int> myVec;
    
    for (int i = 0; i < numElements; i++) {
      myVec.push_back(getRandomInt(maxValue));
    }

    try {
      mySpan.addRange<std::vector<int> >(myVec.begin(), myVec.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      shortSpan = mySpan.shortestSpan();
      std::cout << "Shortest Span Found: " << shortSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    // mySpan.displaySpan();  // Uncomment at your own peril.
  }

  {
    std::cout << "\n===== Test 10 : longestSpan GT 10000 Elements =====\n" << std::endl;
    // Greater than 10000 elements //
    int numElements = 20000;
    int maxValue = 1000000000;
    Span mySpan = Span(numElements);
    int shortSpan = 0;
    std::vector<int> myVec;
    
    for (int i = 0; i < numElements; i++) {
      myVec.push_back(getRandomInt(maxValue));
    }

    try {
      mySpan.addRange<std::vector<int> >(myVec.begin(), myVec.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      shortSpan = mySpan.longestSpan();
      std::cout << "Shortest Span Found: " << shortSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    // mySpan.displaySpan();  // Uncomment at your own peril.
  }
  
  {
    std::cout << "\n===== Test 11 : Basic Test with List =====\n" << std::endl;
    // Basic Test with List //
    int numElements = 8;
    int maxValue = 100;
    Span mySpan = Span(numElements);
    int shortSpan = 0;
    std::list<int> myList;
    
    for (int i = 0; i < numElements; i++) {
      myList.push_back(getRandomInt(maxValue));
    }

    try {
      mySpan.addRange<std::list<int> >(myList.begin(), myList.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      shortSpan = mySpan.shortestSpan();
      std::cout << "Shortest Span Found: " << shortSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }
  
  {
    std::cout << "\n===== Test 12 : Basic Test with Deque =====\n" << std::endl;
    // Basic Test with Deque //
    int numElements = 8;
    int maxValue = 100;
    Span mySpan = Span(numElements);
    int shortSpan = 0;
    std::deque<int> myDeque;
    
    for (int i = 0; i < numElements; i++) {
      myDeque.push_back(getRandomInt(maxValue));
    }

    try {
      mySpan.addRange<std::deque<int> >(myDeque.begin(), myDeque.end());
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      shortSpan = mySpan.shortestSpan();
      std::cout << "Shortest Span Found: " << shortSpan << std::endl;
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    mySpan.displaySpan();
  }

  return (0);
}
