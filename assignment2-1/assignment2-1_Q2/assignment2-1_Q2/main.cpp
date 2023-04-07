#include <iostream>

using namespace std;

// 길찾기 재귀함수 선언부
void search(char** maze, int curx, int cury, int destx, int desty, int cnt, int col, int row);

int main() {
	int row, col, i, j, x1, x2, y1, y2, cnt = 1;
	char temp;

	// 미로의 폭과 너비 입력
	cin >> col >> row;

	// 최대 크기 조건 확인 조건문
	if (col > 31 || row > 31) {
		cout << "최대 미로 크기에 부합하지 않습니다." << endl;
		return 0;
	}

	// 2차원 동적배열로 미로 크기만큼 할당
	char** maze = new char* [col];
	for (i = 0; i < col; i++)
		maze[i] = new char[row];

	// 2차원배열에 미로 입력받기
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			cin >> temp; // 임시 변수에 저장받고
			if (temp == '\0') // 저장된 값이 개행문자면 건너뛰기
				continue;
			else
				maze[i][j] = temp; // 아니면 미로 배열에 저장
		}
	}

	// 시작지점과 도착지점 좌표 입력받기
	cin >> x1 >> y1 >> x2 >> y2;
	// 이후 입력값 index화하기 위해 1씩 빼주기
	x1--; y1--; x2--; y2--;

	// 재귀함수 호출
	search(maze, x1, y1, x2, y2, cnt, col - 1, row - 1);

	// 동적할당 해제
	for (i = 0; i < col; i++)
		delete[] maze[i];
	delete[] maze;

	return 0;
}

// 길찾기 재귀함수 정의부
// 매개변수로 미로배열, 현재 xy좌표, 목표 xy좌표, 이동거리(cnt), 최대 행과 열의 개수
void search(char** maze, int curx, int cury, int destx, int desty, int cnt, int col, int row) {
	// 재귀함수 탈출부. 현재 좌표와 목표 좌표가 같으면 탈출
	if (curx == destx && cury == desty)
		cout << cnt;

	// 위로 이동하는 경우. 현재 위치가 테두리가 아니거나 위칸이 1이 아닌경우
	if (cury > 0 && maze[cury - 1][curx] != '1') {
		maze[cury][curx] = '1'; // 현재 위치에 1을 저장하여 재방문 방지
		search(maze, curx, cury - 1, destx, desty, cnt + 1, col, row);
	}
	// 오른쪽으로 이동하는 경우. 현재 위치가 테두리가 아니거나 오른쪽칸이 1이 아닌경우
	if (curx < row && maze[cury][curx + 1] != '1') {
		maze[cury][curx] = '1';// 현재 위치에 1을 저장하여 재방문 방지
		search(maze, curx + 1, cury, destx, desty, cnt + 1, col, row);
	}
	// 아래로 이동하는 경우. 현재 위치가 테두리가 아니거나 아래칸이 1이 아닌경우
	if (cury < col && maze[cury + 1][curx] != '1') {
		maze[cury][curx] = '1';// 현재 위치에 1을 저장하여 재방문 방지
		search(maze, curx, cury + 1, destx, desty, cnt + 1, col, row);
	}
	// 왼쪽으로 이동하는 경우. 현재 위치가 테두리가 아니거나 왼쪽칸이 1이 아닌경우
	if (curx > 0 && maze[cury][curx - 1] != '1') {
		maze[cury][curx] = '1';// 현재 위치에 1을 저장하여 재방문 방지
		search(maze, curx - 1, cury, destx, desty, cnt + 1, col, row);
	}
}