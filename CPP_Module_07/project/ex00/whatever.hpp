/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:56:53 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/17 13:18:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void swap(T &a, T &b) {
  // swap template function
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> T min(T a, T b) {
  // min template function
  return (a < b) ? a : b;
}

template <typename T> T max(T a, T b) {
  // min template function
  return (a > b) ? a : b;
}
