#include <iostream>
#include <string>

#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

using namespace std;


// string.cpp 시작부
namespace oopstd {

	class string {
	private:
		char* s;
		size_t len;

	public:
		string() {
			this->s = nullptr;
			this->len = 0;
		}
		string(const char* s) {
			int cnt = 0;

			this->s = (char*)s;
			while (s[cnt]) {
				cnt++;
			}
			this->len = cnt;
		}
		string(const string& str) {
			this->s = str.s;
			this->len = str.len;
		}
		~string() {
			delete[] s;
		}
		

		string& assign(const string& str);
		char& at(size_t pos);
		const char* c_str() const;
		void clear();
		void push_back(char c);
		/*int compare(const string* str) const;
		string& replace(size_t pose, size_t len, const string* str);
		string substr(size_t pos, size_t len) const;
		size_t find(const string& str, size_t pos) const;*/
	};

	// 문자열 저장 멤버함수
	string& string::assign(const string& str) {

		if (str.s != nullptr) { // 전달받은 값이 존재하면
			this->len = strlen(str.s); // 해당 값만큼 길이 저장
			this->s = new char[this->len + 1]; // 문자열 길이만큼 동적할당
			for (size_t i = 0; i < len; i++) { // 값 저장
				s[i] = str.s[i];
			}
			s[len] = '\0'; // 마지막에 널 삽입
		}

		return *this;
	}

	// 문자열에서 지정된 위치 반환 멤버함수
	char& string::at(size_t pos) {
		if (pos >= len) { // 저장된 문자열의 길이가 입력받은 위치보다 작으면
			cout << "out of range" << endl; // 오류 출력
			return this->s[this->len];
		}

		return this->s[pos];
	}

	// 저장된 문자열의 주소 반환 멤버함수
	const char* string::c_str() const {
		return this->s;
	}


	// 문자열 초기화 함수
	void string::clear() {
		this->s[0] = '\0';
		len = 0;
	}

	// 푸시백멤버함수
	void string::push_back(char c) {
		char* new_s = new char[len + 2];
		if (s != nullptr) {
			for (size_t i = 0; i < len; i++)
				new_s[i] = s[i];
		}
		s = new_s;
		new_s[len++] = c;
		new_s[len] = '\0';
	}


	int stoi(const string& str, size_t* idx, int base);
	float stof(const string& str, size_t* idx);

	string to_string(int val);
	string to_string(float val);

}

// string.cpp 종결부

int main() {
	
	// string & c_str method test
	string a1;
	a1.assign("HI");
	cout << a1 << endl;
	// custom method test
	oopstd::string a2;
	a2.assign("HI");
	cout << a2.c_str() << endl << endl;

	// at method test
	string example1 = "Hello World";
	cout << example1.at(2) << endl;
	// custom method test
	oopstd::string example2 = "Hello World";
	cout << example2.at(2) << endl << endl;

	// push_back method test
	example1.push_back('b');
	cout << example1 << endl;
	// custom method test
	example2.push_back('b');
	cout << example2.c_str() << endl;

	// clear method test
	example1.clear();
	cout << example1 << endl;
	// custom method test
	example2.clear();
	cout << example2.c_str() << endl << endl;


	_CrtDumpMemoryLeaks();
	return 0;
}