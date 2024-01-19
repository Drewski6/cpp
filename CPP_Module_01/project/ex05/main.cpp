/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:00:16 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/19 18:23:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main() {
  Harl harl;

  harl.complain("shouldn't work");

  harl.complain("debug");
  harl.complain("info");
  harl.complain("warning");
  harl.complain("error");
  return (0);
}
