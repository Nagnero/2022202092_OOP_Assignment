#include <iostream>
#include <string.h>

using namespace std;

class Node {
private:
    int value;
    Node* next;
    Node* prev;

public:
    Node() {
        this->value = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    void setValue(int data) { this->value = data; }
    int getValue() { return this->value; }
    void setNext(Node* nextNode) { this->next = nextNode; }
    Node* getNext() { return this->next; }
    void setPrev(Node* prevNode) { this->prev = prevNode; }
    Node* getPrev() { return this->prev; }
};

class Stack {
private:
    Node* top;
    Node* bottom;
    int size;

public:
    Stack() {
        this->top = NULL;
        this->bottom = NULL;
        this->size = 0;
    }
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
    else {
        if (this->size > 1) {
            Node* tempNode = top;
            cout << top->getValue() << endl;
            top = top->getPrev();
            top->setNext(NULL);
            delete tempNode;

            this->size--;
        }
        else {
            cout << top->getValue() << endl;               
            delete bottom;
            bottom = NULL;
            top = NULL;
            this->size--;
        }
    }
}

void Stack::print_top() {
    if (!(this->is_empty()))
        cout << top->getValue() << endl;
    else
        cout << "Stack is empty" << endl;
}

void Stack::print_all() {
    Node* curNode = bottom;

    while (curNode) {
        cout << curNode->getValue() << " ";
        curNode = curNode->getNext();
    }
    cout << endl;

    delete curNode;
}

int Stack::is_empty() {
    if (this->size == 0) // 비어있으면 1 반환
        return 1;
    else
        return 0;
}

int main() {
    Stack* stack = new Stack;
    char command[6]{};
    int input;

    while (strcmp(command, "exit") != 0) {
        cin >> command;

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
        else {
            cout << "Enter valid command" << endl;
        }
    }

    delete stack;

    return 0;
}