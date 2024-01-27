/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:42 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/26 18:41:03 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
public:
  // Constructors , Copy Constructor, Destructor
  Fixed(void);
  Fixed(Fixed const &source);
  ~Fixed(void);

  // Overloaded Operators
  Fixed &operator=(Fixed const &rhs);

  // Getters
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _fixed_num;
  static const int _bin_pnt = 8;
};

#endif // __FIXED_H__
