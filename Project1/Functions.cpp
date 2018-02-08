/*
	Badajoz, Seve

	CS A200
	Febuary 7, 2018

	Lab 02
*/

#include "DoublyList.h"

// Definition copy constructor
DoublyList::DoublyList(const DoublyList& other) {
	count = other.count;
	first = new Node(*other.first);
	Node* curr = other.first;
	while (++curr != nullptr)
		insertBack(curr->getData());
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
DoublyList DoublyList::operator=(const DoublyList& other) {
	delete first;
	delete last;
	count = other.count;
	first = new Node(*other.first);
	Node* curr = other.first;
	while (++curr != nullptr)
		insertBack(curr->getData());
}

// Definition move assignment operator
DoublyList DoublyList::operator=(DoublyList&& other) {
	delete first;
	delete last;
	count = other.count;
	first = other.first;
	last = other.last;
	other.first = nullptr;
	other.last = nullptr;
	other.count = 0;
}

// Definition switchEveryTwo
void DoublyList::switchEveryTwo()const {

}
