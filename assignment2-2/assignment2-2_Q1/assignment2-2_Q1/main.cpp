#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	string data = "";
	struct Node* next = nullptr;
	struct Node* d_next = nullptr;
	struct Node* prev = nullptr;
} Node;



int main() {
	string input, temp;

	cin >> input;

	// ù��°�� �׻� [�� ���۵ǹǷ� ���ǹ� �����ϰ� ���� ��� ����
	Node* head = new Node;
	Node* curNode = head;

	// �Է¹��� ���ڿ��� ����Ʈ�� �����ϴ� �ݺ���
	for (int i = 1; i < input.length(); i++) {
		// ���ο� ����Ʈ ����
		if (input[i] == '[') {
			Node* newNode = new Node;
			
		}
		// �޸��� ������ temp�� �迭�� ����
		else if (input[i] == ',') {
			i++; // comma�ڿ� �׻� ������ ���� ����
			Node* newNode = new Node;

			if (temp == "") { // �� ���ڿ��̸� �״�� ����Ʈ �߰�

			}
		}
		// ����Ʈ ������
		else if (input[i] == ']') {

		}
		// ���ڿ��� ��Ҹ�
		else {
			// ������ ���ڿ��� �� ���̸�
			
			temp.push_back(input[i]);
		}
	}


	delete head;
}