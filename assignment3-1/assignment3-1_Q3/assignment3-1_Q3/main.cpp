#include <iostream>


using namespace std;

class Node {
private:
	Node* m_pNext; // ���� ����� �ּҸ� ������ ������
	int m_Data; // ���� ��忡 ����� ������

public:
	Node() { // ������
		this->m_pNext = NULL;
		this->m_Data = 0;
	}
	~Node() {} // �Ҹ���

	void SetData(int n) { this->m_Data = n; }
	void SetNext(Node* pNext) { this->m_pNext = pNext; }
	int GetData() { return this->m_Data; }
	Node* GetNext() { return this->m_pNext; }
};

class Queue {
private:
	Node* m_pHead; // ť�� head ��带 ����ų ������
	Node* m_pTail; // ť�� tail ��带 ����ų ������
	int m_Size; // ť�� ũ�⸦ ������ ����
	int m_NumElemnet; // ���� ����� ����� ������ ������ ����

public:
	Queue() { // ������
		this->m_pHead = NULL;
		this->m_pTail = NULL;
		this->m_Size = 0;
		this->m_NumElemnet = 0;
	}

	~Queue() { // �Ҹ���
		Node* curNode = m_pHead; // ���� ��带 ����ų ������
		Node* delNode = NULL; // ������ ��带 ����ų ������

		while (curNode) { // ��� ��带 �����ϴ� �ݺ���
			delNode = curNode;
			curNode = curNode->GetNext();
			if (delNode == m_pTail) { // tail ����� ���
				this->m_pHead = NULL;
				this->m_pTail = NULL;
			}
			delete delNode; // ��� ����
		}
	}

	void SetSize(int n) { this->m_Size = n; }
	bool IsEmpty() { return m_pHead ? false : true; }
	bool IsFull() { return m_Size == m_NumElemnet ? true : false; }
	bool Push(Node* pNode);
	Node* Pop();
	void PrintQueue();
};

// ��� �߰� ����Լ�
bool Queue::Push(Node* pNode) {
	if (IsEmpty()) { // ť�� ��� ������
		m_pHead = pNode;
		m_pTail = pNode;
		m_NumElemnet++;

		return true;
	}
	else { // ť�� ������� ������
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
		m_NumElemnet++;

		return true;
	}
}

// ������ ��� ��ȯ ����Լ�
Node* Queue::Pop() {
	if (m_NumElemnet != 1) { // ����� ��尡 1�� �̻��� ���
		Node* tempNode = m_pHead; // ��ȯ�� ��� �ּ� ����
		m_pHead = m_pHead->GetNext(); // head��� �������� �̵�
		m_NumElemnet--;

		return tempNode;
	}
	else { // ����� ��尡 1���� ���
		Node* tempNode = m_pHead; // ��ȯ�� ��� �ּ� ����
		m_pHead = NULL;
		m_pTail = NULL;
		m_NumElemnet--;

		return tempNode;
	}
}

// ť�� ����� ��� �����͸� ����ϴ� ����Լ�
void Queue::PrintQueue() {
	Node* curNode = m_pHead; // ���� ��带 ����Ű�� ������

	while (curNode) { // ��� ��忡 ���� �ݺ�
		cout << curNode->GetData() << " "; // ��忡 ����� ������ ���
		curNode = curNode->GetNext(); // ���� ���� �̵�
	}
}

int main() {
	Queue* queue = new Queue;
	char command[20]{};
	int input = 0, size;

	cin >> size; // ť�� ũ�⸦ �Է� ����
	queue->SetSize(size); // ť�� ũ�⸦ ����

	while (1) { // ����ڷκ��� ��ɾ �Է¹޾� ó���ϴ� �ݺ���
		cin >> command;

		if (strcmp(command, "push") == 0) { // push ��ɾ� ó��
			cin >> input;

			if (!queue->IsFull()) { // ť�� �� �� ���� ������
				Node* newNode = new Node; // ���ο� ��带 ����

				newNode->SetData(input); // �Է� ���� �����͸� ��忡 ����
				if (queue->Push(newNode))
					cout << "Push successful" << endl;
			}
			else { // �� ��������
				cout << "Already full" << endl;
			}
		}
		else if (strcmp(command, "pop") == 0) {

			if (!queue->IsEmpty()) { // ������� ������
				Node* delNode = queue->Pop();
				cout << "pop " << delNode->GetData() << endl; // ���

				delete delNode;
			}
			else { // ���������
				cout << "Already Empty" << endl;
			}
		}
		else if (strcmp(command, "print") == 0) { // print ��ɾ� ó��
			queue->PrintQueue(); // ť�� ����� ��� �����͸� ���
			cout << endl; // ���� ���� ���
		}
		else if (strcmp(command, "exit") == 0) // exit ��ɾ� ó��
			break;
		else // �߸��� ��ɾ �Է����� ��� ���� �޽��� ���
			cout << "Enter valid command" << endl; 
	}

	delete queue;
	
	return 0;
}