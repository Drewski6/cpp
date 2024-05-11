/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/11 13:30:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

int main(int argc, char **argv) {
  // main
  if (argc != 2) {
    std::cout << "Error: wrong number of arguments." << std::endl;
    return (1);
  }

  std::string input_str = argv[1];

  try {
    RPN rpn(input_str);
    rpn.parseInput();
    std::cout << rpn.evaluate() << std::endl;
  } catch (std::exception & ex) {
    std::cout << ex.what() << std::endl;
  }

  return (0);
}
