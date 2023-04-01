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
    bool is_empty();
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

        }
        else {
            cout << top->getValue();
            Node* tempNode =
                cout << top->getValue();
            delete top;
            top = NULL;
            bottom = NULL;
            size--;
        }
    }
}

bool Stack::is_empty() {
    if (this->size == 0)
        return 1;
    else
        return 0;
}

int main() {
    char command[6]{};
    int input;

    while (strcmp(command, "exit") != 0) {
        cin >> command >> input;

        if (strcmp(command, "push")) {
        }
    }
}