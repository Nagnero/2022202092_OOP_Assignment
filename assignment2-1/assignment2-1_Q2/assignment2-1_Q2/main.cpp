#include <iostream>

using namespace std;

void search(char maze[][30], int curx, int cury, int destx, int desty, int cnt, int col, int row);


int main() {
	int row, col, i, j, x1, x2, y1, y2, cnt = 1;
	char temp, maze[30][30]{};

	// 미로의 폭과 너비 입력
	cin >> col >> row;

	// 2차원배열에 미로 입력받기
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			cin >> temp;
			if (temp == '\0')
				continue;
			maze[i][j] = temp;
		}
	}

	// 시작지점과 도착지점 좌표로 설정
	cin >> x1 >> y1 >> x2 >> y2;
	// 이후 입력값 index화하기 위해 1씩 빼주기
	x1--; y1--; x2--; y2--;


	search(maze, x1, y1, x2, y2, cnt, col - 1, row - 1);


	_CrtDumpMemoryLeaks();
	return 0;
}

void search(char maze[][30], int curx, int cury, int destx, int desty, int cnt, int col, int row) {
	if (curx == destx && cury == desty)
		cout << cnt;

	// 위로 이동하는 경우
	if (cury > 0 && maze[cury - 1][curx] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx, cury - 1, destx, desty, cnt + 1, col, row);
	}
	// 오른쪽으로 이동하는 경우
	if (curx < row && maze[cury][curx + 1] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx + 1, cury, destx, desty, cnt + 1, col, row);
	}
	// 아래로 이동하는 경우
	if (cury < col && maze[cury + 1][curx] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx, cury + 1, destx, desty, cnt + 1, col, row);
	}
	// 왼쪽으로 이동하는 경우
	if (curx > 0 && maze[cury][curx - 1] != '1') {
		maze[cury][curx] = '1';
		search(maze, curx - 1, cury, destx - 1, desty, cnt + 1, col, row);
	}
}