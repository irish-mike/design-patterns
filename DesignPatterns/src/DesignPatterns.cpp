#include <iostream>
#include "DataStructures/LinkedList.h"
#include "DataStructures/DynamicArray.h"
#include "Utils.h";


int main()
{
    LinkedList list;
    DynamicArray array(10);

    list.addFirst(10);
    list.addFirst(0);
    list.addFirst(-10);

    list.addLast(20);
    
    std::cout << "Linked List: ";
    Utils::print(list);
    std::cout << std::endl;

    for (int i = 0; i < 15; i++)
    {
        array.insert(i);
    }
    array.insert(-100);
    array.insert(0);
    array.insert(100);

    std::cout << "Dynamic Array: ";
    Utils::print(array);
    std::cout << std::endl;


    return 0;
}
