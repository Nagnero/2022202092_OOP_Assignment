#include <iostream>
using namespace std;

char arr[384][717];

void draw(int row, int col)
{
    arr[row][col] = '$';

    arr[row + 1][col - 1] = '$';
    arr[row + 1][col + 1] = '$';

    for (int i = 0; i < 5; i++)
        arr[row + 2][col - 2 + i] = '$';
}

void print_tri(int len, int row, int col)
{
    if (len == 3)
    {
        draw(row, col);
        return;
    }

    print_tri(len / 2, row, col);
    print_tri(len / 2, row + len / 2, col - len / 2);
    print_tri(len / 2, row + len / 2, col + len / 2);
}

int main()
{
    unsigned char k;
    int N, num, row, col, i, j;

    cin >> k;

    num = k - 48;
    N = pow(2, num - 1);
    row = 3 * N;
    col = 2 * row - 1;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            arr[i][j] = ' ';

    print_tri(row, 0 ,row - 1); 

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << arr[i][j];
        cout << endl;
    }

    return 0;
}

