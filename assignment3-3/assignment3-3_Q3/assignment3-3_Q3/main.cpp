#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {
    double matrix[3][3];

public:
    // �⺻ ������
    Matrix() {
        // 0���� 99������ ������ ���� ��� �ʱ�ȭ
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = rand() % 100;
            }
        }
    }
    // �־��� ���ڷ� ��� �ʱ�ȭ
    Matrix(int num) {
        // �־��� ���ڷ� ��� �ʱ�ȭ
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = num;
            }
        }
    }

    // ��� ��� �Լ�
    void printMatrix();

    // �� ����� ���ϴ� ������ �����ε�
    Matrix& operator+=(const Matrix& other);
    // �� ����� ���� ������ �����ε�
    Matrix& operator-=(const Matrix& other);
    // �� ����� ���ϴ� ������ �����ε�
    Matrix& operator*(const Matrix& other);
};

// ��� ��� �Լ�
void Matrix::printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // �� ���Ҹ� 5ĭ�� ������ �������� ���
            printf("%5.f ", matrix[i][j]);
        }
        cout << endl;
    }
}

// �� ����� ���ϴ� ������ �����ε�
Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

// �� ����� ���� ������ �����ε�
Matrix& Matrix::operator-=(const Matrix& other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

// �� ����� ���ϴ� ������ �����ε�
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
