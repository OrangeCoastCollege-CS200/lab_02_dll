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
	if (count < 2)
		cout << "List is too small (Must have at least two nodes)";
	else {
		Node * temp = first;
		Node * curr = first->getNext();
		while (temp != nullptr && curr != nullptr) {
			curr->setPrev(temp->getPrev());
			if (curr->getPrev() != nullptr) curr->getPrev()->setNext(curr);
			temp->setPrev(curr);
			temp->setNext(curr->getNext());
			curr->setNext(temp);
			if (temp->getNext() != nullptr) temp->getNext()->setPrev(temp);
			temp = temp->getNext();
			if (temp != nullptr) curr = temp->getNext();
		}
		if (count % 2 == 0) {
			last = last->getNext();
			first = first->getPrev();
		}
		else {
			last = last->getPrev();
			last->setNext(nullptr);
			temp->setPrev(nullptr);
			temp->setNext(first->getNext());
			first->getPrev()->setPrev(temp);
			first = temp;
		}
	}
}

