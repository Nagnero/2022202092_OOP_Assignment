#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {
    double matrix[3][3];

public:
    // 기본 생성자
    Matrix() {
        // 0부터 99까지의 랜덤한 수로 행렬 초기화
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = rand() % 100;
            }
        }
    }
    // 주어진 숫자로 행렬 초기화
    Matrix(int num) {
        // 주어진 숫자로 행렬 초기화
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = num;
            }
        }
    }

    // 행렬 출력 함수
    void printMatrix();

    // 두 행렬을 더하는 연산자 오버로딩
    Matrix& operator+=(const Matrix& other);
    // 두 행렬을 빼는 연산자 오버로딩
    Matrix& operator-=(const Matrix& other);
    // 두 행렬을 곱하는 연산자 오버로딩
    Matrix& operator*(const Matrix& other);
};

// 행렬 출력 함수
void Matrix::printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // 각 원소를 5칸의 공간을 가지도록 출력
            printf("%5.f ", matrix[i][j]);
        }
        cout << endl;
    }
}

// 두 행렬을 더하는 연산자 오버로딩
Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

// 두 행렬을 빼는 연산자 오버로딩
Matrix& Matrix::operator-=(const Matrix& other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

// 두 행렬을 곱하는 연산자 오버로딩
Matrix& Matrix::operator*(const Matrix& other) {
    Matrix tempmat;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tempmat.matrix[i][j] = this->matrix[i][j] * other.matrix[i][j];
        }
    }
    return tempmat;
}

int main() {
    srand((unsigned int)time(NULL));
    Matrix matrix;
    int num, command;

    matrix.printMatrix();

    while (1) {
        cout << "Enter command (0.print 1.addition 2.subtraction 3.multiply else.exit): ";
        cin >> command;

        if (command == 0)
            matrix.printMatrix();
        else if (command == 1) {
            cout << "Enter number: ";
            cin >> num;
            Matrix tempmat(num);
            matrix += tempmat;
            matrix.printMatrix();
        }
        else if (command == 2) {
            cout << "Enter number: ";
            cin >> num;
            Matrix tempmat(num);
            matrix -= tempmat;
            matrix.printMatrix();
        }
        else if (command == 3) {
            cout << "Enter number: ";
            cin >> num;
            Matrix tempmat(num);
            tempmat = matrix * tempmat;
            tempmat.printMatrix();
        }
        else
            break;
    }

    return 0;
}
