#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

// 입력값을 10진수로 변환하는 함수의 prototype
int to_decimal(int& temp, int len, int c); 
// 변환한 10진수를 다시 다른 진법으로 변환하는 함수의 prototype
int to_target(int temp, int c);
int to_hexa(int temp);

char input[100]{};

int main() {
    int c, t, len, temp = 0; // 현재 진수인 c와 목표 진수인 t
    cout << "Enter input : ";
    cin >> input >> c >> t;

    len = strlen(input); // 입력값의 자릿수

    // 먼저 입력값을 10진수로 변환해서 정수값 도출
    to_decimal(temp, len, c); 

    // 변환된 10진수를 목표 진법으로 변환 후 출력
    if (t != 16)
        to_target(temp, t); // 2, 8, 10 진수로 출력
    else
        to_hexa(temp); // 16진수로 출력

    return 0;
}

// 십진수 변환
int to_decimal(int& temp, int len, int c) {
    // 16진수가 아닌 수라면 공식에 따라 10진수로 변환
    if (c != 16) {
        for (int i = 0; i < len; i++) {
            temp += (input[i] - '0') * pow(c, len - 1 - i);
        }
    }
    else { // 16진수라면 알파벳을 받는 경우 숫자로 바꿔서 변환
        for (int i = 0; i < len; i++) {
            if (input[i] >= 'A' && input[i] <= 'F') {
                int num = input[i] - 'A' + 10;
                temp += num * pow(c, len - 1 - i);
            }
            else {
                temp += (input[i] - '0') * pow(c, len - 1 - i);
            }
        }
    }

    return 0;
}


// 십진수를 원하는 수로 변경 후 출력
int to_target(int temp, int t) {
    // 재귀함수 탈출 조건
    if (temp == 0)
        return 0;

    // 각 진법의 맞는 숫자(t)로 나누어 재귀함수 호출
    to_target(temp / t, t);
    cout << temp % t; // 첫째자리부터 출력

    return 0;
}

int to_hexa(int temp) {
    // 재귀함수 탈출조건
    if (temp == 0)
        return 0;

    // 16으로 나누어 재귀함수 호출
    to_hexa(temp / 16);

    // 첫째자리부터 출력
    temp %= 16;
    if (temp < 10) {
        cout << temp;
    }
    else { // 10이상의 경우 알파벳 대문자로 바꾸어 출력
        cout << static_cast<char>(temp - 10 + 'A');
    }

    return 0;
}