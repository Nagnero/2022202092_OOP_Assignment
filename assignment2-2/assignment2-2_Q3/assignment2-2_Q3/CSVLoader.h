#include <fstream>
#include <string>

class CSVLoader {
public:
	static constexpr unsigned int MAX_BUFFER_SIZE = 128;

	CSVLoader();
	CSVLoader(const char* path);
	~CSVLoader();

	float** getData() const; // 값이 저장된 2중 포인터 반환
	int getRows() const; // row 반환
	int getCols() const; // col 반환

	void parse(const char* path); // 파싱 멤버함수 선언
	void print(void); // 출력 멤버함수선언

private:
	float** data;
	int cols;
	int rows;
};
