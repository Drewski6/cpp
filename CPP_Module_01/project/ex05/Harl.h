/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:00:25 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:03:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl {
private:
  typedef void (Harl::*fPtr)();

  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

public:
  Harl();
  ~Harl();
  void complain(std::string level);
};

#endif // HARL_H //
