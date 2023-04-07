#include <iostream>
#include <string.h>

using namespace std;

// Node 클래스 선언
class Node {
// 해당 노드에서만 접근 가능한 정보. 
// 노드에 저장된 값 (value), 다음 노드 주소(next), 이전 노드 주소 (prev)
private:
    int value;
    Node* next;
    Node* prev;
// 해당 노드 밖에서도 접근 가능한 정보
public:
    // 노드를 선언할 시 자동으로 초기화
    Node() {
        this->value = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    // Node를 수정하거나 접근하여 값을 출력하는 메서드
    void setValue(int data) { this->value = data; } // 노드의 값을 수정하는 메서드
    int getValue() { return this->value; } // 노드에 저장된 값을 반환하는 메서드
    void setNext(Node* nextNode) { this->next = nextNode; } // 노드의 다음 노드를 지정하는 메서드
    Node* getNext() { return this->next; } // 노드에 지정된 다음 노드를 반환하는 메서드
    void setPrev(Node* prevNode) { this->prev = prevNode; } // 노드의 이전 노드를 지정하는 메서드
    Node* getPrev() { return this->prev; } // 노드의 지정된 이전 노드를 반환하는 메서드
};

// Stack 클래스 선언부
class Stack {
// 해당 노드에서만 접근 가능한 정보. 
// 스택의 크기(size), top 노드의 주소(top), bottom 노드의 주소(bottom)
private:
    Node* top;
    Node* bottom;
    int size;
// 해당 노드 밖에서도 접근 가능한 정보
public:
    // 스택을를 선언할 시 자동으로 초기화
    Stack() {
        this->top = NULL;
        this->bottom = NULL;
        this->size = 0;
    }
    // 스택의 소멸자. delete될 때 호출됨
    ~Stack() {
        // 임시노드
        Node* curNode = top; // 현재 노드를 의미. top노드부터 시작
        Node* delNode = NULL; // 삭제할 노드를 의미
        while (curNode != NULL) // top 노드부터 순차적으로 삭제
        {
            delNode = curNode; // delNode에 현재노드를 저장하고
            curNode = curNode->getPrev(); // 현재 노드를 아래 노드로 지정. 현재 bottom일 경우 NULL이 됨
            delete delNode; // delNode가 가리키는 메모리 삭제
        }
        delNode = NULL; // delNode에 저장된 주소값 NULL로 초기화
    }
    // Stack의 클래스 메서드
    void push(int data);
    void pop();
    void print_top();
    void print_all();
    int is_empty();
};

// 요소 추가 메서드
void Stack::push(int data) {
    Node* newNode = new Node; // 새로운 저장공간 생성
    newNode->setValue(data);  // 데이터 저장

    if (is_empty()) {         // 비어 있으면
        top = bottom = newNode; // 새로운 노드를 탑이자 바텀으로 지정
        this->size++;           // 사이즈 증가
    }
    else {                  // 이미 값이 있으면
        top->setNext(newNode);  // top의 next를 새 노드로 지정
        newNode->setPrev(top);  // 새 노드의 이전 노드를 top으로 지정
        top = top->getNext();   // top을 새 노드로 지정
        this->size++;
    }
}

// 요소 삭제 메서드
void Stack::pop() {
    if (is_empty()) { // 비어 있으면
        cout << "Already empty" << endl;
    }
    else { // 비어있지 않으면
        if (this->size > 1) { // 스택에 저장된 노드가 2개 이상이면
            Node* tempNode = top; // top 노드를 임시로 저장하고
            cout << top->getValue() << endl; // top노드에 저장된 값 출력 후
            top = top->getPrev(); // 이전노드를 탑노드로 지정
            top->setNext(NULL); // 탑으로 지정된 이전노드의 다음 노드 없애고
            delete tempNode; // 미리 저장해놓은 기존 top노드 삭제
            this->size--; // 스택에 저장된 노드 수 1 감소
        }
        else { // 스택에 저장된 노드가 1개면 top노드와 bottom노드가 같음
            cout << top->getValue() << endl; // 저장된 노드에 저장된 값 출력 후
            delete bottom; // bottom노드를 삭제하면 top노드를 삭제하는 것과 동일
            bottom = NULL; // top과 bottom에 저장된 값 초기화
            top = NULL;
            this->size--; // 스택에 저장된 노드수 1 감소시켜 0으로 만들기
        }
    }
}

// top 출력 메서드
void Stack::print_top() {
    if (!(this->is_empty())) // 스택이 비어있지 않으면
        cout << top->getValue() << endl; // top 출력
    else // 스택이 비어있으면
        cout << "Stack is empty" << endl; // 비어있다는 안내문구 출력
}

// 모든 노드에 저장된 값 출력 메서드
void Stack::print_all() {
    // 스택이 비어있으면 비어있다고 출력 후 메서드 종료
    if ((this->is_empty())) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* curNode = bottom; // 임시 노드 설정. bottom 노드 할당

    while (curNode) { // 임시노드 (현재노드)에 저장된 값이 있으면 반복
        cout << curNode->getValue() << " ";
        curNode = curNode->getNext();
    } // 저장된 값 출력 후 현재노드를 다음노드로 이동
    cout << endl;

    delete curNode; // 임시 노드 할당해제
}

// 스택이 비어있는지 확인하는 메서드
int Stack::is_empty() {
    if (this->size == 0) // 비어있으면 1 반환
        return 1;
    else
        return 0;
}

int main() {
    Stack* stack = new Stack; // 새로운 스택 할당
    char command[6]{}; // 커맨드를 입력 받을 변수
    int input; // 각 노드에 집어넣을 정수

    while (1) {

        cin >> command;
        // 커맨드에 따라 각기 다른 스택 클래스 메서드 호출
        if (!strcmp(command, "push")) {
            cin >> input;
            stack->push(input);
        }
        else if (!strcmp(command, "pop")) {
            stack->pop();
        }
        else if (!strcmp(command, "top")) {
            stack->print_top();
        }
        else if (!strcmp(command, "print")) {
            stack->print_all();
        }
        else if (!strcmp(command, "empty")) {
            cout << stack->is_empty() << endl;
        }
        else if (strcmp(command, "exit") == 0) { 
            break;
        }
        else { // 어떤 커맨드와도 매치되지 않는 커맨드면 재입력 요구
            cout << "Enter valid command" << endl;
        }
    }

    delete stack; // 스택 삭제 후 종료

    return 0;
}