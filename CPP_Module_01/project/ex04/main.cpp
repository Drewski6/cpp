/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:47:25 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/18 17:27:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void readInFile(std::ifstream &input_file, std::string &file_contents) {
  std::string line;
  int i = 0;

  while (std::getline(input_file, line)) {
    if (i != 0)
      file_contents += '\n';
    file_contents += line;
    i++;
  }
}

void findAndReplace(std::string &input_str, std::string &search_str,
                    std::string &replace_str) {
  std::string new_str;
  size_t pos = 0;
  while ((pos = input_str.find(search_str, pos)) != std::string::npos) {
    input_str.erase(pos, search_str.length());
    new_str += input_str.substr(0, pos);
    new_str += replace_str;
    new_str += input_str.substr(pos, input_str.length());
    input_str = new_str;
    new_str.clear();
    pos += 1;
  }
  return;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Error: Incorrect number of arguments.\n"
              << "Usage: ./sed_is_for_losers [filename] [search string] "
                 "[replacement string]"
              << std::endl;
    return (1);
  }

  std::ifstream input_file;
  input_file.open(argv[1]);
  if (!input_file.is_open()) {
    std::cerr << "Error: File named " << argv[1] << " could not be opened."
              << std::endl;
    return (1);
  }
  std::string file_contents;
  readInFile(input_file, file_contents);
  input_file.close();

  std::string search_str = argv[2];
  std::string replace_str = argv[3];
  findAndReplace(file_contents, search_str, replace_str);

  std::string output_file_name = argv[1];
  output_file_name += ".replace";
  std::ofstream output_file(output_file_name.c_str());
  if (output_file.is_open()) {
    output_file << file_contents << std::endl;
    output_file.close();
  }

  return (0);
}
