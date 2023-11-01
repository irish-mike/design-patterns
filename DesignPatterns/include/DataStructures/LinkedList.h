#pragma once
class LinkedList {
public:
	LinkedList() : first(nullptr), last(nullptr) {};
	~LinkedList();

	void addFirst(int val);
	void addLast(int val);

	void deleteFirst();
	void deleteLast();

	size_t indexOf(int val);
	bool contains(int val);

	bool isEmpty();

private:
	struct Node
	{
		int value = 0;
		Node* next = nullptr;
		Node(int val, Node* nextNode) : value(val), next(nextNode) {}
	};

	Node* first;
	Node* last;
};