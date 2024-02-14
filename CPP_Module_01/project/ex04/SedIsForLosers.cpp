/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:03:45 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/14 22:03:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

bool findAndReplace(char *fileNameCh, std::string &searchStr,
                    std::string &replaceStr) {
  // Initial parameter check. searchStr cannot be empty.
  if (searchStr.length() == 0) {
    std::cerr << "Error: No valid search string." << std::endl;
    return (1);
  }

  // Open file.
  std::ifstream inputFile;

  inputFile.open(fileNameCh);
  if (!inputFile.is_open()) {
    std::cerr << "Error: Unable to open file named \"" << fileNameCh
              << "\".\nCheck that it exists and has appropriate permissions."
              << std::endl;
    return (1);
  }

  // Read in file.
  std::string fileContents;
  std::string line;

  for (int i = 0; std::getline(inputFile, line); i++) {
    if (i != 0)
      fileContents += '\n';
    fileContents += line;
  }

  // Close input file.
  inputFile.close();

  // Find and replace
  for (size_t loc = 0; loc != std::string::npos;
       loc = fileContents.find(searchStr, loc + searchStr.length())) {
    if (loc != 0 || (fileContents.find(searchStr) == 0)) {
      fileContents.erase(loc, searchStr.length());
      fileContents.insert(loc, replaceStr);
      loc = loc + replaceStr.length() - searchStr.length();
    }
  }

  // Output to replace file
  std::string outputFileName = fileNameCh;
  outputFileName += ".replace";

  std::ofstream outputFile(outputFileName.c_str());

  if (outputFile.is_open()) {
    outputFile << fileContents << std::endl;
    outputFile.close();
  } else {
    std::cerr << "Error: Unable to create output file." << std::endl;
    return (1);
  }

  return (0);
};
