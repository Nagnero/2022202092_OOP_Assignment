#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;


uint8_t** memory_alloc2D(size_t height, size_t width);
int memory_free2D(uint8_t** memory);
void swap(int& x, int& y); // ���� ��ġ �ٲ� ����� �����Լ�


int main()
{
	const char* IMAGE_NAME = "Barbara_512x512_yuv400_8bit.raw";
	const char* RESULT_NAME2 = "Barbara_horizontalflip.raw"; // ������� ���ϸ�
	const char* RESULT_NAME3 = "Barbara_verticalflip.raw"; // �������� ���ϸ�
	const int IMAGE_HEIGHT = 512, IMAGE_WIDTH = 512;
	int x1, x2, y1, y2, i, j, crop_width, crop_height;

	FILE* fp = 0; // file pointer
	uint8_t** input_image = 0;
	uint8_t** output_image = 0;

	// ��ǥ �ΰ� �Է¹ޱ�
	cout << "1st coordinate : ";
	cin >> x1;
	cin.ignore(10, ','); // �޸� �Է� ����
	cin >> y1;
	cout << "2nd coordinate : ";
	cin >> x2;
	cin.ignore(10, ','); // �޸� �Է� ����
	cin >> y2;

	// ��ǥ�� �迭�� index�� ����� ���� 1�� ���ֱ�
	x1--, x2--, y1--, y2--;


	// Load input image, �б� ���� ����
	fopen_s(&fp, IMAGE_NAME, "rb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << IMAGE_NAME << ")" << endl;
		return -1;
	}

	// �Է¹��� �̹��� �����ŭ �迭 �����Ҵ�
	input_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH);
	if (input_image == 0)
	{
		cout << "Failed to allocate memory" << endl;
		return -1;
	}

	// �Ҵ�� �迭�� ���Ϸκ��� ���� ������ ����
	fread((uint8_t*)input_image[0], sizeof(uint8_t), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
	fclose(fp);

	//����� �̹��� �����ŭ �迭 �����Ҵ�
	output_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH);
	if (output_image == 0)
	{
		cout << "Failed to allocate memory" << endl;
		return -1;
	}

	// �簢���� ���� ���� ������ �Ʒ� ��ǥ�� �����ϴ� �ڵ�
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

	// �ڸ� �̹����� �ʺ�� ���� ���
	crop_width = x2 - x1;
	crop_height = y2 - y1;

	// �ڸ� ���̸�ŭ output_image�� ������ �迭�� �����Ͽ� ������ ����
	for (i = 0; i < crop_height; i++)
		for (j = 0; j < crop_width; j++)
			output_image[i][j] = input_image[y1 + i][x1 + j];

	// �ڸ� ���̸� ���ϸ� ��Ÿ���� ���� ����
	char RESULT_NAME1[30] = "Barbara_Cropped_";
	// index  ����� ���� ���� ���� ���� �� �ʱ�ȭ
	int len = strlen(RESULT_NAME1), cnt = 1, temp = crop_width, temp1 = crop_width;
	while (temp /= 10)
		cnt++; // �ʺ� �ڸ��� ����
	for (i = 0; i < cnt; i++) { // �ʺ��� ���ڸ����� �迭�� ����
		RESULT_NAME1[len + cnt - i - 1] = temp1 % 10 + 48; // char���� ASKII�ڵ�� ���ڷ� ��ȯ
		temp1 /= 10;
	}
	len = strlen(RESULT_NAME1) + 1;
	strcat(RESULT_NAME1, "x"); // ���ϸ� ���Ļ� 'x' �߰�

	// ���̿� ���� �� ���� �ݺ�
	cnt = 1; temp = crop_height, temp1 = crop_height;
	while (temp /= 10)
		cnt++;
	for (i = 0; i < cnt; i++) {
		RESULT_NAME1[len + cnt - i - 1] = temp1 % 10 + 48;
		temp1 /= 10;
	}
	// �������� '.raw' ���ڿ� �߰��Ͽ� Ȯ���� �߰�
	strcat(RESULT_NAME1, ".raw");


	fopen_s(&fp, RESULT_NAME1, "wb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME1 << ")" << endl;
		return -1;
	}
	// ���پ� �����Ͽ� �ڸ� �ʺ�ŭ ������ �Է�
	for(int i = 0; i < crop_height; i++)
		fwrite((uint8_t*)output_image[i], sizeof(uint8_t), (size_t)(crop_width), fp);
	fclose(fp);


	// horizontally flipped image 
	for (i = 0; i < IMAGE_HEIGHT; i++)
		for (j = 0; j < IMAGE_WIDTH; j++)
			output_image[i][j] = input_image[i][IMAGE_WIDTH - j]; // ���� �̹����� col index�� ����
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
			output_image[i][j] = input_image[IMAGE_HEIGHT - i - 1][j]; // ���� �̹����� row index�� ����
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