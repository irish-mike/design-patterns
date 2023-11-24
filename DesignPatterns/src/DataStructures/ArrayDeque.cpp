#include "Datastructures/ArrayDeque.h"
#include <stdexcept>

ArrayDeque::ArrayDeque(int size): size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    queue = new int[size];
}

void ArrayDeque::enqueue(int val) {
    if(isFull()){
        throw std::overflow_error("Queue is full");
    }

    queue[getBack()] = val;
    count++;
}

int ArrayDeque::dequeue() {
    if(isEmpty()){
        throw std::underflow_error("Queue is empty");
    }

    int val = queue[getFront()];

    queue[getFront()] = 0;
    count--;
    front++;

    return val;
}

int ArrayDeque::peek() const{
    if(isEmpty()){
        throw std::underflow_error("Queue is empty");
    }

    return queue[front];
}


bool ArrayDeque::isFull() const{
    return (count == size);
}

int ArrayDeque::getFront() const
{
    return front % size;
}

int ArrayDeque::getBack() const
{
    return (front + count) % size;
}

bool ArrayDeque::isEmpty() const{
    return (count == 0);
}
