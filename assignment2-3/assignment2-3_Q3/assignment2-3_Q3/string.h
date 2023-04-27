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
			// �Է¹��� ���ڿ��� ���� ����
			int cnt = 0;
			while (s[cnt])
				cnt++;
			this->len = cnt;

			// ���ڿ� ���̸�ŭ �����Ҵ�
			this->s = new char[len + 1];

			for (int i = 0; i < this->len; i++)
				this->s[i] = s[i];

			this->s[len] = '\0'; // �������� NULL���� �߰�
		}
		string(const string& str) {
			// ���޹��� ���� ���� ����
			int cnt = 0;
			while (str.s[cnt]) // ���ڿ��� �����Ͱ� ������ cnt ����
				cnt++;
			this->len = cnt; // �ش� ����ŭ ���� ����

			this->s = new char[len + 1]; // �ش� �����͸� ������ ���ڿ� �����Ҵ�

			for (size_t i = 0; i < len; i++) { // �� ����
				this->s[i] = str.s[i];
			}
			this->s[len] = '\0'; // �������� �� ����
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