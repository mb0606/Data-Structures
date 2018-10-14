#pragma once
// Array-based queue implementation
template <typename E> class AQueue {
private:
	int maxSize;  // Maximum size of queue
	int front;    // Index of front element
	int rear;     // Index of rear element
	int size;
	E *listArray; // Array holding queue elements


public:
	explicit AQueue(int max = 50) {  // Constructor
									 // Make list array one position larger for empty slot maxSize = size+1;
		rear = 0;
		front = 1;
		size = 0;
		maxSize = 50;
		listArray = new E[maxSize];
	}

	//copy constructor
	AQueue(const AQueue<E>& copyObj) {
		rear = copyObj.rear;
		front = copyObj.front;
		size = copyObj.size;
		maxSize = copyObj.maxSize;
		listArray = new E[maxSize];
		for (int i = copyObj.front; i <= copyObj.rear; i++) {
			listArray[i] = copyObj.listArray[i];
		}

	}

	~AQueue() {
		delete[] listArray;
	} // Destructor

	void clear() {
		rear = 0;
		front = 1;
	} // Reinitialize
	void enqueue(const E& it) {     // Put "it" in queue
		rear = (rear + 1) % maxSize;       // Circular increment
		listArray[rear] = it;
		size++;
	}
	E dequeue() {           // Take element out
		E it = listArray[front];
		if (length() == 1) {
			clear();
		}
		//Assert(length() != 0, "Queue is empty");
		else if (front < rear) {
			front = (front + 1) % maxSize;
			size++;// Circular increment
		}
		return it;
	}
	const E& frontValue() const {  // Get front value
		return listArray[front];
	}
	bool isEmpty() {
		return front > rear;
	}
	virtual int length() const         // Return length
	{
		return ((rear + maxSize) - front + 1) % maxSize;
	}
	void printValues() {
		for (int i = 0; i < size; i++) {
			std::cout << listArray[front + i].name << std::endl;
		}
	}

};
