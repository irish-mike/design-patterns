#include "utils.h"
#include <iostream>

void Utils::print(DynamicArray& dynamicArray) {

    for (int i = 0; i < dynamicArray.getCount(); i++) {
        std::cout << dynamicArray[i] << ", ";
    }
    std::cout << std::endl;
}

void Utils::print(LinkedList& linkedList) {
    LinkedList::Node* current = linkedList.getFirst();

    while (current != nullptr) {
        std::cout << current->value << ", ";
        current = current->next;
    }

    std::cout << std::endl;
}