#include <iostream>
using namespace std;

bool check_repeat(int result[], int target);

int main() {
    // �Է¹��� �迭 2�� �� ��ü �迭�� ��ĥ �迭 1�� ���� �� �ʱ�ȭ
    char arr1[30]{}, arr2[30]{}, total[60]{};
    int len1 = 0, len2 = 0, result[20]{}, i, j, cnt, index = 0;

    // ���� �迭 �ΰ� �Է�
    cout << "Enter two number." << endl;
    cin >> arr1 >> arr2;

    // �迭�� �Էµ� ������ ����
    while (arr1[len1] != NULL)
        len1++;
    while (arr2[len2] != NULL)
        len2++;

    // total �迭�� �� �迭 ���ļ� �Է�
    for (i = 0; i < len1; i++)
        total[i] = arr1[i];
    for (; i < len1 + len2; i++)
        total[i] = arr2[i - len1];

    for (i = 0; i < len1 + len2; i++) { // ��ü �ݺ�
        cnt = 0;
        if (check_repeat(result, total[i] - '0')) { // �̹� ����� ������ Ȯ��
            result[index] = total[i] - '0';
            for (j = 0; j < len1 + len2; j++) { // ���� ���ڰ� �ִ��� ī��Ʈ
                if (result[index] == total[j] - '0')
                    cnt++;
            }
            result[index + 1] = cnt;
            index += 2;
        }
    }

    // index��ŭ  result �迭 ���
    for (i = 0; i < index; i++)
        cout << result[i];
};

// �ߺ��Ǵ��� Ȯ���ϴ� ����� �����Լ�
bool check_repeat(int result[], int target) {
    int index = 0;

    while (result[index]) {
        if (result[index] == target)
            return 0;
        else
            index += 2;
    }

    return 1;
}