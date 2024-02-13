/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:42:36 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:03:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

#include <fstream>
#include <iostream>
#include <string>

class Sed {
private:
  std::string fileName;
  std::string fileContents;
  bool hasContent;

  // Private Methods
  void readInFile(std::ifstream &inputFile);
  bool openAndReadFile();

public:
  // Constructor
  Sed(std::string fileNameVal, bool hasContent = false);
  // Destructor
  ~Sed();

  // Public Methods
  void findAndReplace(std::string &search_str, std::string &replace_str);
  void outputContentsToFile();
  bool getHasContent();
};

#endif // SED_H //
