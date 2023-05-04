#include <iostream>

using namespace std;

class Node {
private:
    Node* m_pNext; // 다음 노드의 주소를 저장하는 포인터
    int m_Data; // 노드에 저장할 데이터

public:
    Node() {
        this->m_pNext = NULL; // 포인터 초기화
        this->m_Data = 0; // 데이터 초기화
    }
    ~Node() {}

    void SetData(int n) { this->m_Data = n; } // 데이터 설정
    void SetNext(Node* pNext) { this->m_pNext = pNext; } // 다음 노드 주소 설정
    int GetData() { return this->m_Data; } // 데이터 반환
    Node* GetNext() { return this->m_pNext; } // 다음 노드 주소 반환
};

class Stack {
private:
    Node* m_pTop; // 맨 위의 노드 주소를 저장하는 포인터
    int m_Size; // 스택의 크기
    int m_NumElement; // 스택에 저장된 원소 개수

public:
    Stack() {
        this->m_pTop = NULL; // 포인터 초기화
        this->m_Size = 0; // 크기 초기화
        this->m_NumElement = 0; // 원소 개수 초기화
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

    void SetSize(int n) { this->m_Size = n; } // 스택의 크기 설정
    bool IsEmpty() { return m_pTop ? false : true; } // 스택이 비어있는지 확인하는 함수
    bool IsFull() { return m_Size == m_NumElement ? true : false; } // 스택이 꽉 차 있는지 확인하는 함수
    bool Push(Node* pNode); // 스택에 원소를 추가하는 함수
    Node* Pop(); // 스택에서 원소를 삭제하고 반환하는 함수
    void PrintStack(); // 스택에 저장된 원소를 출력하는 함수
};

// 푸시 멤버함수
bool Stack::Push(Node* pNode) {
    if (!IsFull()) { // 스택이 꽉 차 있지 않으면
        pNode->SetNext(m_pTop); // 새 노드의 다음 노드를 현재 맨 위의 노드로 설정
        m_pTop = pNode; // 새 노드를 맨 위의 노드로 설정
        m_NumElement++; // 원소 개수 증가

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
        m_NumElement--; // 원소 개수 감소

        return delNode;
    }
    else { // 스택이 비어있으면
        cout << "Already Empty" << endl;
        return NULL;
    }
}

// 출력 멤버함수
void Stack::PrintStack() {
    Node* curNode = m_pTop; // 현재 노드를 가리키는 포인터


    while (curNode) {
        cout << curNode->GetData() << " "; // 현재 노드의 데이터 출력
        curNode = curNode->GetNext(); // 다음 노드로 이동
    }
}

int main() {
    Stack* stack = new Stack; // Stack 객체 생성
    char command[20]; // 사용자 입력을 받을 문자열
    int input = 0, size; // 사용자 입력을 받을 정수와 스택의 크기

    cin >> size; // 스택의 크기 입력
    stack->SetSize(size); // 스택의 크기 설정

    while (1) { // 사용자가 exit 명령을 입력할 때까지 무한 반복
        cin >> command; // 명령어 입력

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
        else if (strcmp(command, "exit") == 0) { // exit 명령을 입력한 경우
            break; // 반복문 탈출
        }
        else { // 잘못된 명령을 입력한 경우
            cout << "Enter valid command" << endl;
        }
    }

    delete stack; // 동적 할당한 메모리 해제

    return 0; // 프로그램 종료
}