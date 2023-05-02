#include <iostream>

using namespace std;

class Node {
private:
	Node* m_pNext;
	int m_Data;

public:
	Node() {
		this->m_pNext = NULL;
		this->m_Data = 0;
	}
	~Node() {}

	void SetData(int n) { this->m_Data = n; }
	void SetNext(Node* pNext) { this->m_pNext = pNext; }
	int GetData() { return this->m_Data; }
	Node* GetNext() { return this->m_pNext; }
};

class Queue {
private:
	Node* m_pHead;
	Node* m_pTail;
	int m_Size;
	int m_NumElemnet;

public:
	Queue() {
		this->m_pHead = NULL;
		this->m_pTail = NULL;
		this->m_Size = 0;
		this->m_NumElemnet = 0;
	}
	~Queue() {
		delete m_pHead;
		delete m_pTail;
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

int main() {
	Queue* queue = new Queue;
	string command;
	int input = 0, size;

	cin >> size;
	queue->SetSize(size);

	while (1) {
		cin >> command;

		if (command == "push") {
			cin >> input;

			if (!queue->IsFull()) { // �� �� ���� ������
				Node* newNode = new Node;

				newNode->SetData(input);
				if (queue->Push(newNode))
					cout << "Push successful" << endl;
			}
			else { // �� ��������
				cout << "Already full" << endl;
			}			
		}
		else if (command == "pop") {
			
			if (!queue->IsEmpty()) { // ������� ������
				Node* delNode = queue->Pop();
				cout << "pop " << delNode->GetData() << endl; // ���

				delete delNode;
			}
			else { // ���������
				cout << "Already Empty" << endl;
			}
		}
		else if (command == "print") {

		}
	}

	return 0;
}