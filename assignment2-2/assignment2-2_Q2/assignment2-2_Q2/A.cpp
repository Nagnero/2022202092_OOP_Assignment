#include "A.h"
using namespace std;

A::A(double input) { // ������
    this->value = input; // private�� �����Ͽ� value�� input ����
    cout << "Class A is created with " << this->value << endl; // ������. ��ü ���� ���� ���
}

A::~A() {
    cout << "Class A is destroyed with " << this->value << endl; // �Ҹ���. ��ü �Ҹ� ���� ���
}