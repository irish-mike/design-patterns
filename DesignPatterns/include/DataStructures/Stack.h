//
// Created by Mike Grinnell on 08/11/2023.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H


class Stack {
public:
    explicit Stack(int size = 10);
    ~Stack() { delete[] stack;};


    void push(int val);
    int pop();
    int peek() const;
    bool isEmpty() const;

private:
    int* stack;
    int size;
    int count;
};


#endif //DATASTRUCTURES_STACK_H
