/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:42:43 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/17 14:20:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *array_ptr, unsigned int array_len, void (*f)(T &)) {
  for (unsigned int i = 0; i < array_len; i++) {
    f(array_ptr[i]);
  }
  return;
}

template <typename T> void print(T &a) {
  // print
  std::cout << a << " ";
};

template <typename T> void addOne(T &a) {
  // increment
  a++;
}
