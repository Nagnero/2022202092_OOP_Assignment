#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

// 사용자 정의함수 prototype 
void insertionSort(int* arr, int len);
void quickSort(int* arr, int start, int end);
void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);
void bubbleSort(int* arr, int len);


int main() {
	// 시간 측정하기 위한 밑작업
	LARGE_INTEGER ticksPerSec, time_start, time_end, diff;
	QueryPerformanceFrequency(&ticksPerSec);

	int len, i ,j;
	
	cout << "Enter number of inputs: ";
	cin >> len;

	// 2차원 동적배열 할당, 4xlen 짜리 2차원 배열
	int** arr = new int*[4];
	for (i = 0; i < 4; i++)
		arr[i] = new int[len];

	//정렬을 진행할 배열 입력
	cout << "Enter array: ";
	for (j = 0; j < len; j++)
		cin >> arr[0][j];

	// 입력받은 배열을 3줄에 복사
	for (i = 1; i < 4; i++)
		for (j = 0; j < len; j++)
			arr[i][j] = arr[0][j];

	
	QueryPerformanceCounter(&time_start); // 시간 측정 시작점을 time_start로 설정
	insertionSort(arr[0], len);
	QueryPerformanceCounter(&time_end); // 시간 측정 종료점을 time_end로 설정
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // 걸린 시간을 diff에 저장
	
	// 정렬 결과 출력
	cout << endl <<"Sorted order: ";
	for (int i = 0; i < len; i++)
		cout << arr[0][i] << " ";
	// 가운데 값 출력
	cout << endl << "Median number: " << arr[0][len / 2] << endl << endl;
	// 삽입 정렬 소요 시간 출력
	cout << "duration time for insertion sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;


	QueryPerformanceCounter(&time_start); // 시간 측정 시작점을 time_start로 설정
	quickSort(arr[1], 0, len - 1);
	QueryPerformanceCounter(&time_end); // 시간 측정 종료점을 time_end로 설정
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // 걸린 시간을 diff에 저장
	// 퀵 정렬 소요 시간 출력
	cout << "duration time for quick sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;

	QueryPerformanceCounter(&time_start); // 시간 측정 시작점을 time_start로 설정
	mergeSort(arr[2], 0, len - 1);
	QueryPerformanceCounter(&time_end); // 시간 측정 종료점을 time_end로 설정
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // 걸린 시간을 diff에 저장
	// 합병 정렬 소요 시간 출력
	cout << "duration time for merge sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;

	QueryPerformanceCounter(&time_start); // 시간 측정 시작점을 time_start로 설정
	bubbleSort(arr[3], len);
	QueryPerformanceCounter(&time_end); // 시간 측정 종료점을 time_end로 설정
	diff.QuadPart = time_end.QuadPart - time_start.QuadPart; // 걸린 시간을 diff에 저장
	// 버블 정렬 소요 시간 출력
	cout << "duration time for bubble sort: "
		<< ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) << endl;


	// 2차원 동적배열 할당 해제
	for (int i = 0; i < 4; i++)
		delete[] arr[i];
	delete[] arr;
	
	return 0;
}

// 삽입정렬 합수
void insertionSort(int* arr, int len) {
	for (int cur = 1; cur <= len - 1; cur++) {
		
		bool is_end = 0; // 종료 flag
		int temp = arr[cur]; // temp에 비교할 기준 저장
		int walker; // 움직이며 비교할 index
		// temp를 기준으로 앞쪽 정렬된 배열들의 값과 비교
		for (walker = cur - 1; walker >= 0 && !is_end;) {
			if (arr[walker] > temp) {
				arr[walker + 1] = arr[walker]; // 비교할 기준이 비교할 대상보다 작으면 한칸씩 밀기
				walker--;
			}
			else
				is_end = 1;
		}
		arr[walker + 1] = temp; // 미룬 칸에 비교 기준 삽입
	}

	return;
}

// 퀵정렬 함수
void quickSort(int* arr, int start, int end) {
	
	if (start >= end) // 재귀함수 탈출 구문
		return;

	// 기준점(pivot)을 배열의 첫번째 값으로 고정
	int pivot = start, temp;
	int left = pivot + 1, right = end;

	// 왼쪽에서 시작하는 index가 오른쪽에서 시작하는 index보다 작아질때까지 반복
	while (left <= right) {
		// pivot보다 큰 값을 만나거나 끝에 도달할때까지 index증가
		while (arr[left] < arr[pivot] && left <= end)
			left++;
		// pivot보다 작은 값을 만나거나 첫 부분에 도착할 때까지 index 감소
		while (arr[right] > arr[pivot] && right > start)
			right--;

		// 왼쪽 index가 오른쪽 index보다 커지면 오른쪽 값을 pivot과 교환
		if (left > right) {
			temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}
		else if (arr[left] == arr[right]) { // 중복되는 경우 예외처리
			left++;
			right--;
		}
		// 왼쪽 index가 오른쪽 index보다 작으면 서로 값 교환
		else {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	// 재귀함수 호출부문
	quickSort(arr, start, right - 1); // pivot 기준 앞부분
	quickSort(arr, right + 1, end); // pivot 기준 뒷부분

	return;
}

// 합병 정렬에서 분할 함수
void mergeSort(int* arr, int start, int end) {

	if (start >= end) // 재귀함수 탈출부
		return;

	int mid = (start + end) / 2; // 입력받은 index의 중간값 지정

	// 입력받은 배열을 반으로 쪼개는 재귀함수 호출부
	mergeSort(arr, start, mid); // 가운데 기준 왼쪽 쪼개기
	mergeSort(arr, mid + 1, end); // 가운데 기준 오른쪽 쪼개기

	// 쪼개진 배열을 비교하며 합치기
	merge(arr, start, mid, end);
}

// 합병 정렬에서 합성 함수
void merge(int* arr, int start, int mid, int end) {
	
	int i, j, cnt = start, L_len = mid - start + 1, R_len = end - mid;

	// 임시 배열 동적할당
	int* L = new int[L_len];
	int* R = new int[R_len];

	// 동적으로 할당한 배열에 순차적으로 값 대입
	for (i = 0; i < L_len; i++)
		L[i] = arr[start + i];
	for (j = 0; j < R_len; j++)
		R[j] = arr[mid + 1 + j];

	i = 0, j = 0; // 임시 배열의 인덱스
	// 두 임시 배열에서 앞에서부터 작은 순서대로 본 배열에 값 대입
	while (i < L_len && j < R_len) {
		if (L[i] < R[j]) { // 왼쪽이 작은 경우 
			arr[cnt++] = L[i++];// 왼쪽값 본배열에 대입
		}
		else { // 오른쪽이 작은 경우
			arr[cnt++] = R[j++]; // 오른쪽값 본배열에 대입
		}
	} // 왼쪽이나 오른쪽중에 한쪽 index가 범위를 벗어나면 탈출

	// 범위를 벗어나지 않은 index에 따라 왼쪽이나 오른쪽 값 마저 대입
	while (i < L_len)
		arr[cnt++] = L[i++];
	while (j < R_len)
		arr[cnt++] = R[j++];

	// 동적할당 해제
	delete[] L;
	delete[] R;
}

// 버블 정렬 함수
void bubbleSort(int* arr, int len) {

	// 이중 반복문으로 제일 큰 수부터 맨 뒤에 정렬
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) { // 앞쪽 값이 뒤쪽보다 크면 서로 교환
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return;
}