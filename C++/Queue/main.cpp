// airLineTickets.cpp : Defines the entry point for the console application.
#include <iostream>
#include "lqueue.h"
#include "string"


using namespace std;

struct passanger {
	string name;
};

int showMenu(void);
void addPassenger(LQueue<passanger>* queue);
void deletePassenger(LQueue<passanger>* queue);
void showPassengers(LQueue<passanger>* queue);


const int LINES = 2;


int main()
{

	LQueue<passanger> qPassengers[LINES];

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
        if(x < 1 || x >4) {
        cout << "Invalid entry" << endl;
        }
	} while (x != 4);


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
	cin.clear();
	return select;
}

void addPassenger(LQueue<passanger>* queue) {
    if(queue[0].length() < 3 || queue[1].length() < 3){
        string name;
        cout << "Enter name: ";
        cin >> name;
        cin.clear();
        if (queue[0].length() < 3) {
            passanger bookingPassanger;
            bookingPassanger.name = name;
            queue[0].enqueue(bookingPassanger);

            //cout << "Booking " << name << " on flight"<< endl;
        }
        else {
            cout << "Sorry. Plane fully booked. Adding "<< name <<" to waiting list" << endl;
            passanger waitPassanger;
            waitPassanger.name = name;
            queue[1].enqueue(waitPassanger);
        }
    }
    else {
        cout << "Sorry. Plane and waiting list fully booked. Try later" << endl;
    }

}
void deletePassenger(LQueue<passanger>* queue) {
	if (queue[0].length() != 0) {
		passanger personBooked = queue[0].dequeue();
		//cout << "Removing " << personBooked.name << " from booked passengers" << endl;
		if (queue[1].length() != 0) {
			passanger personWaiting = queue[1].dequeue();
			queue[0].enqueue(personWaiting);
			cout << "Adding "<< personWaiting.name <<" from waiting list" << endl;
		}
	}
	else {
		cout << "No passengers to delete" << endl;
	}

}
void showPassengers(LQueue<passanger>* queue) {
	if(queue[0].length() > 0) {
		cout << "Booked Passengers" << endl;
		cout << "=================";
		queue[0].printValues();
        if (queue[1].length() > 0) {
            cout << "Waiting list" << endl;
            cout << "=================";
 		    queue[1].printValues();
        }
        else {
            cout << "No passengers on waiting list" << endl;
        }
	}
	else {
		cout << "No passengers" << endl;
	}


}