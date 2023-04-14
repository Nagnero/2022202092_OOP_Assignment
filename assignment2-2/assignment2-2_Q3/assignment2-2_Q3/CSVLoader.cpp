#include "CSVLoader.h"
#include <iostream>

using namespace std;

// ������ ����
CSVLoader::CSVLoader() {
	this->data = nullptr;
	this->cols = 0;
	this->rows = 0;
}

// ���ڸ� �ϳ� �޴� ������ ����
CSVLoader::CSVLoader(const char* path) {
	this->data = nullptr;
	this->cols = 0;
	this->rows = 0; // private�� ���� �ʱ�ȭ ��
	this->parse(path); // �Ľ� �Լ� ȣ��
}

// �Ҹ��� ���Ǻ�
CSVLoader::~CSVLoader() {
	for (int i = 0; i < this->getRows(); i++)
		delete[] this->data[i];

	delete[] this->data;
}

// float ���� ������ �ּ� ��ȯ
float** CSVLoader::getData() const {
	return this->data;
}

// private�� ����� rows ��ȯ �Լ�
int CSVLoader::getRows() const {
	return this->rows;
}

// private�� ����� cols ��ȯ �Լ�
int CSVLoader::getCols() const {
	return this->cols;
}

// ������ �Ľ� �Լ�
void CSVLoader::parse(const char* path) {
	ifstream fin; // input ���� ����
	string input; // �Է°�
	int max_col = 0, max_row = 0;

	fin.open(path); // ���� ����

	// � �������� �Ǵ�
	while (getline(fin, input)) { // ���پ� input�� ����
		int col = 0;
		for (int i = 0; i < input.length(); i++) {
			// �޸��� �ƴϸ� ���� ����
			if (input[i] != ',') 
				continue;
			else // �޸��� col ����
				col++;
		}
		max_row++; // ���� �Ǵ� ���� max_row ����
		if (col > max_col) // col�� ����� max_col���� ũ��
			max_col = col; // max_col�� col ����
	}
	 // ��� �� 
	this->cols = max_col + 1;
	this->rows = max_row;

	fin.close(); // ���� Ŭ����

	// ��� �� ��� �� �ش� ũ�⸸ŭ �����迭 �Ҵ�
	this->data = new float* [getRows()];
	for (int i = 0; i < getRows(); i++) {
		this->data[i] = new float[getCols()];
		for (int j = 0; j < getCols(); j++)
			this->data[i][j] = 0;
	}

	// �� �Է��� ���� �ٽ� ���� ����
	fin.open(path);

	string temp = ""; // �ӽ� ���ڿ� ���� ���� �� �ʱ�ȭ
	int row = 0;

	// ���پ� ���ư��鼭 �� ����
	while (getline(fin, input)) {
		int col = 0;
		// ���� �迭 ���鼭 �Ǵ�
		for (int i = 0; i < input.length() + 1; i++) {
			// ���ڿ��� �Է¹����� �ӽ� �迭�� �߰�
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

// ��ü ��� ��� �Լ� ���Ǻ�
void CSVLoader::print(void) {

	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}
