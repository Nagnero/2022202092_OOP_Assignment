#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c;

	cout << "Enter a, b, c: ";
	cin >> a >> b >> c;

	cout << "the roots of " << a << "x^2 + " << b << "x + " << c << " = 0 :" << endl << endl;

	if (a == 0)
	{
		cout << "Unexpected factor of a quadratic term" << endl;
	}
	else if (pow(b, 2) - 4 * a * c == 0)
	{
		cout << "X1, X2: " << -b / 2 * a <<endl;
	}
	else if (pow(b, 2) - 4 * a * c == 0 < 0)
	{
		cout << "The equation has no real number solution" << endl;
	}
	else
	{
		float temp = pow(b, 2) - 4 * a * c;
		cout << "X1 = " << (-b + sqrt(temp)) / 2 * a << ", X2 = " << (-b - sqrt(temp)) / 2 * a << endl;
	}

	return 0;
}