#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <cmath>

using namespace std;

// ���������� transmitted data ���� �� �ʱ�ȭ
char T[16]{};
// divisor ���������� ����
const int divisor[5] = { 1, 1, 0, 1, 1 };

// ����������Լ��� prototype
void Transmission_channel(const char* data);
void Sender();
int Receiver(const char* T);
int shift(int* binary, int* Q, int index);



int main() {

    Sender();
    
    return 0;
}

// Sender�Լ� ���Ǻ�
void Sender() {
    char data[16]; // ����ڿ��� �Է��� ���� ���ڹ迭
    int binary[16], Q[5]{}, bucket[5]{}, i, j;// �������� ������ �迭 �� �ӽ� �迭 ���� �� �ʱ�ȭ

    cin >> data;// ����ڿ��� �Է¹���

    // �Է¹��� �����͸� ���� ���ڷ� ��ȯ
    for (i = 0; i < 12; i++)
        binary[i] = data[i] - '0';

    // bucket�� ù �ټ��ڸ� ����
    for (i = 0; i < 5; i++)
        bucket[i] = binary[i];

    // dividsor�� 12�� �ݺ� ������
    for (i = 0; i < 12;) {
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

        int temp = i; // shift �Լ����� i�� �ٲ������ Ȯ���ϱ� ���� ����
        i = shift(binary, bucket, i); // shift �Լ� ȣ��
        if (temp == i) // i�� �������� �ʾҴٸ� 1 ����
            i++;

        for (j = 0; j < 5; j++)
            bucket[j] = Q[j];
    }

    // FCS�� bucket�� binary�迭 �ڿ� �߰��ϴ� �ݺ���
    for (; i < 16; i++)
        binary[i] = bucket[i - 11];

    // ���� �迭�� binary�� ������ �迭�� �����ϴ� �ݺ���
    for (i = 12; i < 16; i++)
        data[i] = binary[i] + '0';

    // ��ȣ ����ó�� �Լ� ���
    Transmission_channel(data);

    // �ܼ� ��º�
    cout << "Coded frame: ";
    for (i = 0; i < 16; i++)
        cout << data[i];

    cout << endl << "Received frame: ";
    for (i = 0; i < 16; i++)
        cout << T[i];

    cout << endl << "Reconstructed data: ";
    for (i = 0; i < 12; i++)
        cout << T[i];

    // ��ȣ �޾Ƽ� ���� ���� ��º�
    if (Receiver(T))
        cout << endl << "No detected error";
    else
        cout << endl << "Receiver has detected error" << endl;

}

// ��ȣ ����ó�� �Լ� ���Ǻ�
void Transmission_channel(const char* data) {

    srand(time(NULL)); // ����ø��� �ٸ� �� ���

    for (int i = 0; i < 16; i++) {
        if (rand() % 100 + 1 > 5) // 95% Ȯ���� ���� �迭�� ������ ����
            T[i] = data[i];
        else { // 5% Ȯ���� �� �ݴ�� ��ȯ �� ����
            int temp = data[i] - '0';
            temp = (temp + 1) % 2;
            T[i] = temp + '0';
        }
    }
}

int Receiver(const char* arr) {
    int binary[16], Q[5]{}, bucket[5]{}, i, j;

    // �Է¹��� �����͸� ���� ���ڷ� ��ȯ
    for (i = 0; i < 16; i++)
        binary[i] = arr[i] - '0';

    // bucket�� ù �ټ��ڸ� ����
    for (i = 0; i < 5; i++)
        bucket[i] = binary[i];

    // bucket�� ù��° ��Ұ� 0�̸� �������� ����, ù �Է°��� 0�ΰ��
    if (bucket[0] == 0) {
        for (j = 0; j < 5; j++) {
            bucket[j] = binary[1 + j];
        }
    }
    // dividsor�� 12�� �ݺ� ������
    for (i = 0; i < 12;) {

        // XOR ����
        for (j = 0; j < 5; j++)
            Q[j] = divisor[j] ^ bucket[j];

        int temp = i; // shift �Լ����� i�� �ٲ������ Ȯ���ϱ� ���� ����
        i = shift(binary, bucket, i); // shift �Լ� ȣ��
        if (temp == i) // i�� �������� �ʾҴٸ� 1 ����
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


    // temp�� 2������ �ٽ� ��ȯ�Ͽ� ����
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