/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/04/01 16:11:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2 || *(argv[1]) == 0) {
    std::cout << "Error: Invalid arguments.\n"
              << "Usage: ./convert [char, int, float, or double]" << std::endl;
    return (1);
  }

  ScalarConverter::convert(argv[1]);

  return (0);
}
