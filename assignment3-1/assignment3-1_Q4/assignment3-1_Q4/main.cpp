#include <iostream>

using namespace std;

class Node {
private:
    Node* m_pNext; // ���� ����� �ּҸ� �����ϴ� ������
    int m_Data; // ��忡 ������ ������

public:
    Node() {
        this->m_pNext = NULL; // ������ �ʱ�ȭ
        this->m_Data = 0; // ������ �ʱ�ȭ
    }
    ~Node() {}

    void SetData(int n) { this->m_Data = n; } // ������ ����
    void SetNext(Node* pNext) { this->m_pNext = pNext; } // ���� ��� �ּ� ����
    int GetData() { return this->m_Data; } // ������ ��ȯ
    Node* GetNext() { return this->m_pNext; } // ���� ��� �ּ� ��ȯ
};

class Stack {
private:
    Node* m_pTop; // �� ���� ��� �ּҸ� �����ϴ� ������
    int m_Size; // ������ ũ��
    int m_NumElement; // ���ÿ� ����� ���� ����

public:
    Stack() {
        this->m_pTop = NULL; // ������ �ʱ�ȭ
        this->m_Size = 0; // ũ�� �ʱ�ȭ
        this->m_NumElement = 0; // ���� ���� �ʱ�ȭ
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

    void SetSize(int n) { this->m_Size = n; } // ������ ũ�� ����
    bool IsEmpty() { return m_pTop ? false : true; } // ������ ����ִ��� Ȯ���ϴ� �Լ�
    bool IsFull() { return m_Size == m_NumElement ? true : false; } // ������ �� �� �ִ��� Ȯ���ϴ� �Լ�
    bool Push(Node* pNode); // ���ÿ� ���Ҹ� �߰��ϴ� �Լ�
    Node* Pop(); // ���ÿ��� ���Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
    void PrintStack(); // ���ÿ� ����� ���Ҹ� ����ϴ� �Լ�
};

// Ǫ�� ����Լ�
bool Stack::Push(Node* pNode) {
    if (!IsFull()) { // ������ �� �� ���� ������
        pNode->SetNext(m_pTop); // �� ����� ���� ��带 ���� �� ���� ���� ����
        m_pTop = pNode; // �� ��带 �� ���� ���� ����
        m_NumElement++; // ���� ���� ����

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
        m_NumElement--; // ���� ���� ����

        return delNode;
    }
    else { // ������ ���������
        cout << "Already Empty" << endl;
        return NULL;
    }
}

// ��� ����Լ�
void Stack::PrintStack() {
    Node* curNode = m_pTop; // ���� ��带 ����Ű�� ������


    while (curNode) {
        cout << curNode->GetData() << " "; // ���� ����� ������ ���
        curNode = curNode->GetNext(); // ���� ���� �̵�
    }
}

int main() {
    Stack* stack = new Stack; // Stack ��ü ����
    char command[20]; // ����� �Է��� ���� ���ڿ�
    int input = 0, size; // ����� �Է��� ���� ������ ������ ũ��

    cin >> size; // ������ ũ�� �Է�
    stack->SetSize(size); // ������ ũ�� ����

    while (1) { // ����ڰ� exit ����� �Է��� ������ ���� �ݺ�
        cin >> command; // ��ɾ� �Է�

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
        else if (strcmp(command, "exit") == 0) { // exit ����� �Է��� ���
            break; // �ݺ��� Ż��
        }
        else { // �߸��� ����� �Է��� ���
            cout << "Enter valid command" << endl;
        }
    }

    delete stack; // ���� �Ҵ��� �޸� ����

    return 0; // ���α׷� ����
}