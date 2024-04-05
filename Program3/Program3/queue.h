#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node* nextPtr;
};

//Template class, to create a queue with a linked list.

template<typename T>
class Queue {
private:
	Node<T>* headPtr;
	Node<T>* tailPtr;

public:
	Queue() : headPtr(nullptr), tailPtr(nullptr) {}

	//This print function iterates through the list starting from head node
	//and prints the data stored in each node of linked list until null pointer is reached.

	void print() {
		Node<T>* current = headPtr;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->nextPtr;
		}
		cout << endl;
	}

	//Push function addds new node at end with given value T. 
	//Dynamically allocates memory for new node and updates nextPtr
	//Tailptr is also updated to point to new node.
	//If list is empty, headptr and tailptr are assigned to the new node.

	void push(T value) {
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->nextPtr = nullptr;

		if (headPtr == nullptr) {
			headPtr = tailPtr = newNode;
		}
		else {
			tailPtr->nextPtr = newNode;
			tailPtr = newNode;
		}
	}

	//Pop removes last node from list. If empty, function returns nothing.
	//If only one node, headpt and tailptr set to null.
	//Else, list is traversed to delete last node and updates tailptr to second-to-last node.

	void pop() {
		if (headPtr == nullptr) {
			return; 
		}
		else if (headPtr == tailPtr) {
			delete headPtr;
			headPtr = tailPtr = nullptr;
		}

		else {
			Node<T>* temp = headPtr;
			while (temp->nextPtr != tailPtr) {
				temp = temp->nextPtr;
			}

			delete tailPtr;
			tailPtr = temp;
			tailPtr->nextPtr = nullptr;
		}
	}

	//Front returns the headPtr data, and prints error if the list is empty.

	T front() {
		if (headPtr == nullptr) {
			cout << "Queue is empty.";
		}
		return headPtr->data;
	}
	
	//Size begins a counter variable, and increments for every node until reaching nullptr.

	int size() {
		int count = 0;
		Node<T>* current = headPtr;
		while (current != nullptr) {
			count++;
			current = current->nextPtr;
		}
		return count;
	}

	//Empty functions iterates through list and deletes each node while updating
	//headPtr to point to next node, and once all are deleted tailptr is nullptr.

	void empty() {
		while (headPtr != nullptr) {
			Node<T>* temp = headPtr;
			headPtr = headPtr->nextPtr;
			delete temp;
		}
		tailPtr = nullptr;
	}

	//Move to rear function takes the data of front, updates headptr to 
	//next node, and deletes previous node.
	//Then new node is created with taken data of front and adds to end by updating tailptr.

	void move_to_rear() {
		T frontElement = front();

		Node<T>* current = headPtr;
		headPtr = headPtr->nextPtr;
		delete current;

		Node<T>* newNode = new Node<T>;
		newNode->data = frontElement;
		newNode->nextPtr = nullptr;

		tailPtr->nextPtr = newNode;
		tailPtr = newNode;
	}
};