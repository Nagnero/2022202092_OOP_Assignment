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

// 노드 추가 멤버함수
bool Queue::Push(Node* pNode) {
	if (IsEmpty()) { // 큐가 비어 있으면
		m_pHead = pNode;
		m_pTail = pNode;
		m_NumElemnet++;

		return true;
	}
	else { // 큐가 비어있지 않으면
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
		m_NumElemnet++;

		return true;
	}
}

// 삭제할 노드 반환 멤버함수
Node* Queue::Pop() {
	if (m_NumElemnet != 1) { // 저장된 노드가 1개 이상인 경우
		Node* tempNode = m_pHead; // 반환할 노드 주소 저장
		m_pHead = m_pHead->GetNext(); // head노드 다음으로 이동
		m_NumElemnet--;
		
		return tempNode;
	}
	else { // 저장된 노드가 1개인 경우
		Node* tempNode = m_pHead; // 반환할 노드 주소 저장
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

			if (!queue->IsFull()) { // 꽉 차 있지 않으면
				Node* newNode = new Node;

				newNode->SetData(input);
				if (queue->Push(newNode))
					cout << "Push successful" << endl;
			}
			else { // 꽉 차있으면
				cout << "Already full" << endl;
			}			
		}
		else if (command == "pop") {
			
			if (!queue->IsEmpty()) { // 비어있지 않으면
				Node* delNode = queue->Pop();
				cout << "pop " << delNode->GetData() << endl; // 출력

				delete delNode;
			}
			else { // 비어있으면
				cout << "Already Empty" << endl;
			}
		}
		else if (command == "print") {

		}
	}

	return 0;
}