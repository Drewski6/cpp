/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:23:26 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/02 22:54:15 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  std::string in_str;

  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; i++)
      in_str += argv[i];
    for (size_t i = 0; i < in_str.length(); i++)
      in_str.at(i) = std::toupper(in_str.at(i));
  }

  std::cout << in_str << std::endl;
  return (0);
}
