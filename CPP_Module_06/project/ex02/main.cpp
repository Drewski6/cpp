/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/15 19:21:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  std::srand(std::time(NULL));
  int randNum = std::rand() % 3;

  switch (randNum) {
  case (0):
    return (new A);
    break;
  case (1):
    return (new B);
    break;
  case (2):
    return (new C);
    break;
  default: // default should never happen due to % 3
    return (NULL);
    break;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "ptr: class is of type: A" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "ptr: class is of type: B" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "ptr: class is of type: C" << std::endl;
  else
    std::cout << "ptr: error: not derived from Base" << std::endl;
};

void identify(Base &p) {
  try {
    A &retA = dynamic_cast<A &>(p);
    std::cout << "ref: class is of type: A" << std::endl;
    (void)retA;
  } catch (const std::exception &ex) {
    try {
      B &retB = dynamic_cast<B &>(p);
      std::cout << "ref: class is of type: B" << std::endl;
      (void)retB;
    } catch (const std::exception &ex) {
      try {
        C &retC = dynamic_cast<C &>(p);
        std::cout << "ref: class is of type: C" << std::endl;
        (void)retC;
      } catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
      }
    }
  }
  return;
};

int main() {
  {
    std::cout << "\n===== Test 1 : Test =====\n" << std::endl;

    Base *base_ptr = generate();

    // Pass base_ptr (Base *)to identify
    identify(base_ptr);

    // Pass base_ref (Base &)to identify
    identify(*base_ptr);

    delete base_ptr;
  }

  return (0);
}
