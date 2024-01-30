/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/30 21:21:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

int main(void) {

  {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
  }

  {
    // Test Comparison Operators
    Fixed first(123.123f);
    Fixed second(321.321f);

    std::cout << "Testing > Operator\n"
              << "Float: " << (123.123f > 321.321f) << "\n"
              << "Fixed: " << (first > second) << std::endl;

    std::cout << "Testing < Operator\n"
              << "Float: " << (123.123f < 321.321f) << "\n"
              << "Fixed: " << (first < second) << std::endl;

    std::cout << "Testing >= Operator\n"
              << "Float: " << (123.123f >= 321.321f) << "\n"
              << "Fixed: " << (first >= second) << std::endl;

    std::cout << "Testing <= Operator\n"
              << "Float: " << (123.123f <= 321.321f) << "\n"
              << "Fixed: " << (first <= second) << std::endl;

    std::cout << "Testing == Operator\n"
              << "Float: " << (123.123f == 321.321f) << "\n"
              << "Fixed: " << (first == second) << std::endl;

    std::cout << "Testing != Operator\n"
              << "Float: " << (123.123f != 321.321f) << "\n"
              << "Fixed: " << (first != second) << std::endl;
  }

  {
    // Test Mathmatical Operators
    Fixed first(5.5f);
    Fixed second(7.8f);
    float f_first = 5.5f;
    float f_second = 7.8f;

    std::cout << "first: " << first << std::endl;
    std::cout << "second: " << second << std::endl;
    std::cout << "first + second: " << (first + second) << std::endl;
    std::cout << "f_first + f_second: " << (f_first + f_second) << std::endl;
    std::cout << "first - second: " << (first - second) << std::endl;
    std::cout << "f_first - f_second: " << (f_first - f_second) << std::endl;
    std::cout << "first * second: " << (first * second) << std::endl;
    std::cout << "f_first * f_second: " << (f_first * f_second) << std::endl;
    std::cout << "first / second: " << (first / second) << std::endl;
    std::cout << "f_first / f_second: " << (f_first / f_second) << std::endl;
  }

  {
    // Test Increment/Decrement Operators
    Fixed a(8);
    Fixed b(11);

    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "--b: " << --b << std::endl;

    std::cout << "a: " << a << std::endl;
    a++;
    std::cout << "a++: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    b--;
    std::cout << "b--: " << b << std::endl;
  }

  {
    // Static Functions
    Fixed a(8);
    Fixed b(11);

    std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "Fixed::max(a, a): " << Fixed::max(a, a) << std::endl;
    std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
  }

  {
    // Division by Zero
    Fixed a(0);

    std::cout << "a / 0: " << (a / 0) << std::endl;
  }

  return (0);
}
