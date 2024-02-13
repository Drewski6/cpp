/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:47:25 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 17:21:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.h"
#include <iostream>

bool checkArgs(int argc) {
  if (argc != 4) {
    std::cerr << "Error: Incorrect number of arguments.\n"
              << "Usage: ./sed_is_for_losers [filename] [search string] "
                 "[replacement string]"
              << std::endl;
    return (1);
  }
  return (0);
}

int main(int argc, char **argv) {
  if (checkArgs(argc))
    return (1);

  {
    std::string fileNameStr = argv[1];
    std::string searchStr = argv[2];
    std::string replaceStr = argv[3];

    if (fileNameStr.length() == 0 || searchStr.length()  == 0 || replaceStr.length() == 0)
    {
      std::cout << "Error: Arguments cannot be empty strings." << std::endl;
      return (1);
    }

    Sed sedFile(fileNameStr);
    if (sedFile.getHasContent()) {
      sedFile.findAndReplace(searchStr, replaceStr);
      sedFile.outputContentsToFile();
    }
  }

  return (0);
}
