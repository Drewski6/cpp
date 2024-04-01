/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/04/01 10:42:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main() {
  // main
  {
    std::cout << "\n===== Test 1 : Basic Constructors =====\n" << std::endl;
    // Tests default constructor, copy constructor and copy assignment.

    MutantStack<int> mstack; // default constructor
    MutantStack<int> ustack; // default constructor

    std::cout << "Adding 190 to mstack then copy to ustack\n" << std::endl;
    mstack.push(190);
    ustack = mstack; // copy assignment operator

    std::cout << "mstack size       : " << mstack.size() << std::endl;
    std::cout << "mstack top        : " << mstack.top() << std::endl;
    std::cout << "mstack._stack addr: " << &(mstack.top()) << std::endl;

    std::cout << "ustack size       : " << ustack.size() << std::endl;
    std::cout << "ustack top        : " << ustack.top() << std::endl;
    std::cout << "ustack._stack addr: " << &(ustack.top()) << std::endl;

    std::cout << "\nAdding 270 to mstack but not ustack\n" << std::endl;
    mstack.push(270);

    std::cout << "mstack size       : " << mstack.size() << std::endl;
    std::cout << "mstack top        : " << mstack.top() << std::endl;
    std::cout << "mstack._stack addr: " << &(mstack.top()) << std::endl;

    std::cout << "ustack size       : " << ustack.size() << std::endl;
    std::cout << "ustack top        : " << ustack.top() << std::endl;
    std::cout << "ustack._stack addr: " << &(ustack.top()) << std::endl;

    std::cout << "\nCreating ystack with copy constructor\n" << std::endl;
    MutantStack<int> ystack = mstack;

    std::cout << "ystack size       : " << ystack.size() << std::endl;
    std::cout << "ystack top        : " << ystack.top() << std::endl;
    std::cout << "ystack._stack addr: " << &(ystack.top()) << std::endl;
  }

  {
    std::cout << "\n===== Test 2 : Stack Methods =====\n" << std::endl;
    // Stack Methods //

    MutantStack<int> mstack;

    std::cout << "Is mstack empty? " << (mstack.empty() ? "true" : "false")
              << std::endl;

    std::cout << "\nPushing ints to stack\n" << std::endl;
    mstack.push(111);
    mstack.push(222);
    mstack.push(333);
    mstack.push(444);
    mstack.push(555);

    std::cout << "Is mstack empty? " << (mstack.empty() ? "true" : "false")
              << std::endl;

    std::cout << "mstack size: " << mstack.size() << std::endl;
    std::cout << "mstack top : " << mstack.top() << std::endl;

    std::cout << "\nPopping stack\n" << std::endl;
    mstack.pop();

    std::cout << "mstack size: " << mstack.size() << std::endl;
    std::cout << "mstack top : " << mstack.top() << std::endl;
  }

  {
    std::cout << "\n===== Test 3 : Test from Subject =====\n" << std::endl;
    // Test from Subject //

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
    // return 0; // Not returning yet.
  }

  {
    std::cout << "\n===== Test 4 : Test with std::list (subject) =====\n"
              << std::endl;
    // Test with std::list (subject) //

    std::list<int> myList;

    myList.push_back(5);
    myList.push_back(17);

    std::cout << myList.back() << std::endl;

    myList.pop_back();

    std::cout << myList.size() << std::endl;

    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    //[...]
    myList.push_back(0);

    std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int, std::list<int> > s(myList); // need to use std::list stack
    // return 0; // Not returning yet.
  }

  {
    std::cout << "\n===== Test 5 : Doubles =====\n" << std::endl;
    // Doubles //
  }

  {
    std::cout << "\n===== Test 6 : Strings =====\n" << std::endl;
    // Strings //
  }

  {
    std::cout << "\n===== Test 7 : Algorithms =====\n" << std::endl;
    // What's the point of iterators if they dont work with algorithms //

    // test with std::count, std::max_element, std::min_element,
    // and std::transform to create a new stack
  }

  return (0);
}
