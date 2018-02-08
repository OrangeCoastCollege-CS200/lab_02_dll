#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), prev(nullptr), next(nullptr) {}
    Node (int theData, Node *previous, Node *next)
            : data(theData), next(next), prev(previous) {}
    Node *getNext( ) const { return next; }
    Node *getPrev( ) const { return prev; }
    int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setNext(Node *pointer) { next = pointer; }
    void setPrev(Node *pointer) { prev = pointer; }
	~Node(){}
private:
    int data;
    Node *next;
    Node *prev;
};


class DoublyList
{
	friend ostream& operator<<(ostream& out, const DoublyList& list);

public:
	DoublyList(); 	

	void insertBack(int newData);

	bool isEmpty() const;
	
	const DoublyList* addressObject() const;
	const Node* addressFirst() const;
	const Node* addressLast() const;
	int getNumOfElem() const;

	void reversePrint() const;

	void destroyList();
	~DoublyList();
	
	// Declaration copy constructor
	

	// Declaration move constructor
	

	// Declaration overloaded assignment operator
	

	// Declaration move assignment operator
	

	// Declaration switchEveryTwo
	

private:
    Node *first;	
    Node *last;		
	int count;		
};

#endif