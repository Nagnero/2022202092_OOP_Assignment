#include <iostream>
#include <time.h>


using namespace std;

void insertionSort(int* arr, int len);
void quickSort(int* arr, int start, int end);
void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);
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
	quickSort(arr[1], 0, len - 1);
	for (int i = 0; i < len; i++)
		cout << arr[1][i] << " ";
	cout << endl;
	mergeSort(arr[2], 0, len - 1);
	for (int i = 0; i < len; i++)
		cout << arr[1][i] << " ";
	cout << endl;
	bubbleSort(arr[3], len);



	cout << n4;


	delete[] arr;
	return 0;
}

void insertionSort(int* arr, int len) {
	for (int cur = 1; cur <= len - 1; cur++) {
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

void quickSort(int* arr, int start, int end) {
	if (start >= end)
		return;

	int pivot = start, temp;
	int left = pivot + 1, right = end;

	while (left <= right) {
		while (arr[left] < arr[pivot] && left <= end)
			left++;
		while (arr[right] > arr[pivot] && right > start)
			right--;

		if (left > right) {
			temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	quickSort(arr, start, right - 1); // pivot ���� �պκ�
	quickSort(arr, right + 1, end); // pivot ���� �޺κ�

	return;
}

void mergeSort(int* arr, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, start, mid, end);
}

void merge(int* arr, int start, int mid, int end) {
	
	int i, j, cnt = start, L_len = mid - start + 1, R_len = end - mid;

	// �ӽ� �迭
	int* L = new int[L_len];
	int* R = new int[R_len];

	for (i = 0; i < L_len; i++)
		L[i] = arr[start + i];
	for (j = 0; j < R_len; j++)
		R[j] = arr[mid + 1 + j];

	i = 0, j = 0; // �ӽ� �迭�� �ε���
	while (i < L_len && j < R_len) {
		if (L[i] < R[j]) {
			arr[cnt++] = L[i++];
		}
		else {
			arr[cnt++] = R[j++];
		}
	}

	while (i < L_len)
		arr[cnt++] = L[i++];

	while (j < R_len)
		arr[cnt++] = R[j++];

	delete[] L;
	delete[] R;
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