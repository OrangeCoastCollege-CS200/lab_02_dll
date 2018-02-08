#include "Testing_assignmentOperator.h"

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> v11 = {
	{},
	{ 1 },
	{ 1, 2 },
	{ 4, 5, 6, 7 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
};

vector< vector<int>> v22 = {
	{ 1 },
	{ 3 },
	{ 1, 3 },
	{ 4, 5, 6, 7 },
	{ 8, 7, 6, 5, 4 },
};

void test_assignmentOperator()
{
	cout << "/*********************************************************/\n";
	cout << "     TEST: OVERLOADED ASSIGNMENT OPERATOR" << endl;
	cout << "/*********************************************************/\n";

	int sizeV11 = static_cast<int>(v11.size());
	int sizeV22 = static_cast<int>(v22.size());

	for (int i = 0; i < sizeV11; ++i)
	{
		DoublyList list11;
		int elements11 = static_cast<int>(v11[i].size());
		for (int j = 0; j < elements11; ++j)
			list11.insertBack(v11[i].at(j));
		DoublyList list22;
		int elements22 = static_cast<int>(v22[i].size());
		for (int j = 0; j < elements22; ++j)
			list22.insertBack(v22[i].at(j));

		if (list11.isEmpty()) cerr << "\nList11: (empty)";
		else cout << "\nList11: " << list11;
		if (list22.isEmpty()) cerr << "\nList22: (empty)";
		else cout << "\nList22: " << list22;

		cout << "\n=> Use overloaded assignment operator to copy list11 into list22...";
		list22 = list11;
		if (list22.isEmpty()) cerr << "\nList22: (empty)";
		else cout << "\nList22: " << list22;
		cout << "\n\n=> Check printing in reverse...";
		if (list11.isEmpty()) cerr << "\nList11: empty";
		else
		{
			cout << "\nList11 (backwards): ";
			list11.reversePrint();
		}
		if (list22.isEmpty()) cerr << "\nList22: empty";
		else
		{
			cout << "\nList22 (backwards): ";
			list22.reversePrint();
		}
		cout << "\n\n=> Check address of objects (should be different)...";
		cout << "\nList11: " << list11.addressObject();
		cout << "\nList22: " << list22.addressObject();
		if (!list11.isEmpty() && !list22.isEmpty())
		{
			cout << "\n\n=> Check address of first nodes (should be different)...";
			cout << "\nList11: " << list11.addressFirst();
			cout << "\nList22: " << list22.addressFirst();;
			cout << "\n\n=> Check number of nodes (should be the same)...";
			cout << "\nList11: " << list11.getNumOfElem();
			cout << "\nList22: " << list22.getNumOfElem();
		}

		cout << "\n\n----------------------------------------\n";
	}
}

void test_moveAssignmentOperator()
{
	cout << "/*********************************************************/\n";
	cout << "     TEST: MOVE ASSIGNMENT OPERATOR" << endl;
	cout << "/*********************************************************/\n";

	int sizeV11 = static_cast<int>(v11.size());
	int sizeV22 = static_cast<int>(v22.size());

	for (int i = 0; i < sizeV11; ++i)
	{
		DoublyList list11;
		int elements11 = static_cast<int>(v11[i].size());
		for (int j = 0; j < elements11; ++j)
			list11.insertBack(v11[i].at(j));
		DoublyList list22;
		int elements22 = static_cast<int>(v22[i].size());
		for (int j = 0; j < elements22; ++j)
			list22.insertBack(v22[i].at(j));

		if (list11.isEmpty()) cerr << "\nList11: (empty)";
		else cout << "\nList11: " << list11;
		if (list22.isEmpty()) cerr << "\nList22: (empty)";
		else cout << "\nList22: " << list22;

		cout << "\n=> Use move assignment operator to copy list11 into list22...";
		list22 = move(list11);
		if (list22.isEmpty()) cerr << "\nList22: (empty)";
		else cout << "\nList22: " << list22;
		cout << "\n\n=> Check printing in reverse...";
		if (list11.isEmpty()) cerr << "\nList11: empty";
		else
		{
			cout << "\nList11 (backwards): ";
			list11.reversePrint();
		}
		if (list22.isEmpty()) cerr << "\nList22: empty";
		else
		{
			cout << "\nList22 (backwards): ";
			list22.reversePrint();
		}
		cout << "\n\n=> Check address of objects (should be different)...";
		cout << "\nList11: " << list11.addressObject();
		cout << "\nList22: " << list22.addressObject();
		if (!list11.isEmpty() && !list22.isEmpty())
		{
			cout << "\n\n=> Check address of first nodes (should be different)...";
			cout << "\nList11: " << list11.addressFirst();
			cout << "\nList22: " << list22.addressFirst();;
			cout << "\n\n=> Check number of nodes (should be the same)...";
			cout << "\nList11: " << list11.getNumOfElem();
			cout << "\nList22: " << list22.getNumOfElem();
		}

		cout << "\n\n----------------------------------------\n";
	}
}