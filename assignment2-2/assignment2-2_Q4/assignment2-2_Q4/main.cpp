#include "Clock.h"
#include <iostream>

using namespace std;

int main() {
	Clock* clock = new Clock; // clock 객체 동적 할당
	int sec, command = 1;

	cout << "Enter second: ";
	cin >> sec; // 초 입력

	clock->setTime(sec); // clock 객체에서 초를 입력 받아 시분초 계산해서 저장
	clock->printTime(); // 시간 출력

	while (1) { // 무한반복
		cout << "Enter Command (1.Increase hour, 2.Increase minute, 3.Increase second, 0. exit): ";
		cin >> command; // command 저장
		if (command == 1) { // 시간 1 증가 후 출력
			clock->increaseHour();
			clock->printTime();
		}
		else if (command == 2) { // 분 1 증가 후 출력
			clock->increaseMinute();
			clock->printTime();
		}
		else if (command == 3) { // 초 1 증가 후 출력
			clock->increaseSecond();
			clock->printTime();
		}
		else if (command == 0) // 반복문 탈출
			break;
		else
			cout << "Enter valid number" << endl;
	}

	delete clock; // 객체 메모리 할당 해제

	return 0;
}