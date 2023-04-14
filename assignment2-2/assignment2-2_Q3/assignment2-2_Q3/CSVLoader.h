#include <fstream>
#include <string>

class CSVLoader {
public:
	static constexpr unsigned int MAX_BUFFER_SIZE = 128;

	CSVLoader();
	CSVLoader(const char* path);
	~CSVLoader();

	float** getData() const; // ���� ����� 2�� ������ ��ȯ
	int getRows() const; // row ��ȯ
	int getCols() const; // col ��ȯ

	void parse(const char* path); // �Ľ� ����Լ� ����
	void print(void); // ��� ����Լ�����

private:
	float** data;
	int cols;
	int rows;
};
