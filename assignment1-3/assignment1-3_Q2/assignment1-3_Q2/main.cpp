#include <iostream>
#include <cmath>

using namespace std;

int pre_cal(int& numerator, int& denominator);
int GCD(int a, int b);

int main() {
    double Vout;
    int R1, R2, Rload = 0, Vs, numerator, denominator, gcd;

    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> Rload;

    if (Rload == 0) {
        numerator = Vs * R2;
        denominator = R1 + R2;
        Vout = (double)numerator / denominator;
    }
    else {
        numerator = Vs * R2 * Rload * (Rload + R2);
        denominator = (R1 * (Rload + R2) + R2 * Rload) * (Rload + R2);
        Vout = (double)numerator / denominator;
    }

    cout << "Vout: " << numerator << "/" << denominator;
    
    if (numerator <= denominator)
        gcd = GCD(denominator, numerator);
    else
        gcd = GCD(numerator, denominator);

    // 분모 분자를 기약분수로 나타내기
    numerator /= gcd;
    denominator /= gcd;

    cin >> numerator >> denominator;

    pre_cal(numerator, denominator);

    cout << "Vout: " << numerator << "/" << denominator;


}

int pre_cal(int& numerator, int& denominator) {
    if (numerator < denominator)
        return 0;
    else if (numerator / 10 == 0)
        return 0;

    numerator /= 10;
    pre_cal(numerator, denominator);
}

int GCD(int a, int b) {
    if (b == 0)
        return a;

    GCD(b, a % b);
}