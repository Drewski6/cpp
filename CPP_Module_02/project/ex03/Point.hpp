/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:54:45 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 13:06:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
public:
  // Constructors , Copy Constructor, Destructor
  Point(void);
  Point(const float x_val, const float y_val);

  Point(Point const &source);
  ~Point(void);

  // Overloaded Operators
  Point &operator=(Point const &rhs);

  // Public methods
  Fixed getX(void) const;
  Fixed getY(void) const;

private:
  Fixed const _x;
  Fixed const _y;
};

std::ostream &operator<<(std::ostream &os, Point const &p);
