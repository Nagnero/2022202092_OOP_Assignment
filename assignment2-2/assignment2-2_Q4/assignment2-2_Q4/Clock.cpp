#include "Clock.h"
#include <iostream>

using namespace std;

Clock::Clock() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

Clock::~Clock() {
	cout << "clock is destroyed" << endl;
}


void Clock::increaseHour() { 
	if (this->hour < 23)
		this->hour++;
	else
		this->setHour(0);
}
void Clock::increaseMinute() { 
	if (this->minute < 59)
		this->minute++;
	else {
		this->setMinute(0);
		increaseHour();
	}
}
void Clock::increaseSecond() {
	if (this->second < 59)
		this->second++;
	else {
		this->setSecond(0);
		increaseMinute();
	}
}


void Clock::setTime(int second) {
	this->setSecond(second % 60);
 	this->setMinute((second / 60) % 60);
	this->setHour((second / 3600) % 24);
}


void Clock::printTime() {
	printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
}


void Clock::setHour(int hour) { this->hour = hour; }
void Clock::setMinute(int minute) { this->minute = minute; }
void Clock::setSecond(int second) { this->second = second; }