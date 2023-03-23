#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// wildcard ���� �����ϴ� �Լ�
bool wildcard(char* input, char* data) {

	// input���ڿ��� ���������� �ݺ�
	for (int i = 0; input[i]; i++) {
		if (input[i] == '*') // *�� ������ ���� ������ ������ ���� 1 ��ȯ
			return 1;

		if (input[i] == data[i] || input[i] == '?') // ���� �ε����� ���� ���ڰ� �ְų� ?ǥ�� ������ ���� ���� ����
			continue;
		else { // ���� �ε����� �ٸ� ���ڰ� ������ 0��ȯ
			return 0;
		}
	}

	// ��� input�� charater�� ���� ������ �ݺ��� ��ġ�� ���Ǹ������� 1 ��ȯ
	return 1;
}

int main() {
	char data[100], input[100], result[20][100]{};
	int num, cnt = 0;
	ifstream fin; // ���� ����

	// ���� �̸��� �Է�
	cout << "Input File name : ";
	cin >> input;

	// �Է¹��� ���ϸ�� ����� ���ϸ��� ������ ����� ������ fin�� open
	if (strcmp(input, "filename_list.txt") == 0)
		fin.open("filename_list.txt");
	else { // �ƴϸ� �´� ���� ���ٰ� ��� �� ���� �ݰ� ����
		cout << "no matching file" << endl;
		fin.close();
		return 0;
	}
	// Ű������ ������ �Է¹���
	cout << "Input number of keyword : ";
	cin >> num;


	// num��ŭ �ݺ�
	for (int i = 0; i < num; i++) {
		cout << "Input keyword" << i + 1 << " : "; // n��° Ű���� �Է�
		cin >> input; // input���� ��Ȱ���Ͽ� ���� ���ڿ� �Է¹���

		// ���� ���빰�� ������ �ݺ�
		while (!fin.eof()) {
			fin.getline(data, 100); // ���پ� data�� ���� ��
			if (wildcard(input, data)) { // wildcard�Լ��� �񱳴���� input�� �Բ� data ����
				strcpy(result[cnt], data); // ������ �����ϸ� result ������ ����
				cnt++;
			}
		}
		fin.close(); // ���� ������ �������� �ٽ� ���� ����
		fin.open("filename_list.txt");
	}
	// �ڵ� ���� ���� �� ���� �ݱ�
	fin.close();

	// ������ ���� �� ��� ���
	cout << endl;
	for (int i = 0; i < cnt; i++)
		cout << result[i] << endl;
	
	return 0;
}