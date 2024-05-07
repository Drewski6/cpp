/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/07 12:05:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main() {
  // main
  {
    std::cout << "\n===== Test 1 : int =====\n" << std::endl;
    // int
    int a = 12;
    int b = 42;

    std::cout << "int: pre-swap : a=" << a << ", b=" << b << std::endl;
    swap(a, b);
    std::cout << "int: post-swap: a=" << a << ", b=" << b << std::endl;
    std::cout << "int: min: " << min(a, b) << std::endl;
    std::cout << "int: max: " << max(a, b) << std::endl;
  }

  {
    std::cout << "\n===== Test 2 : double =====\n" << std::endl;
    // double
    double a = 12.12;
    double b = 42.42;

    std::cout << "double: pre-swap : a=" << a << ", b=" << b << std::endl;
    swap(a, b);
    std::cout << "double: post-swap: a=" << a << ", b=" << b << std::endl;
    std::cout << "double: min: " << min(a, b) << std::endl;
    std::cout << "double: max: " << max(a, b) << std::endl;
  }

  {
    std::cout << "\n===== Test 3 : char =====\n" << std::endl;
    // char
    char a = 'A';
    char b = 'E';

    std::cout << "char: pre-swap : a=" << a << ", b=" << b << std::endl;
    swap(a, b);
    std::cout << "char: post-swap: a=" << a << ", b=" << b << std::endl;
    std::cout << "char: min: " << min(a, b) << std::endl;
    std::cout << "char: max: " << max(a, b) << std::endl;
  }

  {
    std::cout << "\n===== Test 4 : std::string =====\n" << std::endl;
    // std::string
    std::string a = "Ecole";
    std::string b = "42";

    std::cout << "std::string: pre-swap : a=" << a << ", b=" << b << std::endl;
    swap(a, b);
    std::cout << "std::string: post-swap: a=" << a << ", b=" << b << std::endl;
    std::cout << "std::string: min: " << ::min(a, b) << std::endl;
    std::cout << "std::string: max: " << ::max(a, b) << std::endl;
  }

  {
    std::cout << "\n===== Test 5 : Test from subject =====\n" << std::endl;
    // Test from subject

    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // Expected Output
    //
    // a = 3, b = 2
    // min(a, b) = 2
    // max(a, b) = 3
    // c = chaine2, d = chaine1
    // min(c, d) = chaine1
    // max(c, d) = chaine2
  }

  {
    std::cout << "\n===== Test 6 : int (equal) =====\n" << std::endl;

    int a = 42;
    int b = 42;

    std::cout << "int: pre-swap : a=" << a << ", b=" << b << std::endl;
    swap(a, b);
    std::cout << "int: post-swap: a=" << a << ", b=" << b << std::endl;
    std::cout << "int: min: " << min(a, b) << std::endl;
    std::cout << "int: max: " << max(a, b) << std::endl;
  }

  {
    std::cout << "\n===== Test 7 : different types =====\n" << std::endl;
    std::cout << "Most of this test is commented out because it causes compiler errors." << std::endl;

    int a = 42;
    double b = 42.0;

    std::cout << "int/double: pre-swap : a=" << a << ", b=" << b << std::endl;
    // swap(a, b);  // Causes compiler errors
    std::cout << "int/double: post-swap: a=" << a << ", b=" << b << std::endl;
    // std::cout << "int: min: " << min(a, b) << std::endl; // Causes compiler errors
    // std::cout << "int: max: " << max(a, b) << std::endl; // Causes compiler errors
  }

  return (0);
}
