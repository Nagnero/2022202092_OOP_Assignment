#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int degree, input[3]{}, temp = 0;
	// cos의 역삼각함수를 통해 PI를 찾아 저장
	float PI = acos(-1), rad, output[3]{};

	// 각도와 좌표를 입력받음
	cout << "Degrees: ";
	cin >> degree;
	cout << "Coordinate: ";
	cin >> input[0] >> input[1] >> input[2];

	// 입력받은 각도를 라디안으로 변형
	rad = degree * PI / 180;

	// 최소한의 연산으로 변환좌표를 구함
	output[0] = - cos(rad) * input[0] + sin(rad) * input[0];
	output[1] = sin(rad) * input[1] + cos(rad) * input[1];

	// 연산값 출력
	cout << output[0] << "  " << output[1] << "  " << output[2];

	return 0;
}