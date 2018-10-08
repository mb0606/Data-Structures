
#include "link.h"
#include "queue.h"

template <typename E> class LQueue : public Queue<E> {
private:
	Link<E>* front;       // Pointer to front queue node
	Link<E>* rear;        // Pointer to rear queue node
	int size;             // Number of elements in queue

public:
	LQueue(int sz = 3) // Constructor 
	{
		front = rear = new Link<E>(); 
		size = 0;
	}
	// LQueue(const LQueue<E> &copyObj) { // Put element on rear
	// 	if (copyObj.front == NULL) {
	// 		front = NULL;
	// 		rear = NULL;		
	// 	}
	// 	else {
	// 		front = copyObj.front;
	// 		Link<E>* temp = new Link<E>();
	// 		temp = copyObj.front;
	// 		while (temp != NULL) {
	// 			E value = temp->element;
	// 			enqueue(value);
	// 			temp = temp->next;
	// 		}
	// 		rear = copyObj.rear;
	// 	}
	// 	delete temp;

	// }

	~LQueue() { 
		if(length() > 0){
			clear();
			delete front; 
		}

	}      // Destructor

	void clear() { // Clear queue
		while (front->next != NULL) { // Delete each link node
			rear = front;
			delete rear;
		}
		rear = front;
		size = 0;
	}

	void enqueue(const E& it) { // Put element on rear
		rear->next = new Link<E>(it, NULL);
		rear = rear->next;
		size++;
	}

	E dequeue() {              // Remove element from front
		//Assert(size != 0, "Queue is empty");
		E it = front->next->element;  // Store dequeued value
		Link<E>* ltemp = front->next; // Hold dequeued link
		front->next = ltemp->next;       // Advance front
		if (rear == ltemp) rear = front; // Dequeue last element
		delete ltemp;                    // Delete link
		size--;
		return it;                       // Return element value
	}

	const E& frontValue() const { // Get front element
		//Assert(size != 0, "Queue is empty");
		return front->next->element;
	}

	virtual int length() const { 
		return size;
	}
	void printValues() const {
		Link<E>* ptemp = new Link<E>();
		ptemp = front;
		while (ptemp != NULL) {
		std::cout << ptemp->element.name << std::endl;
			ptemp = ptemp->next;
		}
		delete ptemp;
	}



};
