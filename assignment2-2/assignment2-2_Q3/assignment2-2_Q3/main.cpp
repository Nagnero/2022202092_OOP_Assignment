#include "CSVLoader.h"
#include <iostream>

using namespace std;


int main() {

	const char* path = "CSVLoader_Data.txt";
	string input;
	int command = 0, col = 0, row = 0;
	
	CSVLoader csv(path);
	float** dataSet = csv.getData();
	cout << "Total column and row is " << csv.getRows() << " and " << csv.getCols() << endl << endl;

	while (1) {
		cout << "Enter Command (1.print all, 2.print with index(col,row), 3.exit): ";
		cin >> command;

		if (command == 1) {
			csv.print();
			cout << endl;
		}
		else if (command == 2) {
			cin >> col >> row;
			cout << dataSet[col - 1][row - 1] << endl;
		}
		else if (command == 3)
			break;
		else
			cout << "Enter vaild command. " << endl;
	}

	return 0;
}