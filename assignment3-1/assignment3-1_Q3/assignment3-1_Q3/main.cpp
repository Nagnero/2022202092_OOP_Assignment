#include <iostream>


#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif


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
		Node* curNode = m_pHead;
		Node* delNode = NULL;

		while (curNode) {
			delNode = curNode;
			curNode = curNode->GetNext();
			if (delNode == m_pTail) {
				this->m_pHead = NULL;
				this->m_pTail = NULL;
			}
			delete delNode;
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

void Queue::PrintQueue() {
	Node* curNode = m_pHead;

	while (curNode) {
		cout << curNode->GetData() << " ";
		curNode = curNode->GetNext();
	}
}

int main() {
	Queue* queue = new Queue;
	char command[20]{};
	int input = 0, size;

	cin >> size;
	queue->SetSize(size);

	while (1) {
		cin >> command;

		if (strcmp(command, "push") == 0) {
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
		else if (strcmp(command, "print") == 0) {
			queue->PrintQueue();
			cout << endl;
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else
			cout << "Enter valid command" << endl;
	}

	delete queue;
	_CrtDumpMemoryLeaks();
	return 0;
}