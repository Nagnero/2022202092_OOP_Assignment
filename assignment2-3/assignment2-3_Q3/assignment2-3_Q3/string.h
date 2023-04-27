#include <iostream>
#include <cmath>

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
			// 입력받은 문자열의 길이 측정
			int cnt = 0;
			while (s[cnt])
				cnt++;
			this->len = cnt;

			// 문자열 길이만큼 동적할당
			this->s = new char[len + 1];

			for (int i = 0; i < this->len; i++)
				this->s[i] = s[i];

			this->s[len] = '\0'; // 마지막에 NULL문자 추가
		}
		string(const string& str) {
			// 전달받은 값의 길이 측정
			int cnt = 0;
			while (str.s[cnt]) // 문자열에 데이터가 있으면 cnt 증가
				cnt++;
			this->len = cnt; // 해당 값만큼 길이 저장

			this->s = new char[len + 1]; // 해당 데이터를 저장할 문자열 동적할당

			for (size_t i = 0; i < len; i++) { // 값 저장
				this->s[i] = str.s[i];
			}
			this->s[len] = '\0'; // 마지막에 널 삽입
		}
		~string() {
			delete[] this->s;
			this->s = NULL;
		}

		size_t npos = -1;
		int getlen() const { return this->len; };

		string& assign(const string& str);
		char& at(size_t pos);
		const char* c_str() const;
		void clear();
		void push_back(char c);
		int compare(const string& str) const;
		string& replace(size_t pose, size_t len, const string& str);
		string substr(size_t pos, size_t len) const;
		size_t find(const string& str, size_t pos) const;
	};
}