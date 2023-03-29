#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

// �Է°��� 10������ ��ȯ�ϴ� �Լ��� prototype
int to_decimal(char* input, int& temp, int len, int c);
// ��ȯ�� 10������ �ٽ� �ٸ� �������� ��ȯ�ϴ� �Լ��� prototype
int to_target(int temp, int t);
int to_hexa(int temp);

int main() {
    char input[100]{};// �Է��� ���� �迭
    int c, t, len, temp = 0; // ���� ������ c�� ��ǥ ������ t

    // ����ڿ��� �Է°� �ޱ�
    cout << "Enter input : ";
    cin >> input >> c >> t;

    len = strlen(input); // �Է°��� �ڸ����� len�� ����

    // ���� �Է°��� 10������ ��ȯ�ϴ� �Լ� ȣ��
    // temp�� ��ȯ�� ������ ���� (pass by reference)
    to_decimal(input, temp, len, c); 

    // ��ȯ�� 10������ ��ǥ �������� ��ȯ �� ���
    // ��ȯ�� ��ǥ ������ ���� ȣ�� �Լ� �ٸ�
    if (t != 16)
        to_target(temp, t); // 2, 8, 10 ������ ���
    else
        to_hexa(temp); // 16������ ���

    return 0;
}

// ������ ��ȯ
int to_decimal(char* input, int& temp, int len, int c) {
    // 16������ �ƴ� ����� ���Ŀ� ���� 10������ ��ȯ
    if (c != 16) {
        for (int i = 0; i < len; i++) {
            // 16������ �ƴ϶�� �Է°��� �ϳ��� �����Ͽ� �ڸ����� ���� 10���� ��ȯ
            temp += (input[i] - '0') * pow(c, len - 1 - i);
        }
    }
    else { // 16������� ���ĺ��� �޴� ��� ���ڷ� �ٲ㼭 ��ȯ
        for (int i = 0; i < len; i++) {
            if (input[i] >= 'A' && input[i] <= 'F') {
                int num = input[i] - 'A' + 10;
                temp += num * pow(c, len - 1 - i);
            }
            else {
                // ���ĺ��� �ƴ� 16������ ���� �״�� 10������ ��ȯ
                temp += (input[i] - '0') * pow(c, len - 1 - i);
            }
        }
    }

    return 0;
}

// �������� ���ϴ� ���� ���� �� ���
int to_target(int temp, int t) {
    // ����Լ� Ż�� ����
    if (temp == 0)
        return 0;

    // �� ������ �´� ����(t)�� ������ ����Լ� ȣ��
    to_target(temp / t, t);
    cout << temp % t; // ù°�ڸ����� ���

    return 0;
}

int to_hexa(int temp) {
    // ����Լ� Ż������
    if (temp == 0)
        return 0;

    // 16���� ������ ����Լ� ȣ��
    to_hexa(temp / 16);

    // ù°�ڸ����� ���
    temp %= 16;
    if (temp < 10) {
        cout << temp;
    }
    else { // 10�̻��� ��� ���ĺ� �빮�ڷ� �ٲپ� ���
        cout << static_cast<char>(temp - 10 + 'A');
    }

    return 0;
}