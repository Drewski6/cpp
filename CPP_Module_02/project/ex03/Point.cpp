/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:54:54 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 13:05:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors , Copy Constructor, Destructor
Point::Point(void) : _x(0), _y(0){};
Point::Point(const float x_val, const float y_val) : _x(x_val), _y(y_val){};

Point::Point(Point const &source) : _x(source._x), _y(source._y){};
Point::~Point(void){};

// Overloaded Operators
Point &Point::operator=(Point const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, Point const &p) {
  os << "X: " << p.getX().toFloat() << " Y: " << p.getY().toFloat();
  return os;
};

// Public Methods
Fixed Point::getX() const { return _x; };
Fixed Point::getY() const { return _y; };

// Private Methods
