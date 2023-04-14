#include "A.h"
using namespace std;

A::A(double input) { // 생성자
    this->value = input; // private에 접근하여 value에 input 저장
    cout << "Class A is created with " << this->value << endl; // 생성자. 객체 생성 문구 출력
}

A::~A() {
    cout << "Class A is destroyed with " << this->value << endl; // 소멸자. 객체 소멸 문구 출력
}