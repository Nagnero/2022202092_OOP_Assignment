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

// Ǫ�� ����Լ�
bool Stack::Push(Node* pNode) {
    if (!IsFull()) { // �� �� ���� ������
        pNode->SetNext(m_pTop);
        m_pTop = pNode;
        m_NumElement++;

        return true;
    }
    else { // �� ��������
        cout << "Already full" << endl;
        return false;
    }
}

// �� ����Լ�
Node* Stack::Pop() {
    if (!IsEmpty()) { // ������� ������
        Node* delNode = m_pTop;
        m_pTop = m_pTop->GetNext();
        m_NumElement--;

        return delNode;
    }
    else { // ���������
        cout << "Already Empty" << endl;
        return NULL;
    }
}

// ��� ����Լ�
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

			if (!stack->IsFull()) { // �� �� ���� ������
				Node* newNode = new Node;

				newNode->SetData(input);
				if (stack->Push(newNode))
					cout << "Push successful" << endl;
			}
			else { // �� ��������
				cout << "Already full" << endl;
			}
		}
		else if (strcmp(command, "pop") == 0) {

			if (!stack->IsEmpty()) { // ������� ������
				Node* delNode = stack->Pop();
				cout << "pop " << delNode->GetData() << endl; // ���

				delete delNode;
			}
			else { // ���������
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