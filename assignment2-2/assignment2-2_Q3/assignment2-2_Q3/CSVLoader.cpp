#include "CSVLoader.h"
#include <iostream>

using namespace std;

CSVLoader::CSVLoader() {
	this->data = nullptr;
	this->cols = 0;
	this->rows = 0;
}

CSVLoader::CSVLoader(const char* path) {
	this->data = nullptr;
	this->cols = 0;
	this->rows = 0;
	this->parse(path);
}

CSVLoader::~CSVLoader() {
	for (int i = 0; i < this->getCols(); i++)
		delete[] this->data[i];

	delete[] this->data;
}


float** CSVLoader::getData() const {
	return this->data;
}

int CSVLoader::getRows() const {
	return this->rows;
}

int CSVLoader::getCols() const {
	return this->cols;
}


void CSVLoader::parse(const char* path) {
	ifstream fin;
	string input;
	int max_col = 0, max_row = 0;

	fin.open(path);

	// 몇열 몇행인지 판단
	while (getline(fin, input)) {
		int row = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ',') {
				// temp.push_back(input[i]);
				continue;
			}
			else {
				// this->data[col][row] = stof(temp);
				row++;
				// temp = "";
			}
		}
		max_col++;
		if (row > max_row)
			max_row = row;
	}

	this->cols = max_col;
	this->rows = max_row + 1;

	fin.close();

	// 행과 열 계산 후 해당 크기만큼 동적배열 할당
	this->data = new float* [getCols()];
	for (int i = 0; i < getCols(); i++) {
		this->data[i] = new float[getRows()];
		for (int j = 0; j < getRows(); j++)
			this->data[i][j] = 0;
	}

	// 값 입력을 위해 다시 파일 오픈
	fin.open(path);

	string temp = "";
	int col = 0;

	while (getline(fin, input)) {
		int row = 0;
		for (int i = 0; i < input.length() + 1; i++) {
			if (input[i] != ',' && input[i] != '\0') {
				temp.push_back(input[i]);
			}
			else {
				if (temp == "") {
					row++;
					continue;
				}

				this->data[col][row] = stof(temp);
				row++;
				temp = "";
			}
		}
		col++;
	}

	fin.close();

}

void CSVLoader::print(void) {

	for (int i = 0; i < getCols(); i++) {
		for (int j = 0; j < getRows(); j++) {
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}
