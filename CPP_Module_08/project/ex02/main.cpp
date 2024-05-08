/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/08 22:03:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>

// Helper for printing stack for evaluation.
template <typename T, typename C>
void printStack(MutantStack<T, C> M) {
  std::cout << "[ ";
  for (typename MutantStack<T, C>::iterator it = M.begin(); it != M.end(); it++) {
      std::cout << *it << " ";
  }
  std::cout << "]" << std::endl;
}

// cmp for use with std::max_element and std::min_element
bool cmp(int a, int b) {
  return a < b;
}

// for use with std::transform
int times_two(int a) {
  return a * 2;
}

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
    MutantStack<double> mstack;

    std::cout << "Is mstack empty? " << (mstack.empty() ? "true" : "false")
              << std::endl;

    std::cout << "\nPushing doubles to stack\n" << std::endl;
    mstack.push(111.111);
    mstack.push(222.222);
    mstack.push(333.333);
    mstack.push(444.444);
    mstack.push(555.555);

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
    std::cout << "\n===== Test 6 : Strings =====\n" << std::endl;
    // Strings //
    MutantStack<std::string> mstack;

    std::cout << "Is mstack empty? " << (mstack.empty() ? "true" : "false")
              << std::endl;

    std::cout << "\nPushing ints to stack\n" << std::endl;
    mstack.push("oh");
    mstack.push("my");
    mstack.push("gosh!");
    mstack.push("It");
    mstack.push("Works!!!");

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
    // What's the point of iterators if they dont work with algorithms //

    // test with std::count, std::max_element, std::min_element,
    // and std::transform to create a new stack
    
    MutantStack<int> mstack;
    // one 1
    mstack.push(1);
    // two 2s
    mstack.push(2);
    mstack.push(2);
    // three 3s
    mstack.push(3);
    mstack.push(3);
    mstack.push(3);
    // four 4s
    mstack.push(4);
    mstack.push(4);
    mstack.push(4);
    mstack.push(4);
    // five 5s
    mstack.push(5);
    mstack.push(5);
    mstack.push(5);
    mstack.push(5);
    mstack.push(5);


    std::cout << "\n===== Test 7 : std::count algorithm =====\n" << std::endl;
    int count = std::count(mstack.begin(), mstack.end(), 5);
    std::cout << "mstack: ";
    printStack(mstack);
    std::cout << "Number of 5s: " << count << std::endl;

    std::cout << "\n===== Test 8 : std::max_element algorithm =====\n" << std::endl;
    MutantStack<int>::iterator it_max = std::max_element(mstack.begin(), mstack.end(), cmp);
    std::cout << "mstack: ";
    printStack(mstack);
    std::cout << "Max element value: " << *it_max << std::endl;

    std::cout << "\n===== Test 9 : std::min_element algorithm =====\n" << std::endl;
    MutantStack<int>::iterator it_min = std::min_element(mstack.begin(), mstack.end(), cmp);
    std::cout << "mstack: ";
    printStack(mstack);
    std::cout << "Min element value: " << *it_min << std::endl;

    std::cout << "\n===== Test 10 : std::transform algorithm =====\n" << std::endl;
    MutantStack<int> ustack;
    
    // need to push all 0s to create space in underlying container.
    for (size_t i = 0; i < mstack.size(); i++) {
      ustack.push(0);
    }

    std::transform(mstack.begin(), mstack.end(), ustack.begin(), times_two);
    std::cout << "mstack: ";
    printStack(mstack);
    std::cout << "ustack: ";
    printStack(ustack);
  }

  {
    std::cout << "\n===== Test 11 : MutantStack with underlying std::list =====\n" << std::endl;

    MutantStack<int, std::list<int> > mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    std::cout << "mstack: ";
    printStack(mstack);
  }

  {
    std::cout << "\n===== Test 12 : MutantStack with underlying std::vector =====\n" << std::endl;

    MutantStack<int, std::vector<int> > mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    std::cout << "mstack: ";
    printStack(mstack);
  }

  return (0);
}
