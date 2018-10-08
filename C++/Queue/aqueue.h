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
	AQueue(int max = 50) {  // Constructor
							// Make list array one position larger for empty slot maxSize = size+1;
		rear = 0;
		front = 1;
		size = 0;
		maxSize = 50;
		listArray = new E[maxSize];
	}
	~AQueue() {
		delete[] listArray;
	} // Destructor

	void clear() {
		rear = 0;
		front = 1;
	} // Reinitialize
	void enqueue(const E& it) {     // Put "it" in queue
									//Assert(((rear+2) % maxSize) != front, "Queue is full");
		rear = (rear + 1) % maxSize;       // Circular increment
		listArray[rear] = it;
		size++;
	}
	E dequeue() {           // Take element out
							//Assert(length() != 0, "Queue is empty");
		E it = listArray[front];
		front = (front + 1) % maxSize; 
		size++;// Circular increment
		return it;
	}
	const E& frontValue() const {  // Get front value
								   //Assert(length() != 0, "Queue is empty");
		return listArray[front];
	}
	bool isEmpty() {
		return front >= rear;
	}
	virtual int length() const         // Return length
	{
		return ((rear + maxSize) - front + 1) % maxSize;
	}
	void printValues() {
		for (int i = 0; i < size; i++) {
			cout << listArray[front +i ].name << endl;
		}
	}

};
