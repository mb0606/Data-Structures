#include "NodeType.h"

class LinkedType
{
public:
	LinkedType();
	void makeEmpty();
	bool isFull() const;
	int getLength();
	void insertItem(int item);
	void deleteItem(int item);
	void show();
	~LinkedType();

private:
	int length;
	NodeType *head;
	NodeType *tail;
};