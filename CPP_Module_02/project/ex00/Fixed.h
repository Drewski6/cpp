/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:42 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 11:26:29 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

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

#endif // FIXED_H //
