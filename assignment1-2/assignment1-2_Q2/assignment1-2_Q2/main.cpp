#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <cmath>

using namespace std;

const int divisor[5] = { 1, 1, 0, 1, 1 };

void Transmission_channel(const char* data) {

    srand(time(NULL)); // ����ø��� �ٸ� �� ���

    for (int i = 0; i < 16; i++) {
        if (rand() % 20 == 0) // 0�� ������ ������ ����; 5% Ȯ��
            (data[i] + 1) % 2;
    }

    for (int i = 0; i < 16; i++)
        cout << data[i];

}

int shift(int* binary, int* Q, int index) {
    int temp = 0, i;

    for (i = 1; i < 5; i++)
    {
        if (Q[i] == 1)
            temp =+ pow(2, 4 - i);
    }

    i = 0;
    do {
        temp = temp << 1;
        for (int j = 0; j < 4; j++)
            Q[j] = Q[j + 1];
        Q[4] = binary[index + 5];
        index++;
        i++;
    } while (temp != 0b10000);
    

    return index;
}

void Sender() {
    char data[16];
    int binary[16], Q[5]{}, bucket[5]{}, i, j;

    cin >> data;
    // �Է¹��� �����͸� ���� ���ڷ� ��ȯ
    for (i = 0; i < 12; i++)
        binary[i] = data[i] - '0';
    for (; i < 16; i++)
        binary[i] = 0;

    // bucket�� ù �ټ��ڸ� ����
    for (i = 0; i < 5; i++)
        bucket[i] = binary[i];

    // dividsor�� 12�� �ݺ� ������
    for (i = 0; i < 12; i++) {
        // bucket�� ù��° ��Ұ� 0�̸� �������� ����
        if (bucket[0] == 0) {
            for (j = 0; j < 5; j++) {
                bucket[j] = binary[i + 1 + j];
            }
            continue;
        }

        // XOR ����
        for (j = 0; j < 5; j++)
            Q[j] = divisor[j] ^ bucket[j];
        
        i = shift(binary, Q, i);
        for (j = 0; j < 5; j++)
            bucket[j] = Q[j];
    }

    cout << data << endl;
    cout << binary;

    // for (i = 0; i < )

}

int main() {

    Sender();

}

