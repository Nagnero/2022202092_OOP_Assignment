#include <iostream>

using namespace std;

// my_strtok �Լ� ����
char* my_strtok(char* str);

int main() {
	char str[200]{}; // �Է¹��� ���ڿ�
	int num = 0; // '@' ��ȣ�� ����


	cin >> str; // ���ڿ� �Է¹ޱ�

	// @�� ������ Ȯ���ϴ� �ݺ���
	for (int i = 0; str[i]; i++)
		if (str[i] == '@')
			num++;

	// @�� 1���� �ƴ� ��� ����ó��
	if (num != 1) {
		cout << "Unvalid e-mail address" << endl;
		return 0;
	}

	// token �ʱ� ���� �� �Ҵ�
	char* token = my_strtok(str);

	// �ݺ����� ���� ���
	while (*token != '\0') {
		cout << token << endl;
		token = my_strtok(NULL); // �ѹ� ���� ������ ���Ŀ� nullptr ����
	}

	return 0;
}

char* my_strtok(char* str) {
	static char* static_str = NULL;

	if (!str) // ���޹��� �Ű������� NULL�̸�
		static_str++; // static_str ���� 1 ����
	else // ���޹��� �Ű������� �ʱ� �Է°��̸� �ش� �� ����
		static_str = str;

	char* return_tok = static_str; // return�� token �� �ʱ�ȭ

	// �Է°����� @�̳� .�� ã�� ������ ���ڸ� �ϳ��� ����
	while (*static_str != '@' && *static_str != '.' && *static_str != '\0')
		static_str++;

	// �Է°��� �������̸�
	if (*static_str == '\0')
		return return_tok;
	else { // �������� �ƴϸ�
		*static_str = '\0';
		return return_tok;
	}
}