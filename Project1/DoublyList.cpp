#include "DoublyList.h"

ostream& operator<<(ostream& out, const DoublyList& list)
{
	Node *temp = list.first;
	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	return out;
}

DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

void DoublyList::insertBack(int newData)
{
	Node *newNode = new Node(newData, last, nullptr);

	if (first == nullptr)
		first = newNode;
	else
		last->setNext(newNode);

	last = newNode;
	++count;
}

bool DoublyList::isEmpty() const
{
	return (first == nullptr);
}

const DoublyList* DoublyList::addressObject() const
{
	return this;
}

const Node* DoublyList::addressFirst() const
{
	return first;
}

const Node* DoublyList::addressLast() const
{
	return last;
}

int DoublyList::getNumOfElem() const
{
	return count;
}

void DoublyList::reversePrint() const
{
	Node *temp = last;
	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getPrev();
	}
}

void DoublyList::destroyList()
{
	Node *temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	last = nullptr;
	count = 0;
}

DoublyList::~DoublyList()
{
	destroyList();
}
