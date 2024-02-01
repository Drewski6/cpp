/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:54:45 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 11:27:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

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
  Fixed _x;
  Fixed _y;
};

std::ostream &operator<<(std::ostream &os, Point const &p);

#endif // POINT_H //
