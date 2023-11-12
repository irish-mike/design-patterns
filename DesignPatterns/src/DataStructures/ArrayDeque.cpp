#include "ArrayDeque.h"
#include <stdexcept>

ArrayDeque::ArrayDeque(int size): size(size) {
    if (size < 0) {
        throw std::invalid_argument("Size must be non-negative");
    }
    queue = new int[size];
}

void ArrayDeque::enqueue(int val) {
    if(isFull()){
        throw std::overflow_error("Queue is full");
    }

    queue[count] = val;
    count++;
}

int ArrayDeque::dequeue() {
    if(isEmpty()){
        throw std::underflow_error("Que is empty");
    }

    int temp = queue[front];
    queue[front] = 0;

    count--;
    front++;

    if(isEmpty()){
        front = 0;
    }else{
        front %= count;
    }

    return temp;
}

int ArrayDeque::peek() const{
    if(isEmpty()){
        throw std::underflow_error("Que is empty");
    }

    return queue[front];
}


bool ArrayDeque::isFull() const{
    return (count == size);
}

bool ArrayDeque::isEmpty() const{
    return (count == 0);
}
