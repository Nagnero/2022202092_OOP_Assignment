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

class Stack {
private:
    Node* m_pTop;
    int m_Size;
    int m_NumElement;

public:
    Stack() {
        this->m_pTop = NULL;
        this->m_Size = 0;
        this->m_NumElement = 0;
    }

    ~Stack() {
        Node* curNode = m_pTop;
        Node* delNode = NULL;

        while (curNode) {
            delNode = curNode;
            curNode = curNode->GetNext();
            delete delNode;
        }

        m_pTop = NULL;
    }

    void SetSize(int n) { this->m_Size = n; }
    bool IsEmpty() { return m_pTop ? false : true; }
    bool IsFull() { return m_Size == m_NumElement ? true : false; }
    bool Push(Node* pNode);
    Node* Pop();
    void PrintStack();
};

// 푸시 멤버함수
bool Stack::Push(Node* pNode) {
    if (!IsFull()) { // 꽉 차 있지 않으면
        pNode->SetNext(m_pTop);
        m_pTop = pNode;
        m_NumElement++;

        return true;
    }
    else { // 꽉 차있으면
        cout << "Already full" << endl;
        return false;
    }
}

// 팝 멤버함수
Node* Stack::Pop() {
    if (!IsEmpty()) { // 비어있지 않으면
        Node* delNode = m_pTop;
        m_pTop = m_pTop->GetNext();
        m_NumElement--;

        return delNode;
    }
    else { // 비어있으면
        cout << "Already Empty" << endl;
        return NULL;
    }
}

// 출력 멤버함수
void Stack::PrintStack() {
    Node* curNode = m_pTop;

    while (curNode) {
        cout << curNode->GetData() << " ";
        curNode = curNode->GetNext();
    }
}

int main() {
    Stack* stack = new Stack;
    char command[20];
    int input = 0, size;

	cin >> size;
	stack->SetSize(size);

	while (1) {
		cin >> command;

		if (strcmp(command, "push") == 0) {
			cin >> input;

			if (!stack->IsFull()) { // 꽉 차 있지 않으면
				Node* newNode = new Node;

				newNode->SetData(input);
				if (stack->Push(newNode))
					cout << "Push successful" << endl;
			}
			else { // 꽉 차있으면
				cout << "Already full" << endl;
			}
		}
		else if (strcmp(command, "pop") == 0) {

			if (!stack->IsEmpty()) { // 비어있지 않으면
				Node* delNode = stack->Pop();
				cout << "pop " << delNode->GetData() << endl; // 출력

				delete delNode;
			}
			else { // 비어있으면
				cout << "Already Empty" << endl;
			}
		}
		else if (strcmp(command, "print") == 0) {
			stack->PrintStack();
			cout << endl;
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else
			cout << "Enter valid command" << endl;
	}

	delete stack;
	_CrtDumpMemoryLeaks();
	return 0;
}