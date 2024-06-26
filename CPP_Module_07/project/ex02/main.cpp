/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/07 16:43:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
  // main

  {
    std::cout << "\n===== Test 1 : Test size =====\n" << std::endl;
    // Testing sizeof the class and the total array size when default
    // constructor is used.

    int size = 0;
    Array<int> my_array;

    std::cout << "sizeof class: " << sizeof(my_array[0]) * size << " bytes"
              << std::endl;
    std::cout << "len of array: " << my_array.size() << std::endl;
  }

  {
    std::cout << "\n===== Test 2 : Test size (size arg given) =====\n"
              << std::endl;
    // Testing size of the class and the total array size when
    // arg constructor is used.

    int size = 3;
    Array<int> my_array(size);

    std::cout << "sizeof class: " << sizeof(my_array[0]) * size << " bytes"
              << std::endl;
    std::cout << "len of array: " << my_array.size() << std::endl;
  }

  {
    std::cout << "\n===== Test 3 : OutOfBoundsException =====\n" << std::endl;

    Array<int> my_array(5);

    std::cout << "len of array: " << my_array.size() << std::endl;

    try {
      my_array[5]; // out of bounds. Last element at index 4.
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }

    try {
      my_array[-1]; // out of bounds (uint32 rolls over to 2147483647)
    } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 4 : Assigning Values Test int =====\n"
              << std::endl;
    // Assigning Values Test for ints

    Array<int> my_array(5);

    std::cout << "len of array: " << my_array.size() << std::endl;

    my_array[0] = 100;
    my_array[1] = 200;
    my_array[2] = 300;
    my_array[3] = 400;
    my_array[4] = 500;

    my_array.print();
  }

  {
    std::cout << "\n===== Test 5 : Assigning Values Test double =====\n"
              << std::endl;
    // Assigning Values Test for doubles

    Array<double> my_array(5);

    std::cout << "len of array: " << my_array.size() << std::endl;

    my_array[0] = 100.1;
    my_array[1] = 200.2;
    my_array[2] = 300.3;
    my_array[3] = 400.4;
    my_array[4] = 500.5;

    my_array.print();
  }

  {
    std::cout << "\n===== Test 6 : Copy Test =====\n" << std::endl;
    // Copy Test

    Array<int> my_array(5);

    my_array[0] = 100;
    my_array[1] = 200;
    my_array[2] = 300;
    my_array[3] = 400;
    my_array[4] = 500;

    Array<int> new_array = my_array;

    // print post copy assignment
    std::cout << "my_array : ";
    my_array.print();

    std::cout << "new_array: ";
    new_array.print();

    // edit a value
    std::cout << "\nChanging value...\n" << std::endl;
    my_array[3] = 10000000;

    // print post edit
    std::cout << "my_array : ";
    my_array.print();

    std::cout << "new_array: ";
    new_array.print();
  }

  {
    std::cout << "\n===== Test 7 : Complex Type =====\n" << std::endl;
    // Complex Type

    Array<std::string> my_array(10);

    my_array[1] = "hi!";
    my_array[7] = "What's up?!";

    my_array.print();
  }

  {
    std::cout << "\n===== Test 8 : Negative size =====\n" << std::endl;
    // Negative size

    // Negative numbers of unsigned ints roll over.
    // Will create valgrind warning because it's too large.
    // We're requesting (2147483647 - 5) * 4 bytes of memory (~8.5 GB).
    // but still runs.

    // Array<float> my_array(-5);
    // std::cout << "negative number test" << std::endl;
  }

  return (0);
}
