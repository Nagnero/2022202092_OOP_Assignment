#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int degree, input[3], temp = 0;
	float PI = acos(-1), rad, output[3]{};

	cout <<PI;

	cout << "Degrees: ";
	cin >> degree;
	cout << "Coordinate: ";
	cin >> input[0] >> input[1] >> input[2];

	rad = degree * PI / 180;

	output[0] = - cos(rad) * input[0] + sin(rad) * input[0];
	output[1] = sin(rad) * input[1] + cos(rad) * input[1];

	cout << output[0] << "  " << output[1] << "  " << output[2];


	return 0;
}