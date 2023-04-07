#include <iostream>

using namespace std;

// ��ã�� ����Լ� �����
void search(char** maze, int curx, int cury, int destx, int desty, int cnt, int col, int row);

int main() {
	int row, col, i, j, x1, x2, y1, y2, cnt = 1;
	char temp;

	// �̷��� ���� �ʺ� �Է�
	cin >> col >> row;

	// �ִ� ũ�� ���� Ȯ�� ���ǹ�
	if (col > 31 || row > 31) {
		cout << "�ִ� �̷� ũ�⿡ �������� �ʽ��ϴ�." << endl;
		return 0;
	}

	// 2���� �����迭�� �̷� ũ�⸸ŭ �Ҵ�
	char** maze = new char* [col];
	for (i = 0; i < col; i++)
		maze[i] = new char[row];

	// 2�����迭�� �̷� �Է¹ޱ�
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			cin >> temp; // �ӽ� ������ ����ް�
			if (temp == '\0') // ����� ���� ���๮�ڸ� �ǳʶٱ�
				continue;
			else
				maze[i][j] = temp; // �ƴϸ� �̷� �迭�� ����
		}
	}

	// ���������� �������� ��ǥ �Է¹ޱ�
	cin >> x1 >> y1 >> x2 >> y2;
	// ���� �Է°� indexȭ�ϱ� ���� 1�� ���ֱ�
	x1--; y1--; x2--; y2--;

	// ����Լ� ȣ��
	search(maze, x1, y1, x2, y2, cnt, col - 1, row - 1);

	// �����Ҵ� ����
	for (i = 0; i < col; i++)
		delete[] maze[i];
	delete[] maze;

	return 0;
}

// ��ã�� ����Լ� ���Ǻ�
// �Ű������� �̷ι迭, ���� xy��ǥ, ��ǥ xy��ǥ, �̵��Ÿ�(cnt), �ִ� ��� ���� ����
void search(char** maze, int curx, int cury, int destx, int desty, int cnt, int col, int row) {
	// ����Լ� Ż���. ���� ��ǥ�� ��ǥ ��ǥ�� ������ Ż��
	if (curx == destx && cury == desty)
		cout << cnt;

	// ���� �̵��ϴ� ���. ���� ��ġ�� �׵θ��� �ƴϰų� ��ĭ�� 1�� �ƴѰ��
	if (cury > 0 && maze[cury - 1][curx] != '1') {
		maze[cury][curx] = '1'; // ���� ��ġ�� 1�� �����Ͽ� ��湮 ����
		search(maze, curx, cury - 1, destx, desty, cnt + 1, col, row);
	}
	// ���������� �̵��ϴ� ���. ���� ��ġ�� �׵θ��� �ƴϰų� ������ĭ�� 1�� �ƴѰ��
	if (curx < row && maze[cury][curx + 1] != '1') {
		maze[cury][curx] = '1';// ���� ��ġ�� 1�� �����Ͽ� ��湮 ����
		search(maze, curx + 1, cury, destx, desty, cnt + 1, col, row);
	}
	// �Ʒ��� �̵��ϴ� ���. ���� ��ġ�� �׵θ��� �ƴϰų� �Ʒ�ĭ�� 1�� �ƴѰ��
	if (cury < col && maze[cury + 1][curx] != '1') {
		maze[cury][curx] = '1';// ���� ��ġ�� 1�� �����Ͽ� ��湮 ����
		search(maze, curx, cury + 1, destx, desty, cnt + 1, col, row);
	}
	// �������� �̵��ϴ� ���. ���� ��ġ�� �׵θ��� �ƴϰų� ����ĭ�� 1�� �ƴѰ��
	if (curx > 0 && maze[cury][curx - 1] != '1') {
		maze[cury][curx] = '1';// ���� ��ġ�� 1�� �����Ͽ� ��湮 ����
		search(maze, curx - 1, cury, destx, desty, cnt + 1, col, row);
	}
}