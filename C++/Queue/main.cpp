// arrayQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "aqueue.h"
#include "string"


using namespace std;

struct passanger {
	string name;
};

int showMenu(void);
void addPassenger(AQueue<passanger>* queue);
void deletePassenger(AQueue<passanger>* queue);
void showPassengers(AQueue<passanger>* queue);


const int LINES = 2;


int main()
{

	AQueue<passanger> qPassengers[LINES];

	int x;
	do {
		x = showMenu();
		switch (x)
		{
		case 1: addPassenger(qPassengers);
			break;
		case 2: deletePassenger(qPassengers);
			break;
		case 3: showPassengers(qPassengers);
			break;
		}
		if (x < 1 || x >4) {
			cout << "Invalid entry" << endl;
		}
	} while (x != 4);

	system("pause");
	return 0;
}

int showMenu(void)
{
	int select;

	cout << "Menu\n";
	cout << "========\n";
	cout << "1. Add Passenger\n";
	cout << "2. Delete Passenger\n";
	cout << "3. Show Passengers\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> select;
	cin.ignore();
	cin.clear();
	return select;
}

void addPassenger(AQueue<passanger>* queue) {
	if (queue[0].length() < 3 || queue[1].length() < 3) {
		string name;
		cout << "Enter name: ";
		getline(cin, name);
		if (queue[0].length() < 3) {
			passanger bookingPassanger;
			bookingPassanger.name = name;
			queue[0].enqueue(bookingPassanger);

			//cout << "Booking " << name << " on flight"<< endl;
		}
		else {
			cout << "Sorry. Plane fully booked. Adding " << name << " to waiting list" << endl;
			passanger waitPassanger;
			waitPassanger.name = name;
			queue[1].enqueue(waitPassanger);
		}
	}
	else {
		cout << "Sorry. Plane and waiting list fully booked. Try later" << endl;
	}

}
void deletePassenger(AQueue<passanger>* queue) {
	if (queue[0].length() != 0) {
		passanger personBooked = queue[0].dequeue();
		//cout << "Removing " << personBooked.name << " from booked passengers" << endl;
		if (queue[1].length() != 0) {
			passanger personWaiting = queue[1].dequeue();
			queue[0].enqueue(personWaiting);
			cout << "Adding " << personWaiting.name << " from waiting list" << endl;
		}
	}
	else {
		cout << "No passengers to delete" << endl;
	}

}
void showPassengers(AQueue<passanger>* queue) {
	if (queue[0].length() > 0) {
		AQueue<passanger> * tempQueue = new AQueue<passanger>();
		cout << "Booked Passengers" << endl;
		cout << "=================\n";
		int length = queue[0].length();
		for (int i = 0; i < length; i++) {
			passanger tempPassanger = queue[0].dequeue();
			cout << tempPassanger.name << endl;
			queue[0].enqueue(tempPassanger);

		}
		//queue[0].printValues();
		if (queue[1].length() > 0) {
			AQueue<passanger> * tempQueue = new AQueue<passanger>();
			cout << "Waiting list" << endl;
			cout << "=================";
			int length = queue[1].length();
			for (int i = 0; i < length; i++) {
				passanger tempPassanger = queue[1].dequeue();
				cout << tempPassanger.name << endl;
				queue[1].enqueue(tempPassanger);

			}
		}
		else {
			cout << "No passengers on waiting list" << endl;
		}
	}
	else {
		cout << "No passengers" << endl;
	}


}
