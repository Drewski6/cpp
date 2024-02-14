/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:47:25 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/14 17:39:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"
#include <iostream>

int main(int argc, char **argv) {
  // Check args
  if (argc != 4) {
    std::cerr << "Error: Incorrect number of arguments.\n"
              << "Usage: ./sifl [filename] [search string] "
                 "[replacement string]"
              << std::endl;
    return (1);
  }

  // Set variables for find and replace function
  char *fileNameCh = argv[1];
  std::string searchStr = argv[2];
  std::string replaceStr = argv[3];

  // Find and replace
  if (findAndReplace(fileNameCh, searchStr, replaceStr))
    return (1);

  return (0);
}
