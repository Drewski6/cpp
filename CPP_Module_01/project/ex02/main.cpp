/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:45:21 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/14 23:02:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
  // assignments
  std::string stringREAL = "HI THIS IS BRAIN";
  std::string *stringPTR = &stringREAL;
  std::string &stringREF = stringREAL;

  // memory addresses
  std::cout << "stringREAL: " << &stringREAL << std::endl;
  std::cout << "stringPTR : " << stringPTR << std::endl;
  std::cout << "stringREF : " << &stringREF << std::endl;

  // values
  std::cout << "stringREAL: " << stringREAL << std::endl;
  std::cout << "stringPTR : " << *stringPTR << std::endl;
  std::cout << "stringREF : " << stringREF << std::endl;

  return (0);
}
