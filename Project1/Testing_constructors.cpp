#include "Testing_constructors.h"

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> v1 = { 
	{  },
	{ 1 },
	{ 1, 2 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
};

void test_copyConstructor()
{
	cout << "/*********************************************************/\n"; 
	cout << "     TEST: COPY CONSTRUCTOR" << endl;
	cout << "/*********************************************************/\n";
	
	int sizeV1 = static_cast<int>(v1.size());

	for (int i = 0; i < sizeV1; ++i)
	{
		DoublyList list1;
		int elements = static_cast<int>(v1[i].size());

		for (int j = 0; j < elements; ++j)
			list1.insertBack(v1[i].at(j));
		
		if (list1.isEmpty()) cerr << "\nList1: (empty)";
		else cout << "\nList1: " << list1;
		cout << "\n=> Use copy constructor to create list2...";
		DoublyList list2(list1);
		if (list2.isEmpty()) cerr << "\nList2: (empty)";
		else cout << "\nList2: " << list2;
		cout << "\n\n=> Check printing in reverse...";
		if (list1.isEmpty()) cerr << "\nList1: empty";
		else
		{
			cout << "\nList1 (backwards): ";
			list1.reversePrint();
		}
		if (list2.isEmpty()) cerr << "\nList2: empty";
		else
		{
			cout << "\nList2 (backwards): ";
			list2.reversePrint();
		}
		cout << "\n\n=> Check address of objects (should be different)...";
		cout << "\nList1: " << list1.addressObject();
		cout << "\nList2: " << list2.addressObject();
		if (!list1.isEmpty() && !list2.isEmpty())
		{
			cout << "\n\n=> Check address of first nodes (should be different)...";
			cout << "\nList1: " << list1.addressFirst();
			cout << "\nList2: " << list2.addressFirst();;
			cout << "\n\n=> Check number of nodes (should be the same)...";
			cout << "\nList1: " << list1.getNumOfElem();
			cout << "\nList2: " << list2.getNumOfElem();
		}

		cout << "\n\n----------------------------------------\n";
	}
}

void test_moveConstructor()
{
	cout << "/*********************************************************/\n";
	cout << "     TEST: MOVE CONSTRUCTOR" << endl;
	cout << "/*********************************************************/\n";
	
	int sizeV1 = static_cast<int>(v1.size());

	for (int i = 0; i < sizeV1; ++i)
	{
		DoublyList list1;
		int elements = static_cast<int>(v1[i].size());

		for (int j = 0; j < elements; ++j)
			list1.insertBack(v1[i].at(j));

		if (list1.isEmpty()) cerr << "\nList1: (empty)";
		else cout << "\nList1: " << list1;
		cout << "\n=> Use move constructor to create list2...";
		DoublyList list2 = move(list1);
		if (list2.isEmpty()) cerr << "\nList2: (empty)";
		else cout << "\nList2: " << list2;
		cout << "\n\n=> Check printing in reverse...";
		if (list1.isEmpty()) cerr << "\nList1: empty";
		else
		{
			cout << "\nList1 (backwards): ";
			list1.reversePrint();
		}
		if (list2.isEmpty()) cerr << "\nList2: empty";
		else
		{
			cout << "\nList2 (backwards): ";
			list2.reversePrint();
		}
		cout << "\n\n=> Check address of objects (should be different)...";
		cout << "\nList1: " << list1.addressObject();
		cout << "\nList2: " << list2.addressObject();
		cout << "\n\n=> Check address of first nodes...";
		cout << "\nList1: " << list1.addressFirst();
		cout << "\nList2: " << list2.addressFirst();
		cout << "\n\n=> Check address of last nodes...";
		cout << "\nList1: " << list1.addressLast();
		cout << "\nList2: " << list2.addressLast();
		cout << "\n\n=> Check number of nodes...";
		cout << "\nList1: " << list1.getNumOfElem();
		cout << "\nList2: " << list2.getNumOfElem();

		cout << "\n\n----------------------------------------\n";
	}
}