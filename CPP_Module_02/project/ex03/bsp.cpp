/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:54:40 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 13:09:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float areaTriangle(Point const a, Point const b, Point const c) {
  // Formula: 0.5 * abs( x0(y1 - y2) + x1(y2 - y0) + x2(y0 - y1) )
  float ret =
      (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
       (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
       (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) *
      0.5;
  if (ret < 0)
    ret *= -1;
  return ret;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  const float areaT1 = areaTriangle(point, b, c);
  const float areaT2 = areaTriangle(a, point, c);
  const float areaT3 = areaTriangle(a, b, point);
  const float areaTOrig = areaTriangle(a, b, c);

  // Print statements for debugging if you want...
  // std::cout << "areaT1: " << areaT1 << std::endl;
  // std::cout << "areaT2: " << areaT2 << std::endl;
  // std::cout << "areaT3: " << areaT3 << std::endl;
  // std::cout << "areaTOrig: " << areaTOrig << std::endl;

  // If area of any are 0 that means point is on the edge or vertex.
  // false condition
  if (!areaT1 || !areaT2 || !areaT3)
    return (false);

  // If sum of 3 triangles is greater than original, then point is outside.
  // false
  if ((areaT1 + areaT2 + areaT3) > areaTOrig)
    return (false);

  // else, true
  return (true);
}
