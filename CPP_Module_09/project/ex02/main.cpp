/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/19 15:55:17 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  PmergeMe pme;
  std::vector<int> vec;

  try {
    pme.parseNumsIntoVector(vec, argc, argv);
  } catch (std::exception & ex) {
    std::cout << ex.what() << std::endl;
    return (1);
  }

  pme.printVector(vec);

  return (0);
}
