/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:42:44 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/19 15:58:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.h"
// Static Variable Initialization

// Constructors
Sed::Sed(std::string fileNameVal, bool hasContentVal)
    : fileName(fileNameVal), hasContent(hasContentVal) {
  if (this->openAndReadFile()) {
    std::cerr << "Error: File named \"" << fileName
              << "\" could not be opened.\n"
              << "       Please check that the file exists and has appropriate "
                 "permissions."
              << std::endl;
  } else {
    hasContent = true;
  }
};

// Destructor
Sed::~Sed(){};

// Public Methods
void Sed::findAndReplace(std::string &search_str, std::string &replace_str) {
  if (hasContent == false) {
    std::cerr << "Sed object does not contain any content." << std::endl;
    return;
  }
  std::string new_str;

  for (size_t pos = 0;
       (pos = fileContents.find(search_str, pos)) != std::string::npos; pos++) {
    fileContents.erase(pos, search_str.length());
    new_str += fileContents.substr(0, pos);
    new_str += replace_str;
    new_str += fileContents.substr(pos, fileContents.length());
    fileContents = new_str;
    new_str.clear();
  }
  return;
}

void Sed::outputContentsToFile() {
  if (hasContent == false) {
    std::cerr << "Sed object does not contain any content." << std::endl;
    return;
  }

  std::string output_file_name = fileName;

  output_file_name += ".replace";
  std::ofstream output_file(output_file_name.c_str());
  if (output_file.is_open()) {
    output_file << fileContents << std::endl;
    output_file.close();
  }
}

bool Sed::getHasContent() { return hasContent; }

// Private Methods
void Sed::readInFile(std::ifstream &inputFile) {
  std::string line;

  for (int i = 0; std::getline(inputFile, line); i++) {
    if (i != 0)
      fileContents += '\n';
    fileContents += line;
  }
}

bool Sed::openAndReadFile() {
  std::ifstream inputFile;
  inputFile.open(fileName.c_str());
  if (!inputFile.is_open()) {
    return (1);
  }
  Sed::readInFile(inputFile);
  inputFile.close();
  return (0);
};
