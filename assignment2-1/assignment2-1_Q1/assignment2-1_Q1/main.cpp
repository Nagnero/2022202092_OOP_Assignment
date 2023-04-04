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

// ��� �߰� �޼���
void Stack::push(int data) {
    Node* newNode = new Node; // ���ο� ������� ����
    newNode->setValue(data);  // ������ ����

    if (is_empty()) {         // ��� ������
        top = bottom = newNode; // ���ο� ��带 ž���� �������� ����
        this->size++;           // ������ ����
    }
    else {                  // �̹� ���� ������
        top->setNext(newNode);  // top�� next�� �� ���� ����
        newNode->setPrev(top);  // �� ����� ���� ��带 top���� ����
        top = top->getNext();   // top�� �� ���� ����
        this->size++;
    }
}

// ��� ���� �޼���
void Stack::pop() {
    if (is_empty()) { // ��� ������
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
    if (this->size == 0) // ��������� 1 ��ȯ
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