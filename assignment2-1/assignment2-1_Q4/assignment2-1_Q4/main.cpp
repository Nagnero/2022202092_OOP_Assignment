#include <iostream>
#include <fstream>

using namespace std;

int main() {
	// ���� �Է� ��Ʈ�� binary.txt�� ����
	ifstream fin;
	fin.open("binary.txt");
	// ���� ��� ��Ʈ�� alphabet.txt�� ����
	ofstream fout;
	fout.open("alphabet.txt");

	char c, result[100]{};
	// cnt�� 0�� ������ ���� ����
	int cnt = 0, index = 0;

	// binary ������ ���� ���� ��� ����ó��
	if (!fin) {
		cout << "No existing file" << endl;
		return 0;
	}

	// �Է� ��Ʈ���� ����� ���� �ϳ��� �����ͼ� �Ǵ�
	while (fin.get(c)) {
		// ���๮�ڸ� ������ 0�� ���� �ʱ�ȭ �� �ݺ��� continue
		if (c == '\n') {
			cnt = 0;
			continue;
		}
		// 0�� �Է¹����� cnt ����
		else if (c == '0') {
			cnt++;
			// cnt�� 25�̸� z���� �� cnt 0 ���� �ʱ�ȭ
			if (cnt == 25) {
				result[index++] = cnt + 'a';
				cnt = 0;
			}
		}
		// 1�� �Է� ������ �ƽ�Ű �ڵ�� ���ĺ� ����. ���� cnt 0���� �ʱ�ȭ
		else {
			result[index++] = cnt + 'a';
			cnt = 0;
		}
	}

	// ����� ���ڿ� �������� NULL���� �־ ���ڿ� �ϼ�
	result[index + 1] = (char)"\0";
	// �ϼ��� ���ڿ��� ���� ��� ��Ʈ���� ����
	fout.write((char*)result, index);

	// ����� ���� ����� ��Ʈ�� �ݱ�
	fin.close();
	fout.close();

	return 0;
}