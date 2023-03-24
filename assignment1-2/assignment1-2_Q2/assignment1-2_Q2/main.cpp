#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <cmath>

using namespace std;

char T[16]{}, T1[12]{};
const int divisor[5] = { 1, 1, 0, 1, 1 };


void Transmission_channel(const char* data);
void Sender();
int Receiver(const char* T);
int shift(int* binary, int* Q, int index);



int main() {

    Sender();

}

void Sender() {
    char data[16];
    int binary[16], Q[5]{}, bucket[5]{}, i, j;

    cin >> data;
    // 입력받은 데이터를 이진 숫자로 변환
    for (i = 0; i < 12; i++)
        binary[i] = data[i] - '0';
    for (; i < 16; i++)
        binary[i] = 0;

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

        int temp = i;
        i = shift(binary, Q, i);
        if (temp == i)
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

    Transmission_channel(data);

    cout << "Coded frame: ";
    for (i = 0; i < 16; i++)
        cout << data[i];

    cout << endl << "Received frame: ";
    for (i = 0; i < 16; i++)
        cout << T[i];

    cout << endl << "Reconstructed data: ";
    for (i = 0; i < 12; i++)
        cout << T[i];

    if (Receiver(T))
        cout << endl << "No detected error";
    else
        cout << endl << "Receiver has detected error" << endl;

}

void Transmission_channel(const char* data) {

    srand(time(NULL)); // 실행시마다 다른 값 출력

    for (int i = 0; i < 16; i++) {
        if (rand() % 100 + 1 > 5) // 0이 나오지 않으면 실행; 5% 확률
            T[i] = data[i];
        else {
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

        int temp = i;
        i = shift(binary, Q, i);
        if (temp == i)
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
        //for (int j = 0; j < 4; j++)
        //    Q[j] = Q[j + 1];
        //Q[4] = binary[index + 5];
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