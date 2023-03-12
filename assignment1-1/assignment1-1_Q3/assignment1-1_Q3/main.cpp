#include <iostream>
using namespace std;

int GCD(int x, int y);

int main()
{
	int a, b, gcd;
	long long lcm;

	cout << "Enter two number ";
	cin >> a >> b;

	if (a > b)
	{
		gcd = a;
		a = b;
		b = gcd;
	}

	gcd = GCD(a, b);
	lcm = static_cast<long long>(a) * b;

	cout << endl << "GCD : " << gcd << endl << "LCD : " << lcm << endl;

	return 0;
}

int GCD(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}