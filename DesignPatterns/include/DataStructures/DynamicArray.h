//
// Created by Mike Grinnell on 03/11/2023.
//

#ifndef DATASTRUCTURES_DYNAMICARRAY_H
#define DATASTRUCTURES_DYNAMICARRAY_H


class DynamicArray {
public:
    explicit DynamicArray(int size = 10): array(new int[size]), size(size), count(0) {};
    ~DynamicArray(){delete[] array;}

    void insert(int value);
    void removeAt(int index);
    int indexOf(int val);

    void print();

private:
    int* array;
    int size;
    int count;

    void reSize();
};


#endif //DATASTRUCTURES_DYNAMICARRAY_H
