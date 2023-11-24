#include <iostream>
#include "DataStructures/LinkedList.h"
#include "DataStructures/DynamicArray.h"
#include "DataStructures/ArrayDeque.h"
#include "Utils.h";

#include "Exercises.h"

#include <string>

int main()
{
    std::string s = "hungryforapples";
    Excercises::findFirstRepeatingChar(s);

    s = "aabbccdeeffghhi";
    Excercises::findFirstRepeatingChar(s);


    return 0;
}
