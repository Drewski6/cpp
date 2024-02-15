/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 11:03:17 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

  {
    std::cout << "===== Test 1 =====" << std::endl;
    // Example from the subject
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
  }

  {
    std::cout << "\n===== Test 2 =====" << std::endl;
    // Example of default constructor
    Fixed a;
  }

  {
    std::cout << "\n===== Test 3 =====" << std::endl;
    // Example of copy constructor
    Fixed a;
    Fixed b(a);
  }

  {
    std::cout << "\n===== Test 4 =====" << std::endl;
    // Example of copy assignment constructor
    Fixed a;
    Fixed b = a;
  }

  {
    std::cout << "\n===== Test 5 =====" << std::endl;
    // Example of setter and getter
    Fixed a;
    a.getRawBits();
    a.setRawBits(7);
  }

  return 0;
}
