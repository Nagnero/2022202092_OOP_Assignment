#include <iostream>
using namespace std;

bool check_repeat(int result[], int target);

int main() {
    char arr1[30]{}, arr2[30]{}, total[60]{};
    int len1 = 0, len2 = 0, result[20]{}, i, j, cnt, index = 0;

    cout << "Enter two number." << endl;
    cin >> arr1 >> arr2;

    while (arr1[len1] != NULL)
        len1++;

    while (arr2[len2] != NULL)
        len2++;

    for (i = 0; i < len1; i++)
        total[i] = arr1[i];
    for (; i < len1 + len2; i++)
        total[i] = arr2[i - len1];

    for (i = 0; i < len1 + len2; i++) { // 전체 반복
        cnt = 0;
        if (check_repeat(result, total[i] - 48)) { // 이미 저장된 값인지 확인
            result[index] = total[i] - 48;
            for (j = 0; j < len1 + len2; j++) { // 같은 숫자가 있는지 카운트
                if (result[index] == total[j] - 48)
                    cnt++;
            }
            result[index + 1] = cnt;
            index += 2;
        }
    }

    for (i = 0; i < index; i++)
        cout << result[i];
};

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