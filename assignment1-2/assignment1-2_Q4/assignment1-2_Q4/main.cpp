#include <iostream>
#include <fstream>

using namespace std;


uint8_t** memory_alloc2D(size_t height, size_t width);
int memory_free2D(uint8_t** memory);
void swap(int& x, int& y);


int main()
{
	const char* IMAGE_NAME = "Barbara_512x512_yuv400_8bit.raw";
	const char* RESULT_NAME = "result_Barbara_512x512_yuv400_8bit.raw";
	const char* RESULT_NAME2 = "Barbara_horizontalflip.raw";
	const char* RESULT_NAME3 = "Barbara_verticalflip.raw";
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


	if (x1 > x2)
		swap(x1, x2);

	crop_width = x1 - x2;
	crop_height = y1 - y2;

	for (i = 0; i < x2 - x1; i++)
		for (j = 0; j < y2 - y1; j++)
			output_image[i][j] = input_image[x1 + i][y1 + j];
	char RESULT_NAME1[100] = "Barbara_Cropped_.raw";
	fopen_s(&fp, RESULT_NAME1, "wb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME1 << ")" << endl;
		return -1;
	}
	fwrite((uint8_t*)output_image[0], sizeof(uint8_t), (size_t)(crop_width * crop_height), fp);
	fclose(fp);



	// horizontally flipped image 
	for (i = 0; i < IMAGE_HEIGHT; i++)
		for (j = 0; j < IMAGE_WIDTH; j++)
			output_image[i][j] = input_image[i][IMAGE_WIDTH - j];
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
			output_image[i][j] = input_image[IMAGE_HEIGHT - i - 1][j];
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