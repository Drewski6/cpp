/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/11 23:43:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <string>

int main() {
  std::string dBFileName = "./data.csv";
  BitcoinExchange btc(dBFileName);

  try {
    btc.dBImport();
  } catch (std::exception &ex) {
    std::cout << ex.what() << std::endl;
  }

  std::string strArr[4] = {"2000-01-01", "2018-01-01", "2019-01-01",
                           "2044-01-01"};

  for (int i = 0; i < 4; i++) {
    try {
      std::cout << btc.valueLookup(strArr[i]) << std::endl;
    } catch (std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  return (0);
}
