#include "Clock.h"
#include <iostream>

using namespace std;

int main() {
	Clock* clock = new Clock; // clock ��ü ���� �Ҵ�
	int sec, command = 1;

	cout << "Enter second: ";
	cin >> sec; // �� �Է�

	clock->setTime(sec); // clock ��ü���� �ʸ� �Է� �޾� �ú��� ����ؼ� ����
	clock->printTime(); // �ð� ���

	while (1) { // ���ѹݺ�
		cout << "Enter Command (1.Increase hour, 2.Increase minute, 3.Increase second, 0. exit): ";
		cin >> command; // command ����
		if (command == 1) { // �ð� 1 ���� �� ���
			clock->increaseHour();
			clock->printTime();
		}
		else if (command == 2) { // �� 1 ���� �� ���
			clock->increaseMinute();
			clock->printTime();
		}
		else if (command == 3) { // �� 1 ���� �� ���
			clock->increaseSecond();
			clock->printTime();
		}
		else if (command == 0) // �ݺ��� Ż��
			break;
		else
			cout << "Enter valid number" << endl;
	}

	delete clock; // ��ü �޸� �Ҵ� ����

	return 0;
}