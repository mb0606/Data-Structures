#include "stdafx.h"
#include "LinkedType.h"
#include <iostream>

using namespace std;

//O(1)
LinkedType::LinkedType()
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

//O(1)
void LinkedType::insertItem(int item) 
{
	NodeType *temp = new NodeType;
	temp->data = item;
	temp->next = nullptr;
	if (!head) {
		head = temp;
	}
	else if (!tail){
		tail = temp;
		head->next = tail;
	}
	else {
		tail->next = temp;
		tail = temp;
	}


	length++;
}
//O(1)
bool LinkedType::isFull() const 
{
	NodeType *location;

	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch(bad_alloc exception)
	{
		return true;
	}
	
}

//O(1)
int LinkedType::getLength() {
	return length;
}

void LinkedType::show() {
	NodeType *temp = head;
	while (temp != nullptr) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

//O(n)
void LinkedType::makeEmpty()
{
	NodeType *temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
	length = 0;
}

//O(n)
void LinkedType::deleteItem(int item) {
	if (head != nullptr) {
		// 
		NodeType *previous_node = head;
		NodeType *current_node = head->next;
		if (item == head->data) {
			head = head->next;
			length--;
		}
		else {
			while (current_node != nullptr) {
				if (item == current_node->data) {
					previous_node->next = current_node->next;
					current_node = current_node->next;
					length--;
				}
				else {
					previous_node = previous_node->next;
					current_node = current_node->next;
				}
			}
		}


	}

}
void LinkedType::insertAfter(int item, int node_value) {
	NodeType *new_node = new NodeType;
	new_node->data = node_value;
	NodeType *current_node = head;
	while (current_node != nullptr) {
		if (current_node->data == item) {
			new_node->next = current_node->next;
			current_node->next = new_node;
			current_node = current_node->next;
			length++;
		}
		else {
			current_node = current_node->next;
		}
	}
}

//O(n)
LinkedType::~LinkedType() {
	makeEmpty();
}
