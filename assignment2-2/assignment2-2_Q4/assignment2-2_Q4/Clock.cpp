#include "Clock.h"
#include <iostream>

using namespace std;

// 생성자
Clock::Clock() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

// 소멸자
Clock::~Clock() {
	cout << "clock is destroyed" << endl;
}

// 시간 증가 멤버 함수
void Clock::increaseHour() { 
	if (this->hour < 23) // 시간이 22이하면 1 증가
		this->hour++;
	else // 23이면 0으로 설정
		this->setHour(0);
}
// 분 증가 멤버 함수
void Clock::increaseMinute() { 
	if (this->minute < 59) // 분이 58이하면 1 증가
		this->minute++;
	else { // 분이 59면 0으로 설정 후 시간 증가
		this->setMinute(0);
		increaseHour();
	}
}
// 초 증가 멤버 함수
void Clock::increaseSecond() {
	if (this->second < 59) // 초가 58이하면 1 증가
		this->second++;
	else { // 초가 59면 0으로 설정 후 분 증가
		this->setSecond(0);
		increaseMinute();
	}
}

// 시간 설정 멤버함수
void Clock::setTime(int second) { // 초를 전달 받아서
	this->setSecond(second % 60); // 시, 분, 초로 처리 후 각각 설정
 	this->setMinute((second / 60) % 60);
	this->setHour((second / 3600) % 24);
}

// 시간 출력 멤버 함수
void Clock::printTime() {
	printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
}

// 시 분 초 설정 멤버 함수
void Clock::setHour(int hour) { this->hour = hour; }
void Clock::setMinute(int minute) { this->minute = minute; }
void Clock::setSecond(int second) { this->second = second; }