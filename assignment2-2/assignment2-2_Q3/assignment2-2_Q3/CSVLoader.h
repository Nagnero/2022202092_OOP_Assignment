#include <fstream>
#include <string>

class CSVLoader {
public:
	static constexpr unsigned int MAX_BUFFER_SIZE = 128;

	CSVLoader();
	CSVLoader(const char* path);
	~CSVLoader();

	float** getData() const; // 값이 저장된 2중 포인터 반환
	int getRows() const;
	int getCols() const;

	void parse(const char* path);
	void print(void);

private:
	float** data;
	int cols;
	int rows;
};
