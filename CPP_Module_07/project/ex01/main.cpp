/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/06 18:05:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main() {
  // main
  {
    std::cout << "\n===== Test 1 : print int array =====\n" << std::endl;
    // int array

    int int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    iter(int_array, 10, &print);
    std::cout << std::endl;
  }

  {
    std::cout << "\n===== Test 2 : print char array =====\n" << std::endl;
    // char array

    char char_array[27] = "abcdefghijklmnopqrstuvwxyz";

    iter(char_array, 26, &print);
    std::cout << std::endl;
  }

  {
    std::cout << "\n===== Test 3 : print double array =====\n" << std::endl;
    // double array

    double d_array[7] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    iter(d_array, 7, &print);
    std::cout << std::endl;
  }

  {
    std::cout << "\n===== Test 4 : increment and print int array =====\n"
              << std::endl;
    // increment and print int array

    int int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    iter(int_array, 10, &print);
    std::cout << "\nAdding one with addOne" << std::endl;
    iter(int_array, 10, &addOne);
    iter(int_array, 10, &print);
    std::cout << std::endl;
  }

  {
    std::cout << "\n===== Test 5 : increment and print double array =====\n"
              << std::endl;
    // increment and print double array

    double double_array[10] = {0.0, 1.1, 2.2, 3.3, 4.4,
                               5.5, 6.6, 7.7, 8.8, 9.9};

    iter(double_array, 10, &print);
    std::cout << "\nAdding one with addOne" << std::endl;
    iter(double_array, 10, &addOne);
    iter(double_array, 10, &print);
    std::cout << std::endl;
  }

  return (0);
}
