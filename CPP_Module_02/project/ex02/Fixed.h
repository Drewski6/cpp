/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:42 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/27 13:15:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <cmath>
#include <iostream>

class Fixed {
public:
  // Constructors , Copy Constructor, Destructor
  Fixed(void);
  Fixed(const int num);
  Fixed(const float fnum);
  Fixed(Fixed const &source);
  ~Fixed(void);

  // Overloaded Operators
  Fixed &operator=(Fixed const &rhs);

  // Getters
  int getRawBits(void) const;
  void setRawBits(int const raw);

  // Conversion Functions
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fixedNum;
  static const int _binPnt = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &f);

#endif // __FIXED_H__
