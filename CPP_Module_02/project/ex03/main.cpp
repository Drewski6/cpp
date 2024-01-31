/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/31 20:36:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  Point p1(0, 0);
  Point p2(5, 0);
  Point p3(0, 4);
  Point point(2, 2);

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
  {
    std::cout << "Tests:" << std::endl;
    // insert tests here
  }
  return (0);
}
