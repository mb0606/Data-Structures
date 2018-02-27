#include "stdafx.h"
#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
	UnsortedType Collection;

	Collection.insertItem(3);
	Collection.insertItem(4);
	Collection.insertItem(6);
	Collection.insertItem(10);
	Collection.insertItem(22);
	Collection.insertItem(99);

	Collection.show();

	Collection.deleteItem(22);

	cout << "Length is currently :" << Collection.getLength() << endl;

	Collection.show();

	system("pause");
}