#include "CSVLoader.h"
#include <iostream>

using namespace std;

// 생성자 정의
CSVLoader::CSVLoader() {
	this->data = nullptr;
	this->cols = 0;
	this->rows = 0;
}

// 인자를 하나 받는 생성자 정의
CSVLoader::CSVLoader(const char* path) {
	this->data = nullptr;
	this->cols = 0;
	this->rows = 0; // private에 변수 초기화 후
	this->parse(path); // 파싱 함수 호출
}

// 소멸자 정의부
CSVLoader::~CSVLoader() {
	for (int i = 0; i < this->getRows(); i++)
		delete[] this->data[i];

	delete[] this->data;
}

// float 이중 포인터 주소 반환
float** CSVLoader::getData() const {
	return this->data;
}

// private에 저장된 rows 반환 함수
int CSVLoader::getRows() const {
	return this->rows;
}

// private에 저장된 cols 반환 함수
int CSVLoader::getCols() const {
	return this->cols;
}

// 데이터 파싱 함수
void CSVLoader::parse(const char* path) {
	ifstream fin; // input 파일 변수
	string input; // 입력값
	int max_col = 0, max_row = 0;

	fin.open(path); // 파일 오픈

	// 몇열 몇행인지 판단
	while (getline(fin, input)) { // 한줄씩 input에 대입
		int col = 0;
		for (int i = 0; i < input.length(); i++) {
			// 콤마가 아니면 다음 루프
			if (input[i] != ',') 
				continue;
			else // 콤마면 col 증가
				col++;
		}
		max_row++; // 한줄 판단 이후 max_row 증가
		if (col > max_col) // col이 저장된 max_col보다 크면
			max_col = col; // max_col에 col 저장
	}
	 // 행과 열 
	this->cols = max_col + 1;
	this->rows = max_row;

	fin.close(); // 파일 클로즈

	// 행과 열 계산 후 해당 크기만큼 동적배열 할당
	this->data = new float* [getRows()];
	for (int i = 0; i < getRows(); i++) {
		this->data[i] = new float[getCols()];
		for (int j = 0; j < getCols(); j++)
			this->data[i][j] = 0;
	}

	// 값 입력을 위해 다시 파일 오픈
	fin.open(path);

	string temp = ""; // 임시 문자열 변수 선언 후 초기화
	int row = 0;

	// 한줄씩 돌아가면서 값 저장
	while (getline(fin, input)) {
		int col = 0;
		// 한줄 배열 돌면서 판단
		for (int i = 0; i < input.length() + 1; i++) {
			// 문자열을 입력받으면 임시 배열에 추가
			if (input[i] != ',' && input[i] != '\0') {
				temp.push_back(input[i]);
			}
			else {
				if (temp == "") {
					col++;
					continue;
				}

				this->data[row][col] = stof(temp);
				col++;
				temp = "";
			}
		}
		row++;
	}

	fin.close();

}

// 전체 출력 멤버 함수 정의부
void CSVLoader::print(void) {

	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}
