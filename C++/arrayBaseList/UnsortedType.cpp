#include "stdafx.h"
#include "UnsortedType.h"
#include <iostream>

using namespace std;

//O(1)
UnsortedType::UnsortedType()
{
	length = 0;
}
//O(1)
void UnsortedType::insertItem(int item)
{
	if (isFull()) { return; }
	info[length] = item;
	length++;
}
//O(n)
void UnsortedType::deleteItem(int item) {
	for (int i = 0; i < length; i++) {
		// find item
		if (info[i] == item)
		{
			// shift all the items left and subtrace 1 from the length
			for (int j = i; j < length - 1; j++) {
				info[j] = info[j + 1];
			}
			length--;
		}
	}
}
//O(1)
bool UnsortedType::isFull() const
{
	return (length == 100);
}
//O(1)
void UnsortedType::makeEmpty()
{
	length = 0;
}
//O(1)
int UnsortedType::getLength()
{
	return length;
}
//O(n)
void UnsortedType::show() {
	for (int i = 0; i < length; i++)
	{
		cout << info[i] << " ";
	}
	cout << endl;
}
