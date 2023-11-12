//
// Created by Mike Grinnell on 08/11/2023.
//
#include <iostream>
#include "Stack.h"

Stack::Stack(int size) : size(size), count(0) {
    if (size < 0) {
        throw std::invalid_argument("Size must be non-negative");
    }
    stack = new int[size];
}

void Stack::push(int val) {
    if(count >= size){
        throw std::overflow_error("Stack is Full");
    }

    stack[count++] = val;
}

int Stack::pop() {
    if(isEmpty()){
        throw std::underflow_error("Stack is Empty");
    }

    int tmp = stack[--count];
    stack[count] = 0;
    return tmp;
}

int Stack::peek() const {
    if(isEmpty()){
        throw std::underflow_error("Stack is Empty");
    }

    return stack[count-1];
}

bool Stack::isEmpty() const {
    return count == 0;
}



