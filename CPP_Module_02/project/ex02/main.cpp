/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 12:50:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

  {
    std::cout << "===== Test 1 : Subject =====" << std::endl;
    // Example from the subject.
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
    std::cout << "\n===== Test 2 : Comparison Operators =====" << std::endl;
    // Test Comparison Operators
    Fixed first(123.123f);
    Fixed second(321.321f);
    Fixed third(123.123f);

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

    std::cout << "Testing == Operator (not equal)\n"
              << "Float: " << (123.123f == 321.321f) << "\n"
              << "Fixed: " << (first == second) << std::endl;

    std::cout << "Testing == Operator (equal)\n"
              << "Float: " << (123.123f == 123.123f) << "\n"
              << "Fixed: " << (first == third) << std::endl;

    std::cout << "Testing != Operator\n"
              << "Float: " << (123.123f != 321.321f) << "\n"
              << "Fixed: " << (first != second) << std::endl;
  }

  {
    std::cout << "\n===== Test 3 : Mathmatical Operators =====" << std::endl;
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
    std::cout << "\n===== Test 4 : Increment/Decrement Operators ====="
              << std::endl;
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
    std::cout << "\n===== Test 5 : Static Functions (min/max) ====="
              << std::endl;
    // Static Functions
    Fixed a(8);
    Fixed b(11);
    const Fixed c(9);
    const Fixed d(18);

    std::cout << "       a: " << a << std::endl;
    std::cout << "       b: " << b << std::endl;
    std::cout << "[const]c: " << c << std::endl;
    std::cout << "[const]d: " << d << std::endl;
    std::cout << std::endl;

    std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "Fixed::max(a, a): " << Fixed::max(a, a) << std::endl;
    std::cout << "Fixed::min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << std::endl;

    std::cout << "Fixed::max([const]c, [const]d): " << Fixed::max(c, d)
              << std::endl;
    std::cout << "Fixed::min([const]c, [const]d): " << Fixed::min(c, d)
              << std::endl;
    std::cout << std::endl;

    std::cout << "Fixed::max(a, [const]d): " << Fixed::max(a, d) << std::endl;
    std::cout << "Fixed::min(a, [const]d): " << Fixed::min(a, d) << std::endl;
    std::cout << std::endl;

    std::cout << "Fixed::max([const]c, b): " << Fixed::max(c, b) << std::endl;
    std::cout << "Fixed::min([const]c, b): " << Fixed::min(c, b) << std::endl;
  }

  {
    std::cout << "\n===== Test 6 : Division by Zero =====" << std::endl;
    // Division by Zero
    Fixed a(0);

    std::cout << "a / 0: " << (a / 0) << std::endl;
  }

  return (0);
}
