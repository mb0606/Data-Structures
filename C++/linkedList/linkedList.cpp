#include "stdafx.h"
#include "LinkedType.h"
#include <iostream>

using namespace std;

int main() {
	LinkedType linkedlist;

	linkedlist.insertItem(5);
	linkedlist.insertItem(6);
	linkedlist.insertItem(22);
	linkedlist.insertItem(90);
	linkedlist.insertItem(1);

	linkedlist.deleteItem(22);

	linkedlist.insertAfter(5, 33);
	linkedlist.insertAfter(1, 88);

	linkedlist.show();

	system("pause");
}