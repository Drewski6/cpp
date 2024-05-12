/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/12 13:53:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // check args
  if (argc != 2) {
    std::cout << "Error: Usage ./btc [inputFile]" << std::endl;
    return (1);
  }
  // Open file
  std::ifstream inputFile(argv[1]);
  // Check that file is open
  if (inputFile.is_open() != true) {
    std::cout << "Error: could not open input file '" << argv[1] << "'"
              << std::endl;
    return (1);
  }
  // set database file name and init btc class
  std::string dBFileName = "./data.csv";
  BitcoinExchange btc(dBFileName);
  // Import database
  try {
    btc.dBImport();
  } catch (std::exception &ex) {
    std::cout << ex.what() << std::endl;
  }
  // Evaluate each line of the input file.
  std::string line;
  while (std::getline(inputFile, line)) {
    try {
      if (line == "date | value")
        continue;
      std::cout << btc.evaluateOutput(line) << std::endl;
    } catch (std::exception &ex) {
      std::cout << ex.what() << std::endl;
    }
  }
  // close file and return
  inputFile.close();
  return (0);
}
