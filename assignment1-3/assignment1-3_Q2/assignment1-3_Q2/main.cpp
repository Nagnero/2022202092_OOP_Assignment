#include <iostream>
#include <cmath>

using namespace std;

int cal(int num, int de_num, int cnt);
bool check_repeat(int cnt); // ��°��� �ݺ��Ǵ��� Ȯ��
int GCD(int a, int b);

int output[50];

int main() {
    // ���� �����
    double Vout, Ps, Pload, Iall;
    // num�� ����, de_num�� �и� �ǹ�
    int R1, R2, Rload = 0, Vs, num, de_num, gcd;

    // �Է°� �ޱ�
    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> Rload;

    // Rload�� 0�� ���
    if (Rload == 0) {
        num = Vs * R2;
        de_num = R1 + R2;
        Vout = (double)num / de_num;
    }
    else { // Rload�� 0�� �ƴ� ��� power ratio�� ���� power�� ���
        num = Vs * R2 * Rload * (Rload + R2);
        de_num = (R1 * (Rload + R2) + R2 * Rload) * (Rload + R2);
        Vout = (double)num / de_num;
        Iall = (double)(Vs * (R2 + Rload)) / (R1 * (R2 + Rload) + (R2 * Rload));

        // power�� ���
        Ps = Iall * Vs;
        Pload = (Vout * R2 * Iall) / (R2 + Rload);
    }

    // Vout ���
    cout << endl << "Vout: " << num << "/" << de_num;
    
    // ����� ������ �и� ������ �ִ����� ���ϱ�
    if (num <= de_num)
        gcd = GCD(de_num, num);
    else
        gcd = GCD(num, de_num);

    // �и� ���ڸ� ���м��� ��Ÿ����
    num /= gcd;
    de_num /= gcd;
  
    // ������ ����
    int pass_num, integer = num / de_num, cnt = 0;
    if (integer != 0)
        pass_num = (num % de_num) * 10;
    else
        pass_num = num * 10;


    // ���ѼҼ����� �Ǵ��ϱ� ����
    // �и��� ��� �� 2�� 5�� ���� ī����
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
    
    // �и��� ������� 2�� 5�� ����
    temp = de_num;
    for (int i = 0; i < num_2; i++)
        temp /= 2;
    for (int i = 0; i < num_5; i++)
        temp /= 5;
    
    if (temp != 1) {// �и��� ���μ��� 2�� 5�ۿ� ������ ���ѼҼ��̹Ƿ� ���� X

        output[cnt++] = pass_num / de_num; // 0��°�� 1 ����
        pass_num = (pass_num % de_num) * 10; // 30 ����
        output[cnt++] = pass_num / de_num; // 1��°�� 4 ����
        pass_num = (pass_num % de_num) * 10; // 20 ����
        cnt = cal(pass_num, de_num, cnt);

        // ��ȯ�Ҽ� ���
        cout << " = " << integer << ".(";
        for (int i = 0; i < cnt; i++)
            cout << output[i];
        cout << ")";
    }

    // power ������ �Ҽ����Ʒ� �ι�°�ڸ����� ���
    if (Rload != 0) {
        cout << fixed;
        cout.precision(2);
        cout << endl << "Load power ratio: " << (Pload / Ps) * 100 << "%";
    }

    return 0;
}

// �м� ������ �ؼ� ���� �����ϴ� ����Լ�
int cal(int num, int de_num, int cnt) {
    // ���� �ݺ��Ǵ��� Ȯ���ϸ� �� �迭 ������ ������ ��ȯ
    if (check_repeat(cnt))
        return cnt / 2;

    // ���� �迭�� ����
    output[cnt++] = num / de_num;
    // ����Լ� ȣ��
    cal((num % de_num) * 10, de_num, cnt);
}

// �迭�� �ݺ��Ǵ��� Ȯ���ϴ� �Լ�
bool check_repeat(int cnt) {
    // ¦���� �ƴϸ� �ݺ��� �ȵǹǷ� 0��ȯ
    if (cnt % 2 == 1)
        return 0;

    // ¦���� ��ü �迭 ������ ���ݸ�ŭ �ݺ���
    int mid = cnt / 2;
    for (int i = 0; i < mid; i++) { // ���� �迭�� �ݺ��Ǵ��� Ȯ��
        if (output[i] != output[mid + i])
            return 0;
    }

    return 1;
}

// �ִ������� ��ȯ�ϴ� ����Լ�
int GCD(int a, int b) {
    if (b == 0)
        return a;

    GCD(b, a % b);
}