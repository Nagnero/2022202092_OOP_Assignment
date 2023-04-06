#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;
	fin.open("binary.txt");
	ofstream fout;
	fout.open("alphabet.txt");

	char c, result[100]{};
	int cnt = 0, index = 0;

	// binary 데이터 파일 없는 경우 예외처리
	if (!fin) {
		cout << "No existing file" << endl;
		return 0;
	}

	while (fin.get(c)) {
		if (c == '\n') {
			cnt = 0;
			continue;
		}
		else if (c == '0') {
			cnt++;
			if (cnt == 25) {
				result[index++] = cnt + 'a';
				cnt = 0;
			}
		}
		else {
			result[index++] = cnt + 'a';
			cnt = 0;
		}
	}

	result[index + 1] = (char)"\0";

	fout.write((char*)result, index);

	fin.close();
	fout.close();
	return 0;
}