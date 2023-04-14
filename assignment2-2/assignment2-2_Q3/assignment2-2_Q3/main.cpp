#include "CSVLoader.h" // 헤더파일 호출
#include <iostream>

using namespace std;


int main() {
	
	const char* path = "CSVLoader_Data.txt"; // 파일명 저장변수
	string input; // 입력값 저장 변수
	int command = 0, col = 0, row = 0;
	
	CSVLoader csv(path); // 객체 선언 및 CSV 자르기 진행
	float** dataSet = csv.getData(); // 이중 포인터 변수에 잘라놓은 데이터 저장
	cout << "Total column and row is " << csv.getRows() << " and " << csv.getCols() << endl << endl;
	// 데이터에 저장된 열과 행 출력

	while (1) { // command에 따라 반복
		cout << "Enter Command (1.print all, 2.print with index(col,row), 3.exit): ";
		cin >> command;
		// command가 1이면 출력 메서드함수 호출
		if (command == 1) {
			csv.print();
			cout << endl;
		}
		else if (command == 2) { // command가 2이면
			cin >> col >> row; // 인덱스를 입력받아
			cout << dataSet[row - 1][col - 1] << endl; // 인덱스에 접근하여 출력
		}
		else if (command == 3) // command가 3이면 탈출
			break;
		else
			cout << "Enter vaild command. " << endl;
	}

	return 0;
}