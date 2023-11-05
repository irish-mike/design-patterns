#include "DataStructures/DynamicArray.h"
#include <iostream>


void DynamicArray::insert(int value) {
    if(count >= size) reSize();

    array[count++] = value;
}

void DynamicArray::removeAt(int index) {
    
    if (count <= 0) {
        throw std::out_of_range("Cannot remove from an empty array");
    };
    
    if(index < 0 || index >= count){
        throw std::invalid_argument("Index out of bounds");
    };

    // Shift elements after the index to the left to fill the gap created by removal
    for (int i = index; i < count ; ++i) {
        array[i] = array[i +1];
    }

    count--;
}

int DynamicArray::indexOf(int val) {

    for (int i=0; i< count; i++){
        if (array[i] == val) return i;
    }

    return -1; // Return -1 if the value is not found in the array
}

void DynamicArray::reSize() {

    size *= 2;
    int* newArray = new int[size];

    for (int i=0; i< count; i++){
        newArray[i] = array[i];
    }

    delete[] array; // Deallocate memory for the old array
    array = newArray; // Update the array pointer to the new array
}

int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}