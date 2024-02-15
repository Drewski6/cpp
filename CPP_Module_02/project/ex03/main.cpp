/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 13:47:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  Point p1(0, 0);
  Point p2(5, 0);
  Point p3(0, 5);
  Point point(0, 4);

  // Output to guide user.
  std::cout << "Given a triangle with verticies: " << std::endl;
  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p2: " << p2 << std::endl;
  std::cout << "p3: " << p3 << std::endl;
  std::cout << "Can the point ";
  std::cout << "(point: " << point << ")";
  std::cout << " be found within it's perimeter?" << std::endl;

  // Run bsp and return result.
  std::cout << "Result: " << (bsp(p1, p2, p3, point) ? "true" : "false")
            << std::endl;

  // Additional tests as requested in the subject.
  // Tests on triangle:
  /*
  // 5 | *
  // 4 | |\
  // 3 | | \
  // 2 | |  \
  // 1 | |   \
  // 0 | *----*
  //     012345
  */
  {
    std::cout << "\nTests:" << std::endl;

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(0, 4);
      std::cout << "Test 1 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(4, 0);
      std::cout << "Test 2 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(0, 0);
      std::cout << "Test 3 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(1, 1);
      std::cout << "Test 4 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(1, 4);
      std::cout << "Test 5 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(1.1, 4);
      std::cout << "Test 6 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(0.9, 4);
      std::cout << "Test 7 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(5, 5);
      std::cout << "Test 8 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(-1, -1);
      std::cout << "Test 9 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }

    {
      Point p1(0, 0);
      Point p2(5, 0);
      Point p3(0, 5);
      Point point(5, -4);
      std::cout << "Test 10 Result: "
                << (bsp(p1, p2, p3, point) ? "true" : "false") << std::endl;
    }
  }
  return (0);
}
