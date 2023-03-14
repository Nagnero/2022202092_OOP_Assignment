#include <iostream>
#include <cmath>
using namespace std;

int det_22(int i1, int i2, int j1, int j2, int mat[][3]);

int main()
{
	int matrix[3][3], cofact[3][3], i, j, det = 0;
	double inverse[3][3];
	
	cout << "Enter 3x3 Matrix" << endl;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> matrix[i][j];

	for (i = 0; i < 3; i++)
	{
		det += matrix[i][0] * det_22((i + 1) % 3, (i + 2) % 3, 1, 2, matrix) * pow(-1, i);
	}

	if (det < 0 || det == 0)
	{
		cout << "The inverse matrix does not exist." << endl;
		return 0;
	}

	for(i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cofact[i][j] = det_22((i + 1) % 3, (i + 2) % 3, (j + 1) % 3, (j + 2) % 3, matrix) * pow(-1, i + j);

		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[j][i] = cofact[i][j]; // matrix¿¡ 

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			inverse[i][j] = static_cast<double>(matrix[i][j]) / det;
			//cout << fixed;
			cout.precision(2);
			cout << inverse[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int det_22(int i1, int i2, int j1, int j2, int mat[][3])
{
	if (i1 > i2)
	{
		int temp = i1;
		i1 = i2;
		i2 = temp;
	}
	if (j1 > j2)
	{
		int temp = j1;
		j1 = j2;
		j2 = temp;
	}
	return mat[i1][j1] * mat[i2][j2] - mat[i1][j2] * mat[i2][j1];
}

