/*
	Badajoz, Seve

	CS A200
	Febuary 7, 2018

	Lab 02
*/

#include "DoublyList.h"

// Definition copy constructor
DoublyList::DoublyList(const DoublyList& other) {
	Node* curr = other.first;
	while (curr != nullptr) {
		insertBack(curr->getData());
		curr = curr->getNext();
	}
}

// Definition move constructor
DoublyList::DoublyList(DoublyList&& other) {
	first = other.first;
	last = other.last;
	count = other.count;
	other.first = nullptr;
	other.last = nullptr;
	other.count = 0;
}

// Definition overloaded assignment operator
DoublyList& DoublyList::operator=(const DoublyList& other) {
	destroyList();
	count = other.count;
	if (count != 0)
		first = new Node(*other.first);
	else
		first = nullptr;
	Node* curr = other.first;
	while (curr != nullptr) {
		insertBack(curr->getData());
		curr = curr->getNext();
	}
	return *this;
}

// Definition move assignment operator
DoublyList& DoublyList::operator=(DoublyList&& other) {
	destroyList();
	count = other.count;
	first = other.first;
	last = other.last;
	other.first = nullptr;
	other.last = nullptr;
	other.count = 0;

	return *this;
}

// Definition switchEveryTwo
void DoublyList::switchEveryTwo() {
	int newCount = count;
	Node* curr = first;
	Node* temp;
		if (count % 2 != 0) newCount -= 1;
		for (int i = 0; i < newCount; i += 2, curr = curr->getNext()) {
			temp = new Node(*curr);

			curr->setPrev(curr->getNext());
			curr->setNext(curr->getNext()->getNext());

			curr->getPrev()->setNext(curr);

			if (i == 0)
				first = temp->getNext();
			else
				curr->getPrev()->setPrev(temp->getPrev());
		}
		
		first->setPrev(nullptr);
		
		if (newCount != count) {
			Node* temp = first;
			first = last;
			last = temp;
		} else {
			last = curr;
	}
}
