#include <iostream>
#include <time.h>

using namespace std;

void insertionSort(int arr[], int len);
void bubbleSort(int arr[], int len);

int  n1 = 0, n2 = 0, n3 = 0, n4 = 0;

int main() {
	int len;

	cout << "Enter number of inputs: ";
	cin >> len;

	int* arr = new int[len];

	cout << "Enter array";
	for (int i = 0; i < len; i++)
		cin >> arr[i];

	insertionSort(arr, len);
	cout << endl;
	bubbleSort(arr, len);



	cout << n4;


	delete[] arr;
	return 0;
}

void insertionSort(int arr[], int len) {
	for (int cur = 1; cur <= len; cur++) {
		bool is_end = 0;
		int temp = arr[cur]; // temp�� ���� ���� ����
		int walker; // �����̸� ���� index
		for (walker = cur - 1; walker >= 0 && !is_end;) {
			if (arr[walker] > temp) {
				arr[walker + 1] = arr[walker]; // ���� ������ ���� ��󺸴� ������ ��ĭ�� �б�
				walker--;
			}
			else
				is_end = 1;
			n1++;
		}
		arr[walker + 1] = temp; // �̷� ĭ�� �� ���� ����
		n1++;
	}

	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";

	return;
}

void bubbleSort(int arr[], int len) {
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