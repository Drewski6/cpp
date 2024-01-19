/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:00:16 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/19 20:30:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

bool checkArgs(int argc) {
  if (argc != 2) {
    return (1);
  }
  return (0);
}

int main(int argc, char **argv) {
  if (checkArgs(argc))
    return (1);

  Harl harl;
  std::string level = argv[1];

  harl.complain(level);
  return (0);
}
