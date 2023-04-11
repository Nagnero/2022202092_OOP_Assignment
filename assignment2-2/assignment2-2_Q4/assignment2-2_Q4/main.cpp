#include "Clock.h"
#include <iostream>

using namespace std;

int main() {
	Clock* clock = new Clock;
	int sec, command = 1;

	cout << "Enter second: ";
	cin >> sec;

	clock->setTime(sec);
	clock->printTime();

	while (1) {
		cout << "Enter Command (1.Increase hour, 2.Increase minute, 3.Increase second, 0. exit): ";
		cin >> command;
		if (command == 1) {
			clock->increaseHour();
			clock->printTime();
		}
		else if (command == 2) {
			clock->increaseMinute();
			clock->printTime();
		}
		else if (command == 3) {
			clock->increaseSecond();
			clock->printTime();
		}
		else if (command == 0)
			break;
		else
			cout << "Enter valid number" << endl;
	}

	delete clock;

	return 0;
}