#include <iostream>
#include <cmath>

using namespace std;

int cal(int num, int de_num, int cnt);
bool check_repeat(int cnt); // 출력값이 반복되는지 확인
int GCD(int a, int b);

int output[50];

int main() {
    // 변수 선언부
    double Vout, Ps, Pload, Iall;
    // num은 분자, de_num은 분모 의미
    int R1, R2, Rload = 0, Vs, num, de_num, gcd;

    // 입력값 받기
    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> Rload;

    // Rload가 0인 경우
    if (Rload == 0) {
        num = Vs * R2;
        de_num = R1 + R2;
        Vout = (double)num / de_num;
    }
    else { // Rload가 0이 아닌 경우 power ratio를 위한 power값 계산
        num = Vs * R2 * Rload * (Rload + R2);
        de_num = (R1 * (Rload + R2) + R2 * Rload) * (Rload + R2);
        Vout = (double)num / de_num;
        Iall = (double)(Vs * (R2 + Rload)) / (R1 * (R2 + Rload) + (R2 * Rload));

        // power값 계산
        Ps = Iall * Vs;
        Pload = (Vout * R2 * Iall) / (R2 + Rload);
    }

    // Vout 출력
    cout << endl << "Vout: " << num << "/" << de_num;
    
    // 계산한 전압의 분모 분자의 최대공약수 구하기
    if (num <= de_num)
        gcd = GCD(de_num, num);
    else
        gcd = GCD(num, de_num);

    // 분모 분자를 기약분수로 나타내기
    num /= gcd;
    de_num /= gcd;
  
    // 정수부 저장
    int pass_num, integer = num / de_num, cnt = 0;
    if (integer != 0)
        pass_num = (num % de_num) * 10;
    else
        pass_num = num * 10;


    // 유한소수인지 판단하기 위해
    // 분모의 약수 중 2와 5의 개수 카운팅
    int num_2 = 0, num_5 =0, temp = de_num;
    while (temp) {
        if (temp % 2 == 0) {
            num_2++;
            temp /= 2;
        }
        else
            break;
    }
    temp = de_num;
    while (temp) {
        if (temp % 5 == 0) {
            num_5++;
            temp /= 5;
        }
        else
            break;
    }
    
    // 분모의 약수에서 2와 5를 없앰
    temp = de_num;
    for (int i = 0; i < num_2; i++)
        temp /= 2;
    for (int i = 0; i < num_5; i++)
        temp /= 5;
    
    if (temp != 1) {// 분모의 소인수가 2와 5밖에 없으면 유한소수이므로 실행 X

        output[cnt++] = pass_num / de_num; // 0번째에 1 저장
        pass_num = (pass_num % de_num) * 10; // 30 저장
        output[cnt++] = pass_num / de_num; // 1번째에 4 저장
        pass_num = (pass_num % de_num) * 10; // 20 저장
        cnt = cal(pass_num, de_num, cnt);

        // 순환소수 출력
        cout << " = " << integer << ".(";
        for (int i = 0; i < cnt; i++)
            cout << output[i];
        cout << ")";
    }

    // power 비율을 소수점아래 두번째자리까지 출력
    if (Rload != 0) {
        cout << fixed;
        cout.precision(2);
        cout << endl << "Load power ratio: " << (Pload / Ps) * 100 << "%";
    }

    return 0;
}

// 분수 연산을 해서 몫을 저장하는 재귀함수
int cal(int num, int de_num, int cnt) {
    // 몫이 반복되는지 확인하면 총 배열 길이의 절반을 반환
    if (check_repeat(cnt))
        return cnt / 2;

    // 몫을 배열에 저장
    output[cnt++] = num / de_num;
    // 재귀함수 호출
    cal((num % de_num) * 10, de_num, cnt);
}

// 배열이 반복되는지 확인하는 함수
bool check_repeat(int cnt) {
    // 짝수가 아니면 반복이 안되므로 0반환
    if (cnt % 2 == 1)
        return 0;

    // 짝수면 전체 배열 길이의 절반만큼 반복문
    int mid = cnt / 2;
    for (int i = 0; i < mid; i++) { // 같은 배열이 반복되는지 확인
        if (output[i] != output[mid + i])
            return 0;
    }

    return 1;
}

// 최대공약수를 반환하는 재귀함수
int GCD(int a, int b) {
    if (b == 0)
        return a;

    GCD(b, a % b);
}