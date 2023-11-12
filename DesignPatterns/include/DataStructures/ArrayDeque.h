//
// Created by Mike Grinnell on 08/11/2023.
//

#ifndef DATASTRUCTURES_ARRAYDEQUE_H
#define DATASTRUCTURES_ARRAYDEQUE_H


class ArrayDeque {
public:
    explicit ArrayDeque(int size = 10);

    void enqueue(int val);
    int dequeue();

    int peek() const;

    bool isEmpty() const;
    bool isFull() const;

private:
    int* queue;
    int size;

    unsigned int count{0};
    unsigned int front{0};
};


#endif //DATASTRUCTURES_ARRAYDEQUE_H
