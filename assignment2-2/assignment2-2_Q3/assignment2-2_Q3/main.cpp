#include "CSVLoader.h" // ������� ȣ��
#include <iostream>

using namespace std;


int main() {
	
	const char* path = "CSVLoader_Data.txt"; // ���ϸ� ���庯��
	string input; // �Է°� ���� ����
	int command = 0, col = 0, row = 0;
	
	CSVLoader csv(path); // ��ü ���� �� CSV �ڸ��� ����
	float** dataSet = csv.getData(); // ���� ������ ������ �߶���� ������ ����
	cout << "Total column and row is " << csv.getRows() << " and " << csv.getCols() << endl << endl;
	// �����Ϳ� ����� ���� �� ���

	while (1) { // command�� ���� �ݺ�
		cout << "Enter Command (1.print all, 2.print with index(col,row), 3.exit): ";
		cin >> command;
		// command�� 1�̸� ��� �޼����Լ� ȣ��
		if (command == 1) {
			csv.print();
			cout << endl;
		}
		else if (command == 2) { // command�� 2�̸�
			cin >> col >> row; // �ε����� �Է¹޾�
			cout << dataSet[row - 1][col - 1] << endl; // �ε����� �����Ͽ� ���
		}
		else if (command == 3) // command�� 3�̸� Ż��
			break;
		else
			cout << "Enter vaild command. " << endl;
	}

	return 0;
}