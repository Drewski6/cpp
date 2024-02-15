/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 11:53:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

  {
    std::cout << "\n===== Test 1 =====" << std::endl;
    // Example from subject
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  }

  {
    std::cout << "\n===== Test 2 =====" << std::endl;
    // toInt test
    Fixed a(42);
    std::cout << "toInt  : " << a.toInt() << std::endl;
    std::cout << "raw Int: " << a.getRawBits() << std::endl;
  }

  {
    std::cout << "\n===== Test 3 =====" << std::endl;
    // toFloat test
    Fixed a(42.42f);
    std::cout << "toFloat  : " << a.toFloat() << std::endl;
    std::cout << "raw Fixed: " << a.getRawBits() << std::endl;
  }

  return 0;
}
