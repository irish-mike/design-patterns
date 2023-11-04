#include <iostream>
#include "DataStructures/LinkedList.h"


void testLinkedList() {
    // Test cases for LinkedList class

    LinkedList list;

    // Testing addFirst and addLast
    list.addFirst(10);  // List: 10
    list.addFirst(5);   // List: 5 -> 10
    list.addLast(15);   // List: 5 -> 10 -> 15
    list.addLast(20);   // List: 5 -> 10 -> 15 -> 20

    // Testing deleteFirst and deleteLast
    list.deleteFirst(); // List: 10 -> 15 -> 20
    list.deleteLast();  // List: 10 -> 15

    // Testing indexOf and contains
    size_t index = list.indexOf(15);
    if (index != std::string::npos) {
        std::cout << "Value 15 found at index " << index << std::endl;
    }
    else {
        std::cout << "Value 15 not found" << std::endl;
    }

    if (list.contains(10)) {
        std::cout << "Value 10 is present in the list" << std::endl;
    }
    else {
        std::cout << "Value 10 is not present in the list" << std::endl;
    }

    if (list.contains(20)) {
        std::cout << "Value 20 is present in the list" << std::endl;
    }
    else {
        std::cout << "Value 20 is not present in the list" << std::endl;
    }

    // Edge cases
    LinkedList emptyList;

    try {
        emptyList.deleteFirst(); // Trying to delete from an empty list
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        emptyList.deleteLast(); // Trying to delete from an empty list
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        emptyList.contains(10); // Trying to search in an empty list
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    testLinkedList();

    return 0;
}
