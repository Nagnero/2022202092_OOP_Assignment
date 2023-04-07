#include <iostream>
#include <fstream>

using namespace std;

int main() {
	// 파일 입력 스트림 binary.txt에 연결
	ifstream fin;
	fin.open("binary.txt");
	// 파일 출력 스트림 alphabet.txt에 연결
	ofstream fout;
	fout.open("alphabet.txt");

	char c, result[100]{};
	// cnt는 0의 개수를 세는 변수
	int cnt = 0, index = 0;

	// binary 데이터 파일 없는 경우 예외처리
	if (!fin) {
		cout << "No existing file" << endl;
		return 0;
	}

	// 입력 스트림에 저장된 글자 하나씩 가져와서 판단
	while (fin.get(c)) {
		// 개행문자를 만나면 0의 개수 초기화 후 반복문 continue
		if (c == '\n') {
			cnt = 0;
			continue;
		}
		// 0을 입력받으면 cnt 증가
		else if (c == '0') {
			cnt++;
			// cnt가 25이면 z저장 후 cnt 0 으로 초기화
			if (cnt == 25) {
				result[index++] = cnt + 'a';
				cnt = 0;
			}
		}
		// 1을 입력 받으면 아스키 코드로 알파벳 저장. 이후 cnt 0으로 초기화
		else {
			result[index++] = cnt + 'a';
			cnt = 0;
		}
	}

	// 저장된 문자열 마지막에 NULL문자 넣어서 문자열 완성
	result[index + 1] = (char)"\0";
	// 완성된 문자열을 파일 출력 스트림에 저장
	fout.write((char*)result, index);

	// 열어둔 파일 입출력 스트림 닫기
	fin.close();
	fout.close();

	return 0;
}