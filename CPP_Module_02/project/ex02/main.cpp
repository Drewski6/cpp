/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:31:00 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/27 13:22:47 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

int main(void) {

  Fixed a;
  // Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  // std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  // std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  // std::cout << b << std::endl;

  // std::cout << Fixed::max(a, b) << std::endl;

  return 0;
}
