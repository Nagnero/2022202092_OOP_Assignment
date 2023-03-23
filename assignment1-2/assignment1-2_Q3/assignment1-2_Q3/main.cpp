#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// wildcard 룰을 적용하는 함수
bool wildcard(char* input, char* data) {

	// input문자열이 끝날때까지 반복
	for (int i = 0; input[i]; i++) {
		if (input[i] == '*') // *을 만나면 조건 만족한 것으로 보고 1 반환
			return 1;

		if (input[i] == data[i] || input[i] == '?') // 같은 인덱스에 같은 문자가 있거나 ?표를 만나면 다음 루프 실행
			continue;
		else { // 같은 인덱스에 다른 문자가 있으면 0반환
			return 0;
		}
	}

	// 모든 input내 charater에 대해 무사히 반복을 마치면 조건만족으로 1 반환
	return 1;
}

int main() {
	char data[100], input[100], result[20][100]{};
	int num, cnt = 0;
	ifstream fin; // 파일 변수

	// 파일 이름을 입력
	cout << "Input File name : ";
	cin >> input;

	// 입력받은 파일명과 저장된 파일명이 같으면 저장된 파일을 fin에 open
	if (strcmp(input, "filename_list.txt") == 0)
		fin.open("filename_list.txt");
	else { // 아니면 맞는 파일 없다고 출력 후 파일 닫고 종료
		cout << "no matching file" << endl;
		fin.close();
		return 0;
	}
	// 키워드의 갯수를 입력받음
	cout << "Input number of keyword : ";
	cin >> num;


	// num만큼 반복
	for (int i = 0; i < num; i++) {
		cout << "Input keyword" << i + 1 << " : "; // n번째 키워드 입력
		cin >> input; // input변수 재활용하여 비교할 문자열 입력받음

		// 파일 내용물의 끝까지 반복
		while (!fin.eof()) {
			fin.getline(data, 100); // 한줄씩 data에 저장 후
			if (wildcard(input, data)) { // wildcard함수에 비교대상인 input과 함께 data 전달
				strcpy(result[cnt], data); // 조건을 만족하면 result 변수에 저장
				cnt++;
			}
		}
		fin.close(); // 다음 루프를 돌기전에 다시 파일 오픈
		fin.open("filename_list.txt");
	}
	// 코드 전부 실행 후 파일 닫기
	fin.close();

	// 저장해 놓은 값 모두 출력
	cout << endl;
	for (int i = 0; i < cnt; i++)
		cout << result[i] << endl;
	
	return 0;
}