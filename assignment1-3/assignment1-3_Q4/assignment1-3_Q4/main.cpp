#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

// ����� �����Լ� prototype 
void insertionSort(int* arr, int len);
void quickSort(int* arr, int start, int end);
void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);
void bubbleSort(int* arr, int len);


int main() {
	// �ð� �����ϱ� ���� ���۾�
	LARGE_INTEGER ticksPerSec, time_start, time_end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	int len, i ,j;
	
	cout << "Enter number of inputs: ";
	cin >> len;

	// 2���� �����迭 �Ҵ�, 4xlen ¥�� 2���� �迭
	int** arr = new int*[4];
	for (i = 0; i < 4; i++)
		arr[i] = new int[len];

	//������ ������ �迭 �Է�
	cout << "Enter array: ";
	for (j = 0; j < len; j++)
		cin >> arr[0][j];

	// �Է¹��� �迭�� 3�ٿ� ����
	for (i = 1; i < 4; i++)
		for (j = 0; j < len; j++)
			arr[i][j] = arr[0][j];

	
	QueryPerformanceCounter(&time_start); // �ð� ���� �������� time_start�� ����
	insertionSort(arr[0], len);
	QueryPerformanceCounter(&time_end); // �ð� ���� �������� time_end�� ����
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // �ɸ� �ð��� diff�� ����
	
	// ���� ��� ���
	cout << endl <<"Sorted order: ";
	for (int i = 0; i < len; i++)
		cout << arr[0][i] << " ";
	// ��� �� ���
	cout << endl << "Median number: " << arr[0][len / 2] << endl << endl;
	// ���� ���� �ҿ� �ð� ���
	cout << "duration time for insertion sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;


	QueryPerformanceCounter(&time_start); // �ð� ���� �������� time_start�� ����
	quickSort(arr[1], 0, len - 1);
	QueryPerformanceCounter(&time_end); // �ð� ���� �������� time_end�� ����
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // �ɸ� �ð��� diff�� ����
	// �� ���� �ҿ� �ð� ���
	cout << "duration time for quick sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;

	QueryPerformanceCounter(&time_start); // �ð� ���� �������� time_start�� ����
	mergeSort(arr[2], 0, len - 1);
	QueryPerformanceCounter(&time_end); // �ð� ���� �������� time_end�� ����
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // �ɸ� �ð��� diff�� ����
	// �պ� ���� �ҿ� �ð� ���
	cout << "duration time for merge sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;

	QueryPerformanceCounter(&time_start); // �ð� ���� �������� time_start�� ����
	bubbleSort(arr[3], len);
	QueryPerformanceCounter(&time_end); // �ð� ���� �������� time_end�� ����
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // �ɸ� �ð��� diff�� ����
	// ���� ���� �ҿ� �ð� ���
	cout << "duration time for bubble sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;


	// 2���� �����迭 �Ҵ� ����
	for (int i = 0; i < 4; i++)
		delete[] arr[i];
	delete[] arr;
	
	return 0;
}

// �������� �ռ�
void insertionSort(int* arr, int len) {
	for (int cur = 1; cur <= len - 1; cur++) {
		
		bool is_end = 0; // ���� flag
		int temp = arr[cur]; // temp�� ���� ���� ����
		int walker; // �����̸� ���� index
		// temp�� �������� ���� ���ĵ� �迭���� ���� ��
		for (walker = cur - 1; walker >= 0 && !is_end;) {
			if (arr[walker] > temp) {
				arr[walker + 1] = arr[walker]; // ���� ������ ���� ��󺸴� ������ ��ĭ�� �б�
				walker--;
			}
			else
				is_end = 1;
		}
		arr[walker + 1] = temp; // �̷� ĭ�� �� ���� ����
	}

	return;
}

// ������ �Լ�
void quickSort(int* arr, int start, int end) {
	
	if (start >= end) // ����Լ� Ż�� ����
		return;

	// ������(pivot)�� �迭�� ù��° ������ ����
	int pivot = start, temp;
	int left = pivot + 1, right = end;

	// ���ʿ��� �����ϴ� index�� �����ʿ��� �����ϴ� index���� �۾��������� �ݺ�
	while (left <= right) {
		// pivot���� ū ���� �����ų� ���� �����Ҷ����� index����
		while (arr[left] < arr[pivot] && left <= end)
			left++;
		// pivot���� ���� ���� �����ų� ù �κп� ������ ������ index ����
		while (arr[right] > arr[pivot] && right > start)
			right--;

		// ���� index�� ������ index���� Ŀ���� ������ ���� pivot�� ��ȯ
		if (left > right) {
			temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}
		else if (arr[left] == arr[right]) { // �ߺ��Ǵ� ��� ����ó��
			left++;
			right--;
		}
		// ���� index�� ������ index���� ������ ���� �� ��ȯ
		else {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	// ����Լ� ȣ��ι�
	quickSort(arr, start, right - 1); // pivot ���� �պκ�
	quickSort(arr, right + 1, end); // pivot ���� �޺κ�

	return;
}

// �պ� ���Ŀ��� ���� �Լ�
void mergeSort(int* arr, int start, int end) {

	if (start >= end) // ����Լ� Ż���
		return;

	int mid = (start + end) / 2; // �Է¹��� index�� �߰��� ����

	// �Է¹��� �迭�� ������ �ɰ��� ����Լ� ȣ���
	mergeSort(arr, start, mid); // ��� ���� ���� �ɰ���
	mergeSort(arr, mid + 1, end); // ��� ���� ������ �ɰ���

	// �ɰ��� �迭�� ���ϸ� ��ġ��
	merge(arr, start, mid, end);
}

// �պ� ���Ŀ��� �ռ� �Լ�
void merge(int* arr, int start, int mid, int end) {
	
	int i, j, cnt = start, L_len = mid - start + 1, R_len = end - mid;

	// �ӽ� �迭 �����Ҵ�
	int* L = new int[L_len];
	int* R = new int[R_len];

	// �������� �Ҵ��� �迭�� ���������� �� ����
	for (i = 0; i < L_len; i++)
		L[i] = arr[start + i];
	for (j = 0; j < R_len; j++)
		R[j] = arr[mid + 1 + j];

	i = 0, j = 0; // �ӽ� �迭�� �ε���
	// �� �ӽ� �迭���� �տ������� ���� ������� �� �迭�� �� ����
	while (i < L_len && j < R_len) {
		if (L[i] < R[j]) { // ������ ���� ��� 
			arr[cnt++] = L[i++];// ���ʰ� ���迭�� ����
		}
		else { // �������� ���� ���
			arr[cnt++] = R[j++]; // �����ʰ� ���迭�� ����
		}
	} // �����̳� �������߿� ���� index�� ������ ����� Ż��

	// ������ ����� ���� index�� ���� �����̳� ������ �� ���� ����
	while (i < L_len)
		arr[cnt++] = L[i++];
	while (j < R_len)
		arr[cnt++] = R[j++];

	// �����Ҵ� ����
	delete[] L;
	delete[] R;
}

// ���� ���� �Լ�
void bubbleSort(int* arr, int len) {

	// ���� �ݺ������� ���� ū ������ �� �ڿ� ����
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) { // ���� ���� ���ʺ��� ũ�� ���� ��ȯ
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return;
}