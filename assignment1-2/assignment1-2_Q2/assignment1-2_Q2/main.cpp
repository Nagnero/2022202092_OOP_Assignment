#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <cmath>

using namespace std;

// 전역변수로 transmitted data 선언 후 초기화
char T[16]{};
// divisor 전역변수로 저장
const int divisor[5] = { 1, 1, 0, 1, 1 };

// 사용자정의함수의 prototype
void Transmission_channel(const char* data);
void Sender();
int Receiver(const char* T);
int shift(int* binary, int* Q, int index);



int main() {

    Sender();
    
    return 0;
}

// Sender함수 정의부
void Sender() {
    char data[16]; // 사용자에게 입력을 받을 문자배열
    int binary[16], Q[5]{}, bucket[5]{}, i, j;// 이진수를 저장할 배열 및 임시 배열 선언 후 초기화

    cin >> data;// 사용자에게 입력받음

    // 입력받은 데이터를 이진 숫자로 변환
    for (i = 0; i < 12; i++)
        binary[i] = data[i] - '0';

    // bucket에 첫 다섯자리 저장
    for (i = 0; i < 5; i++)
        bucket[i] = binary[i];

    // dividsor로 12번 반복 나누기
    for (i = 0; i < 12;) {
        // bucket의 첫번째 요소가 0이면 다음루프 실행
        if (bucket[0] == 0) {
            for (j = 0; j < 5; j++) {
                bucket[j] = binary[i + 1 + j];
            }
            continue;
        }

        // XOR 연산
        for (j = 0; j < 5; j++)
            Q[j] = divisor[j] ^ bucket[j];

        int temp = i; // shift 함수에서 i가 바뀌었는지 확인하기 위한 변수
        i = shift(binary, bucket, i); // shift 함수 호출
        if (temp == i) // i가 증가하지 않았다면 1 증가
            i++;

        for (j = 0; j < 5; j++)
            bucket[j] = Q[j];
    }

    // FCS인 bucket을 binary배열 뒤에 추가하는 반복문
    for (; i < 16; i++)
        binary[i] = bucket[i - 11];

    // 숫자 배열인 binary를 문자형 배열에 저장하는 반복문
    for (i = 12; i < 16; i++)
        data[i] = binary[i] + '0';

    // 신호 오류처리 함수 출력
    Transmission_channel(data);

    // 콘솔 출력부
    cout << "Coded frame: ";
    for (i = 0; i < 16; i++)
        cout << data[i];

    cout << endl << "Received frame: ";
    for (i = 0; i < 16; i++)
        cout << T[i];

    cout << endl << "Reconstructed data: ";
    for (i = 0; i < 12; i++)
        cout << T[i];

    // 신호 받아서 에러 유무 출력부
    if (Receiver(T))
        cout << endl << "No detected error";
    else
        cout << endl << "Receiver has detected error" << endl;

}

// 신호 오류처리 함수 정의부
void Transmission_channel(const char* data) {

    srand(time(NULL)); // 실행시마다 다른 값 출력

    for (int i = 0; i < 16; i++) {
        if (rand() % 100 + 1 > 5) // 95% 확률로 전역 배열에 데이터 저장
            T[i] = data[i];
        else { // 5% 확률로 값 반대로 변환 후 저장
            int temp = data[i] - '0';
            temp = (temp + 1) % 2;
            T[i] = temp + '0';
        }
    }
}

int Receiver(const char* arr) {
    int binary[16], Q[5]{}, bucket[5]{}, i, j;

    // 입력받은 데이터를 이진 숫자로 변환
    for (i = 0; i < 16; i++)
        binary[i] = arr[i] - '0';

    // bucket에 첫 다섯자리 저장
    for (i = 0; i < 5; i++)
        bucket[i] = binary[i];

    // bucket의 첫번째 요소가 0이면 다음루프 실행, 첫 입력값이 0인경우
    if (bucket[0] == 0) {
        for (j = 0; j < 5; j++) {
            bucket[j] = binary[1 + j];
        }
    }
    // dividsor로 12번 반복 나누기
    for (i = 0; i < 12;) {

        // XOR 연산
        for (j = 0; j < 5; j++)
            Q[j] = divisor[j] ^ bucket[j];

        int temp = i; // shift 함수에서 i가 바뀌었는지 확인하기 위한 변수
        i = shift(binary, bucket, i); // shift 함수 호출
        if (temp == i) // i가 증가하지 않았다면 1 증가
            i++;

        for (j = 0; j < 5; j++)
            bucket[j] = Q[j];
    }

    for (i = 1; i < 5; i++) {
        if (bucket[i] == 0)
            continue;
        else
            return 0;
    }

    return 1;
}

int shift(int* binary, int* Q, int index) {
    int temp = 0, i;

    for (i = 1; i < 5; i++)
    {
        if (Q[i] == 1)
            temp += pow(2, 4 - i);
    }

    do {
        temp = temp << 1;
        if (binary[index + 5] == 1)
            temp++;

        index++;
        if (index == 12) {
            temp = temp >> 1;
            for (i = 0; i < 5; i++) {

                int a = pow(2, 4 - i);
                if (temp / a) {
                    Q[i] = 1;
                    temp %= a;
                }
                else
                    Q[i] = 0;
            }
            return 12;
        }
    } while (temp < 0b10000);


    // temp를 2진수로 다시 변환하여 저장
    for (i = 0; i < 5; i++) {
        int a = pow(2, 4 - i);
        if (temp / a) {
            Q[i] = 1;
            temp %= a;
        }
        else
            Q[i] = 0;
    }

    return index;
}