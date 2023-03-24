#include <iostream>
using namespace std;

bool check_repeat(int result[], int target);

int main() {
    // 입력받을 배열 2개 및 전체 배열을 합칠 배열 1개 선언 후 초기화
    char arr1[30]{}, arr2[30]{}, total[60]{};
    int len1 = 0, len2 = 0, result[20]{}, i, j, cnt, index = 0;

    // 숫자 배열 두개 입력
    cout << "Enter two number." << endl;
    cin >> arr1 >> arr2;

    // 배열에 입력된 숫자의 갯수
    while (arr1[len1] != NULL)
        len1++;
    while (arr2[len2] != NULL)
        len2++;

    // total 배열에 두 배열 합쳐서 입력
    for (i = 0; i < len1; i++)
        total[i] = arr1[i];
    for (; i < len1 + len2; i++)
        total[i] = arr2[i - len1];

    for (i = 0; i < len1 + len2; i++) { // 전체 반복
        cnt = 0;
        if (check_repeat(result, total[i] - '0')) { // 이미 저장된 값인지 확인
            result[index] = total[i] - '0';
            for (j = 0; j < len1 + len2; j++) { // 같은 숫자가 있는지 카운트
                if (result[index] == total[j] - '0')
                    cnt++;
            }
            result[index + 1] = cnt;
            index += 2;
        }
    }

    // index만큼  result 배열 출력
    for (i = 0; i < index; i++)
        cout << result[i];
};

// 중복되는지 확인하는 사용자 정의함수
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