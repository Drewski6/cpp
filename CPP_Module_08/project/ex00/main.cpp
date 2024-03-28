/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/28 17:08:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

// Print addresses for evaluator.
template <typename T> void printAddresses(const T &container) {
  typename T::const_iterator it = container.begin();
  std::cout << "| Value | Address           |" << std::endl;
  for (; it != container.end(); it++) {
    std::cout << "| " << *it << "     | " << &(*it) << "    |" << std::endl;
  }
}

int main() {
  {
    std::cout << "===== Test 1 : GOOD Vector Search" << std::endl;

    // Create v1 and load it with ints
    std::vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    // Use easyfind and save result as it.
    std::vector<int>::iterator it = easyfind(v1, 3);

    // Error handling. Iterator equivalent of returing NULL.
    if (it == v1.end())
      std::cout << "Item not be found. Returned address (v1.end()): " << &(*it)
                << std::endl;
    else
      std::cout << "Item found with value: " << *it << " at address: " << &(*it)
                << std::endl;

    printAddresses(v1);
  }

  {
    std::cout << "===== Test 2 : BAD Vector Search" << std::endl;

    // Create v1 and load it with ints
    std::vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    // Use easyfind and save result as it.
    std::vector<int>::iterator it = easyfind(v1, 8);

    // Error handling. Iterator equivalent of returing NULL.
    if (it == v1.end())
      std::cout << "Item not be found. Returned address (v1.end()): " << &(*it)
                << std::endl;
    else
      std::cout << "Item found with value: " << *it << " at address: " << &(*it)
                << std::endl;

    printAddresses(v1);
  }

  {
    std::cout << "\n===== Test 3 : GOOD Deque Search =====\n" << std::endl;

    std::deque<int> d1;
    d1.push_back(0);
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);

    // Use easyfind and save result as it.
    std::deque<int>::iterator it = easyfind(d1, 3);

    // Error handling. Iterator equivalent of returing NULL.
    if (it == d1.end())
      std::cout << "Item not be found. Returned address (d1.end()): " << &(*it)
                << std::endl;
    else
      std::cout << "Item found with value: " << *it << " at address: " << &(*it)
                << std::endl;

    printAddresses(d1);
  }

  {
    std::cout << "\n===== Test 4 : BAD Deque Search =====\n" << std::endl;

    std::deque<int> d1;
    d1.push_back(0);
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);

    // Use easyfind and save result as it.
    std::deque<int>::iterator it = easyfind(d1, 8);

    // Error handling. Iterator equivalent of returing NULL.
    if (it == d1.end())
      std::cout << "Item not be found. Returned address (d1.end()): " << &(*it)
                << std::endl;
    else
      std::cout << "Item found with value: " << *it << " at address: " << &(*it)
                << std::endl;

    printAddresses(d1);
  }

  {
    std::cout << "\n===== Test 5 : GOOD List Search =====\n" << std::endl;

    std::list<int> l1;
    l1.push_back(0);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    // Use easyfind and save result as it.
    std::list<int>::iterator it = easyfind(l1, 3);

    // Error handling. Iterator equivalent of returing NULL.
    if (it == l1.end())
      std::cout << "Item not be found. Returned address (l1.end()): " << &(*it)
                << std::endl;
    else
      std::cout << "Item found with value: " << *it << " at address: " << &(*it)
                << std::endl;

    printAddresses(l1);
  }

  {
    std::cout << "\n===== Test 5 : BAD List Search =====\n" << std::endl;

    std::list<int> l1;
    l1.push_back(0);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    // Use easyfind and save result as it.
    std::list<int>::iterator it = easyfind(l1, 8);

    // Error handling. Iterator equivalent of returing NULL.
    if (it == l1.end())
      std::cout << "Item not be found. Returned address (l1.end()): " << &(*it)
                << std::endl;
    else
      std::cout << "Item found with value: " << *it << " at address: " << &(*it)
                << std::endl;

    printAddresses(l1);
  }

  // NOTE: No tests for std::array or std::forward_list because C++98 only.

  return (0);
}
