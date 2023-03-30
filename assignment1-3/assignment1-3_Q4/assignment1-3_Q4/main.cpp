#include <iostream>
#include <time.h>

using namespace std;

void insertionSort(int* arr, int len);
void bubbleSort(int* arr, int len);

int  n1 = 0, n2 = 0, n3 = 0, n4 = 0;

int main() {
	int len, i ,j;

	cout << "Enter number of inputs: ";
	cin >> len;

	int** arr = new int*[4];
	for (i = 0; i < 4; i++)
		arr[i] = new int[len];

	cout << "Enter array: ";
	for (j = 0; j < len; j++)
		cin >> arr[0][j];

	for (i = 1; i < 4; i++)
		for (j = 0; j < len; j++)
			arr[i][j] = arr[0][j];

	insertionSort(arr[0], len);
	cout << endl;
	bubbleSort(arr[3], len);



	cout << n4;


	delete[] arr;
	return 0;
}

void insertionSort(int* arr, int len) {
	for (int cur = 1; cur <= len - 1; cur++) {
		bool is_end = 0;
		int temp = arr[cur]; // temp에 비교할 기준 저장
		int walker; // 움직이며 비교할 index
		for (walker = cur - 1; walker >= 0 && !is_end;) {
			if (arr[walker] > temp) {
				arr[walker + 1] = arr[walker]; // 비교할 기준이 비교할 대상보다 작으면 한칸씩 밀기
				walker--;
			}
			else
				is_end = 1;
			n1++;
		}
		arr[walker + 1] = temp; // 미룬 칸에 비교 기준 삽입
		n1++;
	}

	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";

	return;
}

void bubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			n4++;
		}
		n4++;
	}

	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";

	return;
}