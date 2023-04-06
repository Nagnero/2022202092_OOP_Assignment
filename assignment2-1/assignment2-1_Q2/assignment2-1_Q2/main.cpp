#include <iostream>

using namespace std;

void search(char** maze, int curx, int cury, int destx, int desty, int cnt, int col, int row);


int main() {
	int row, col, i, j, x1, x2, y1, y2, cnt = 1;
	char temp;

	// �̷��� ���� �ʺ� �Է�
	cin >> col >> row;

	if (col > 31 || row > 31) {
		cout << "�ִ� �̷� ũ�⿡ �������� �ʽ��ϴ�." << endl;
		return 0;
	}

	char** maze = new char* [col];
	for (i = 0; i < col; i++)
		maze[i] = new char[row];

	// 2�����迭�� �̷� �Է¹ޱ�
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			cin >> temp;
			if (temp == '\0')
				continue;
			maze[i][j] = temp;
		}
	}

	// ���������� �������� ��ǥ�� ����
	cin >> x1 >> y1 >> x2 >> y2;
	// ���� �Է°� indexȭ�ϱ� ���� 1�� ���ֱ�
	x1--; y1--; x2--; y2--;


	search(maze, x1, y1, x2, y2, cnt, col - 1, row - 1);

	for (i = 0; i < col; i++)
		delete[] maze[i];
	delete[] maze;

	return 0;
}

void search(char** maze, int curx, int cury, int destx, int desty, int cnt, int col, int row) {
	if (curx == destx && cury == desty)
		cout << cnt;

	// ���� �̵��ϴ� ���
	if (cury > 0 && maze[cury - 1][curx] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx, cury - 1, destx, desty, cnt + 1, col, row);
	}
	// ���������� �̵��ϴ� ���
	if (curx < row && maze[cury][curx + 1] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx + 1, cury, destx, desty, cnt + 1, col, row);
	}
	// �Ʒ��� �̵��ϴ� ���
	if (cury < col && maze[cury + 1][curx] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx, cury + 1, destx, desty, cnt + 1, col, row);
	}
	// �������� �̵��ϴ� ���
	if (curx > 0 && maze[cury][curx - 1] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx - 1, cury, destx - 1, desty, cnt + 1, col, row);
	}
}