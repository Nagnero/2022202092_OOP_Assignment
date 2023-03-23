#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

bool wildcard(char* input, char* data) {

	for (int i = 0; input[i]; i++) {
		if (input[i] == '*')
			return 1;

		if (input[i] == data[i] || input[i] == '?')
			continue;
		else {
			return 0;
		}
	}

	return 1;
}

int main() {
	char data[100], input[100], result[20][100]{};
	int num, cnt = 0;
	ifstream fin;

	cout << "Input File name : ";
	cin >> input >> num;

	if (strcmp(input, "filename_list.txt") == 0)
		fin.open("filename_list.txt");
	else {
		cout << "no matching file";
		fin.close();
	}

	// num만큼 반복
	for (int i = 0; i < num; i++) {
		cin >> input; // input변수 재활용

		while (!fin.eof()) {
			fin.getline(data, 100);
			if (wildcard(input, data)) {
				strcpy(result[cnt], data);
				cnt++;
			}
		}
		fin.close();
		fin.open("filename_list.txt");
	}

	cout << endl;
	for (int i = 0; i < cnt; i++)
		cout << result[i] << endl;
	
}