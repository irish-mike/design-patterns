#include <stdexcept>

#include "DataStructures/LinkedList.h"

// Destructor to clean up memory when the linked list is destroyed
LinkedList::~LinkedList()
{
    while (!isEmpty()) {
        deleteFirst();
    }
}

// Adds a new node with the given value to the beginning of the list
void LinkedList::addFirst(int val)
{
    Node* n = new Node(val, nullptr);

    // If list is empty, set both first and last pointers to the new node
    if (isEmpty()) {
        this->first = n;
        this->last = n;
    }
    else {
        n->next = this->first;
        this->first = n;
    }
}

// Adds a new node with the given value to the end of the list
void LinkedList::addLast(int val)
{
    Node* n = new Node(val, nullptr);

    // If list is empty, set both first and last pointers to the new node
    if (isEmpty()) {
        this->first = this->last = n;
    }
    else {
        this->last->next = n;
        this->last = n;
    }
}

// Deletes the first node from the list
void LinkedList::deleteFirst()
{
    if (isEmpty()) {
        throw std::runtime_error("Cannot delete from an empty list");
    }

    Node* temp = this->first;
    this->first = this->first->next;

    if (this->first == nullptr) {
        this->last = nullptr;
    }

    delete temp;
}

// Deletes the last node from the list
void LinkedList::deleteLast()
{
    if (isEmpty()) {
        throw std::runtime_error("Cannot delete from an empty list");
    }

    if (this->first->next == nullptr) {
        delete this->first;
        this->first = this->last = nullptr;
        return;
    }

    Node* prev = nullptr;
    Node* current = this->first;

    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;
    this->last = prev;
    delete current;
}

// Finds the index of the first occurrence of the given value in the list
size_t LinkedList::indexOf(int val)
{
    Node* n = this->first;
    size_t count = 0;

    while (n != nullptr)
    {
        if (n->value == val) {
            return count;
        }
        n = n->next;
        count++;
    }

    return std::string::npos; // Not found
}


// Checks if the list contains the given value
bool LinkedList::contains(int val)
{
    return indexOf(val) != -1; // Changed to size_t
}

// Checks if the list is empty
bool LinkedList::isEmpty()
{
    return this->first == nullptr && this->last == nullptr;
}
