#ifndef DATASTRUCTURES_ARRAYDEQUE_H
#define DATASTRUCTURES_ARRAYDEQUE_H


class ArrayDeque {
public:
    explicit ArrayDeque(int size = 10);
    ~ArrayDeque() {delete[] queue;}

    void enqueue(int val);
    int dequeue();

    int peek() const;

    bool isEmpty() const;
    bool isFull() const;

    int getFront() const;
    int getBack() const;

private:
    int* queue;
    int size;

    unsigned int count{0};
    unsigned int front{0};
};


#endif //DATASTRUCTURES_ARRAYDEQUE_H
