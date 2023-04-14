#include "Clock.h"
#include <iostream>

using namespace std;

// ������
Clock::Clock() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

// �Ҹ���
Clock::~Clock() {
	cout << "clock is destroyed" << endl;
}

// �ð� ���� ��� �Լ�
void Clock::increaseHour() { 
	if (this->hour < 23) // �ð��� 22���ϸ� 1 ����
		this->hour++;
	else // 23�̸� 0���� ����
		this->setHour(0);
}
// �� ���� ��� �Լ�
void Clock::increaseMinute() { 
	if (this->minute < 59) // ���� 58���ϸ� 1 ����
		this->minute++;
	else { // ���� 59�� 0���� ���� �� �ð� ����
		this->setMinute(0);
		increaseHour();
	}
}
// �� ���� ��� �Լ�
void Clock::increaseSecond() {
	if (this->second < 59) // �ʰ� 58���ϸ� 1 ����
		this->second++;
	else { // �ʰ� 59�� 0���� ���� �� �� ����
		this->setSecond(0);
		increaseMinute();
	}
}

// �ð� ���� ����Լ�
void Clock::setTime(int second) { // �ʸ� ���� �޾Ƽ�
	this->setSecond(second % 60); // ��, ��, �ʷ� ó�� �� ���� ����
 	this->setMinute((second / 60) % 60);
	this->setHour((second / 3600) % 24);
}

// �ð� ��� ��� �Լ�
void Clock::printTime() {
	printf("%02d:%02d:%02d\n", this->hour, this->minute, this->second);
}

// �� �� �� ���� ��� �Լ�
void Clock::setHour(int hour) { this->hour = hour; }
void Clock::setMinute(int minute) { this->minute = minute; }
void Clock::setSecond(int second) { this->second = second; }