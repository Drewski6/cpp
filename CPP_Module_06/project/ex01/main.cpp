/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/05 21:26:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {

  {
    std::cout << "\n===== Test 1 : Stack Test =====\n" << std::endl;

    Data data_stk;

    data_stk.data = 42;

    uintptr_t serialized = Serializer::serialize(&data_stk);
    Data *data_ptr = Serializer::deserialize(serialized);

    std::cout << "&data_stk   : " << &data_stk << std::endl;
    std::cout << "serialized  : " << serialized << std::endl;
    std::cout << "data_ptr    : " << data_ptr << std::endl;
    std::cout << "data_stk val: " << data_stk.data << std::endl;
    std::cout << "data_ptr val: " << data_ptr->data << std::endl;
    std::cout << "Does pre-serialized data equal deserialized data: "
              << (&data_stk == data_ptr ? "true" : "false") << std::endl;
  }

  {
    std::cout << "\n===== Test 2 : Heap Test =====\n" << std::endl;

    Data *data_heap = new Data;

    data_heap->data = 12345;

    uintptr_t serialized = Serializer::serialize(data_heap);
    Data *data_ptr2 = Serializer::deserialize(serialized);

    std::cout << "data_heap    : " << data_heap << std::endl;
    std::cout << "serialized   : " << serialized << std::endl;
    std::cout << "data_ptr2    : " << data_ptr2 << std::endl;
    std::cout << "data_heap val: " << data_heap->data << std::endl;
    std::cout << "data_ptr2 val: " << data_ptr2->data << std::endl;
    std::cout << "Does pre-serialized data equal deserialized data: "
              << (data_heap == data_ptr2 ? "true" : "false") << std::endl;

    delete data_heap;
  }

  return (0);
}
