#include <iostream>


using namespace std;

class Node {
private:
	Node* m_pNext; // 다음 노드의 주소를 저장할 포인터
	int m_Data; // 현재 노드에 저장될 데이터

public:
	Node() { // 생성자
		this->m_pNext = NULL;
		this->m_Data = 0;
	}
	~Node() {} // 소멸자

	void SetData(int n) { this->m_Data = n; }
	void SetNext(Node* pNext) { this->m_pNext = pNext; }
	int GetData() { return this->m_Data; }
	Node* GetNext() { return this->m_pNext; }
};

class Queue {
private:
	Node* m_pHead; // 큐의 head 노드를 가리킬 포인터
	Node* m_pTail; // 큐의 tail 노드를 가리킬 포인터
	int m_Size; // 큐의 크기를 저장할 변수
	int m_NumElemnet; // 현재 저장된 노드의 개수를 저장할 변수

public:
	Queue() { // 생성자
		this->m_pHead = NULL;
		this->m_pTail = NULL;
		this->m_Size = 0;
		this->m_NumElemnet = 0;
	}

	~Queue() { // 소멸자
		Node* curNode = m_pHead; // 현재 노드를 가리킬 포인터
		Node* delNode = NULL; // 삭제할 노드를 가리킬 포인터

		while (curNode) { // 모든 노드를 삭제하는 반복문
			delNode = curNode;
			curNode = curNode->GetNext();
			if (delNode == m_pTail) { // tail 노드일 경우
				this->m_pHead = NULL;
				this->m_pTail = NULL;
			}
			delete delNode; // 노드 삭제
		}
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

// 큐에 저장된 모든 데이터를 출력하는 멤버함수
void Queue::PrintQueue() {
	Node* curNode = m_pHead; // 현재 노드를 가리키는 포인터

	while (curNode) { // 모든 노드에 대해 반복
		cout << curNode->GetData() << " "; // 노드에 저장된 데이터 출력
		curNode = curNode->GetNext(); // 다음 노드로 이동
	}
}

int main() {
	Queue* queue = new Queue;
	char command[20]{};
	int input = 0, size;

	cin >> size; // 큐의 크기를 입력 받음
	queue->SetSize(size); // 큐의 크기를 설정

	while (1) { // 사용자로부터 명령어를 입력받아 처리하는 반복문
		cin >> command;

		if (strcmp(command, "push") == 0) { // push 명령어 처리
			cin >> input;

			if (!queue->IsFull()) { // 큐가 꽉 차 있지 않으면
				Node* newNode = new Node; // 새로운 노드를 생성

				newNode->SetData(input); // 입력 받은 데이터를 노드에 저장
				if (queue->Push(newNode))
					cout << "Push successful" << endl;
			}
			else { // 꽉 차있으면
				cout << "Already full" << endl;
			}
		}
		else if (strcmp(command, "pop") == 0) {

			if (!queue->IsEmpty()) { // 비어있지 않으면
				Node* delNode = queue->Pop();
				cout << "pop " << delNode->GetData() << endl; // 출력

				delete delNode;
			}
			else { // 비어있으면
				cout << "Already Empty" << endl;
			}
		}
		else if (strcmp(command, "print") == 0) { // print 명령어 처리
			queue->PrintQueue(); // 큐에 저장된 모든 데이터를 출력
			cout << endl; // 개행 문자 출력
		}
		else if (strcmp(command, "exit") == 0) // exit 명령어 처리
			break;
		else // 잘못된 명령어를 입력했을 경우 실패 메시지 출력
			cout << "Enter valid command" << endl; 
	}

	delete queue;
	
	return 0;
}