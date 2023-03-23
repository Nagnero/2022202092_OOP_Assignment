#include <iostream>
#include <fstream>

using namespace std;


uint8_t** memory_alloc2D(size_t height, size_t width);
int memory_free2D(uint8_t** memory);


int main()
{
	const char* IMAGE_NAME = "Barbara_512x512_yuv400_8bit.raw";
	const char* RESULT_NAME = "result_Barbara_512x512_yuv400_8bit.raw";
	const int IMAGE_HEIGHT = 512, IMAGE_WIDTH = 512;

	FILE* fp = 0; // file pointer
	uint8_t** input_image = 0;
	uint8_t** output_image = 0;

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

	// Copy 
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			output_image[i][j] = input_image[i][j];
		}
	}

	fopen_s(&fp, RESULT_NAME, "wb");
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME << ")" << endl;
		return -1;
	}

	fwrite((uint8_t*)input_image[0], sizeof(uint8_t), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);

	memory_free2D(output_image);
	memory_free2D(input_image);

	fclose(fp);

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