#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Vout, R1, R2, Rload = 0, Vs;

    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> Rload;

    if (Rload == 0) {
        Vout = (Vs * R2) / (R1 + R2);
    }
    else {
        int Radd = (R2 * Rload) / (Rload + R2);
        Vout = (Vs * Radd) / (R1 + Radd);
    }

    cout << "Vout: " << Vout;
}