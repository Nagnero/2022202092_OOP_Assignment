#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;


uint8_t** memory_alloc2D(size_t height, size_t width);
int memory_free2D(uint8_t** memory);
void swap(int& x, int& y); // 문자 위치 바꿈 사용자 정의함수


int main()
{
	const char* IMAGE_NAME = "Barbara_512x512_yuv400_8bit.raw";
	const char* RESULT_NAME2 = "Barbara_horizontalflip.raw"; // 수평반전 파일명
	const char* RESULT_NAME3 = "Barbara_verticalflip.raw"; // 수직반전 파일명
	const int IMAGE_HEIGHT = 512, IMAGE_WIDTH = 512;
	int x1, x2, y1, y2, i, j, crop_width, crop_height;

	FILE* fp = 0; // file pointer
	uint8_t** input_image = 0;
	uint8_t** output_image = 0;

	// 좌표 두개 입력받기
	cout << "1st coordinate : ";
	cin >> x1;
	cin.ignore(10, ','); // 콤마 입력 제외
	cin >> y1;
	cout << "2nd coordinate : ";
	cin >> x2;
	cin.ignore(10, ','); // 콤마 입력 제외
	cin >> y2;

	// 좌표를 배열의 index로 만들기 위해 1씩 빼주기
	x1--, x2--, y1--, y2--;


	// Load input image, 읽기 모드로 오픈
	fopen_s(&fp, IMAGE_NAME, "rb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << IMAGE_NAME << ")" << endl;
		return -1;
	}

	// 입력받은 이미지 사이즈만큼 배열 동적할당
	input_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH);
	if (input_image == 0)
	{
		cout << "Failed to allocate memory" << endl;
		return -1;
	}

	// 할당된 배열에 파일로부터 읽은 데이터 저장
	fread((uint8_t*)input_image[0], sizeof(uint8_t), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
	fclose(fp);

	//출력할 이미지 사이즈만큼 배열 동적할당
	output_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH);
	if (output_image == 0)
	{
		cout << "Failed to allocate memory" << endl;
		return -1;
	}

	// 사각형의 왼쪽 위와 오른쪽 아래 좌표로 설정하는 코드
	if (x1 > x2 && y1 > y2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	else if (x1 > x2 && y1 < y2) {
		swap(x1, x2);
	}
	else if (x1 < x2 && y1 > y2) {
		swap(y1, y2);
	}

	// 자른 이미지의 너비와 높이 계산
	crop_width = x2 - x1;
	crop_height = y2 - y1;

	// 자른 넓이만큼 output_image에 이차원 배열로 접근하여 데이터 저장
	for (i = 0; i < crop_height; i++)
		for (j = 0; j < crop_width; j++)
			output_image[i][j] = input_image[y1 + i][x1 + j];

	// 자른 넓이를 파일명에 나타내기 위한 로직
	char RESULT_NAME1[30] = "Barbara_Cropped_";
	// index  계산을 위한 각종 변수 선언 및 초기화
	int len = strlen(RESULT_NAME1), cnt = 1, temp = crop_width, temp1 = crop_width;
	while (temp /= 10)
		cnt++; // 너비 자릿수 세기
	for (i = 0; i < cnt; i++) { // 너비의 뒷자리부터 배열에 삽입
		RESULT_NAME1[len + cnt - i - 1] = temp1 % 10 + 48; // char형을 ASKII코드상 숫자로 변환
		temp1 /= 10;
	}
	len = strlen(RESULT_NAME1) + 1;
	strcat(RESULT_NAME1, "x"); // 파일명 형식상 'x' 추가

	// 높이에 대해 윗 과정 반복
	cnt = 1; temp = crop_height, temp1 = crop_height;
	while (temp /= 10)
		cnt++;
	for (i = 0; i < cnt; i++) {
		RESULT_NAME1[len + cnt - i - 1] = temp1 % 10 + 48;
		temp1 /= 10;
	}
	// 마지막에 '.raw' 문자열 추가하여 확장자 추가
	strcat(RESULT_NAME1, ".raw");


	fopen_s(&fp, RESULT_NAME1, "wb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME1 << ")" << endl;
		return -1;
	}
	// 한줄씩 접근하여 자른 너비만큼 데이터 입력
	for(int i = 0; i < crop_height; i++)
		fwrite((uint8_t*)output_image[i], sizeof(uint8_t), (size_t)(crop_width), fp);
	fclose(fp);


	// horizontally flipped image 
	for (i = 0; i < IMAGE_HEIGHT; i++)
		for (j = 0; j < IMAGE_WIDTH; j++)
			output_image[i][j] = input_image[i][IMAGE_WIDTH - j]; // 원본 이미지의 col index를 수정
	fopen_s(&fp, RESULT_NAME2, "wb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME2 << ")" << endl;
		return -1;
	}
	fwrite((uint8_t*)output_image[0], sizeof(uint8_t), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);
	fclose(fp);


	// vertically flipped image
	for (i = 0; i < IMAGE_HEIGHT; i++)
		for (j = 0; j < IMAGE_WIDTH; j++)
			output_image[i][j] = input_image[IMAGE_HEIGHT - i - 1][j]; // 원본 이미지의 row index를 수정
	fopen_s(&fp, RESULT_NAME3, "wb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME3 << ")" << endl;
		return -1;
	}
	fwrite((uint8_t*)output_image[0], sizeof(uint8_t), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);
	fclose(fp);

	memory_free2D(output_image);
	memory_free2D(input_image);

	return 0;
}


uint8_t** memory_alloc2D(size_t height, size_t width)
{
	uint8_t** memory = new uint8_t * [height];
	if (memory == 0)
		return 0;

	memory[0] = new uint8_t[height * width];
	if (memory[0] == 0)
	{
		delete[] memory;
		return 0;
	}

	for (size_t i = 1; i < height; i++)
		memory[i] = memory[i - 1] + width;

	return memory;
}

int memory_free2D(uint8_t** memory)
{
	if (memory == 0)
		return -1;
	if (memory[0])
		delete[] memory[0];

	delete[] memory;
	return 0;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}