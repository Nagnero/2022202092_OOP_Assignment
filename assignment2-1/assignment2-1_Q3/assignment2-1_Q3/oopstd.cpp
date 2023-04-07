#include "oopstd.h"

namespace oopstd {

	// memset ����� ���� �Լ�
	void* memset(void* ptr, int value, size_t num) {
		// ������ ������ ���� �ӽ÷� ���� �� ���� ���� �ּҰ� ����
		char* temp = (char*)ptr; 

		// �ӽ� ���� ������ ���� ���� value ���������� ��ȯ �� ����
		// num��ŭ �ݺ�
		for (int i = 0; i < num; i++) {
			*temp = (char)value;
			temp = temp + 1;
		}

		// ���� ������ ��ȯ
		return ptr;
	}

	// memcpy ����� ���� �Լ�
	void* memcpy(void* destination, const void* source, size_t num) {
		// ������ ������ ���� �ӽ÷� ���� �� ������ �ּҿ� �����͸� ������ �ּ� ���� ����
		char* temp = (char*)source;
		char* temp_dest = (char*)destination;

		// �����͸� ������ �ּҿ� �����Ͽ� ������ �ּҿ� ������ ����
		for (int i = 0; i < num; i++)
			temp_dest[i] = temp[i];

		// destination ��ȯ
		return destination;
	}

	// strcmp ����� ���� �Լ� 
	int strcmp(const char* str1, const char* str2) {
		int i = 0;

		// �� ���ڿ� �� �ϳ��� ����� ���� ������ ����
		while (str1[i] != NULL || str2[i] != NULL) {
			// ���� ��ġ�� ���� ���ڰ� ����Ǿ� ������ i 1 ����
			if (str1[i] == str2[i]) {
				i++;
			}
			// ���� ��ġ�� ����� ���ڰ� str1�� �� ũ�� 1 ��ȯ
			else if (str1[i] > str2[i]) {
				return 1;
			}
			// ���� ��ġ�� ����� ���ڰ� str2�� �� ũ�� -1 ��ȯ
			else {
				return -1;
			}
		}

		return 0;
	}

	// strncmp ����� ���� �Լ�
	int strncmp(const char* str1, const char* str2, size_t num) {

		// �Է¹��� num ��ŭ �ݺ��� �ݺ�
		for (int i = 0; i < num; i++) {
			// ���� ��ġ�� ���� ���ڰ� ����Ǿ� ������ i 1 ����
			if (str1[i] == str2[i]) {
				continue;
			}
			// ���� ��ġ�� ����� ���ڰ� str1�� �� ũ�� 1 ��ȯ
			else if (str1[i] > str2[i]) {
				return 1;
			}
			// ���� ��ġ�� ����� ���ڰ� str2�� �� ũ�� -1 ��ȯ
			else {
				return -1;
			}
		}

		return 0;
	}

	// strcpy ����� ���� �Լ�
	char* strcpy(char* destination, const char* source) {
		int i = 0;

		// ������ �ּҿ� ���� �ּҿ� ����� ������ ����
		while (source[i]) {
			destination[i] = source[i];
			i++;
		}
		// �������� NULL���� ����
		destination[i] = '\0';

		// �����͸� ������ �ּ� ��ȯ
		return destination;
	}

	// strncpy ����� ���� �Լ�
	char* strncpy(char* destination, const char* source, size_t num) {
		int i = 0;

		// num��ŭ�̰ų� ������ �����Ͱ� �ִ� ���ȹݺ�
		for (; i < num && source[i] != NULL; i++) {
			destination[i] = source[i]; // ������ ����
		}

		// ������ �����Ͱ� NULL�̸� ������ �����Ϳ��� NULL���� ����
		if (source[i] == NULL) {
			destination[i] = NULL;
		}

		// �����͸� ������ �ּ� ��ȯ
		return destination;
	}

	// strlen ����� ���� �Լ�
	size_t strlen(const char* str) {
		size_t result = 0;

		// ���ڿ��� �����Ͱ� ������ result ����
		while (str[result])
			result++;

		// result ��ȯ
		return result;
	}

	// atoi ����� ���� �Լ�
	int atoi(const char* str) {
		int len = 0, result = 0, sign = 1;

		// ���ڿ��� ���� ī��Ʈ
		while (!(str[len] == '\n'))
			len++;

		// ���ڿ��� ���̸�ŭ �ݺ��ϸ�
		for (int i = 0; i < len; i++) {
			// �ι�° �ڸ����� ���ڷ� �Է�
			if (i > 0) {
				result += (str[i] - '0') * pow(10, len - i - 1);
			}
			// ù��° �ڸ�����
			else {
				// ù��° ���ڰ� -�̸� sign�� -1��
				if (str[i] == '-')
					sign = -1;
				// ù���� ���ڰ� +�̸� �״�� ����
				else if (str[i] == '+')
					continue;
				// �׳� ���ڸ� ���������� ��ȯ
				else
					result += (str[i] - '0') * pow(10, len - i - 1);
			}
		}

		// sign�� ���ؼ� ��ȯ
		return sign * result;
	}

	// atof ����� ���� �Լ�
	float atof(const char* str) {
		float result = 0;
		int len = 0, len_num = 0, i = 0, period = 0, sign = 1;
		bool under = false;
		
		// ��ü ���ڿ��� ���� len
		while (!(str[len] == '\n')) {
			len++;
			// ���ڰ� -�� .�� �ƴϸ�
			if (str[len] != '-' && str[len] != '.')
				len_num++;
		}

		// ù��° ��ȣ�� -�̸� sign -1, �ݺ��� 1���� ����.
		// �ݺ��� ���� �������� ���ǹ��� ���ֱ� ���� ������ ����
		if (str[0] == '-') {
			sign = -1;
			i = 1;
		}

		for (; i < len; i++) {
			// �Ҽ����� ������ �Ҽ��� �Ʒ��� �Ǵ�
			if (str[i] == '.') {
				under = true;
				period++;
				continue;
			}

			// �Ҽ��� �Ʒ� ���° �ڸ����� �Ǵ��ϰ� �� ����
			if (under) {
				period++;
				result += (str[i] - '0') * pow(10, len_num - i);
			}
			else 
				result += (str[i] - '0') * pow(10, len_num - i - 1);

		}

		// �Ҽ��� �Ʒ� ���° �ڸ����� ���ؼ� �Ҽ��� ���
		result *= pow(0.1, period - 1);

		// ��ȣ�� ���� sign�� ���ؼ� ��ȯ
		return sign * result;
	}
}