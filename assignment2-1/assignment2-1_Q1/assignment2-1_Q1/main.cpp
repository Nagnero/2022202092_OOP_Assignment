#include <iostream>
#include <string.h>

using namespace std;

// Node Ŭ���� ����
class Node {
// �ش� ��忡���� ���� ������ ����. 
// ��忡 ����� �� (value), ���� ��� �ּ�(next), ���� ��� �ּ� (prev)
private:
    int value;
    Node* next;
    Node* prev;
// �ش� ��� �ۿ����� ���� ������ ����
public:
    // ��带 ������ �� �ڵ����� �ʱ�ȭ
    Node() {
        this->value = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    // Node�� �����ϰų� �����Ͽ� ���� ����ϴ� �޼���
    void setValue(int data) { this->value = data; } // ����� ���� �����ϴ� �޼���
    int getValue() { return this->value; } // ��忡 ����� ���� ��ȯ�ϴ� �޼���
    void setNext(Node* nextNode) { this->next = nextNode; } // ����� ���� ��带 �����ϴ� �޼���
    Node* getNext() { return this->next; } // ��忡 ������ ���� ��带 ��ȯ�ϴ� �޼���
    void setPrev(Node* prevNode) { this->prev = prevNode; } // ����� ���� ��带 �����ϴ� �޼���
    Node* getPrev() { return this->prev; } // ����� ������ ���� ��带 ��ȯ�ϴ� �޼���
};

// Stack Ŭ���� �����
class Stack {
// �ش� ��忡���� ���� ������ ����. 
// ������ ũ��(size), top ����� �ּ�(top), bottom ����� �ּ�(bottom)
private:
    Node* top;
    Node* bottom;
    int size;
// �ش� ��� �ۿ����� ���� ������ ����
public:
    // �������� ������ �� �ڵ����� �ʱ�ȭ
    Stack() {
        this->top = NULL;
        this->bottom = NULL;
        this->size = 0;
    }
    // ������ �Ҹ���. delete�� �� ȣ���
    ~Stack() {
        // �ӽó��
        Node* curNode = top; // ���� ��带 �ǹ�. top������ ����
        Node* delNode = NULL; // ������ ��带 �ǹ�
        while (curNode != NULL) // top ������ ���������� ����
        {
            delNode = curNode; // delNode�� �����带 �����ϰ�
            curNode = curNode->getPrev(); // ���� ��带 �Ʒ� ���� ����. ���� bottom�� ��� NULL�� ��
            delete delNode; // delNode�� ����Ű�� �޸� ����
        }
        delNode = NULL; // delNode�� ����� �ּҰ� NULL�� �ʱ�ȭ
    }
    // Stack�� Ŭ���� �޼���
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
    else { // ������� ������
        if (this->size > 1) { // ���ÿ� ����� ��尡 2�� �̻��̸�
            Node* tempNode = top; // top ��带 �ӽ÷� �����ϰ�
            cout << top->getValue() << endl; // top��忡 ����� �� ��� ��
            top = top->getPrev(); // ������带 ž���� ����
            top->setNext(NULL); // ž���� ������ ��������� ���� ��� ���ְ�
            delete tempNode; // �̸� �����س��� ���� top��� ����
            this->size--; // ���ÿ� ����� ��� �� 1 ����
        }
        else { // ���ÿ� ����� ��尡 1���� top���� bottom��尡 ����
            cout << top->getValue() << endl; // ����� ��忡 ����� �� ��� ��
            delete bottom; // bottom��带 �����ϸ� top��带 �����ϴ� �Ͱ� ����
            bottom = NULL; // top�� bottom�� ����� �� �ʱ�ȭ
            top = NULL;
            this->size--; // ���ÿ� ����� ���� 1 ���ҽ��� 0���� �����
        }
    }
}

// top ��� �޼���
void Stack::print_top() {
    if (!(this->is_empty())) // ������ ������� ������
        cout << top->getValue() << endl; // top ���
    else // ������ ���������
        cout << "Stack is empty" << endl; // ����ִٴ� �ȳ����� ���
}

// ��� ��忡 ����� �� ��� �޼���
void Stack::print_all() {
    // ������ ��������� ����ִٰ� ��� �� �޼��� ����
    if ((this->is_empty())) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* curNode = bottom; // �ӽ� ��� ����. bottom ��� �Ҵ�

    while (curNode) { // �ӽó�� (������)�� ����� ���� ������ �ݺ�
        cout << curNode->getValue() << " ";
        curNode = curNode->getNext();
    } // ����� �� ��� �� �����带 �������� �̵�
    cout << endl;

    delete curNode; // �ӽ� ��� �Ҵ�����
}

// ������ ����ִ��� Ȯ���ϴ� �޼���
int Stack::is_empty() {
    if (this->size == 0) // ��������� 1 ��ȯ
        return 1;
    else
        return 0;
}

int main() {
    Stack* stack = new Stack; // ���ο� ���� �Ҵ�
    char command[6]{}; // Ŀ�ǵ带 �Է� ���� ����
    int input; // �� ��忡 ������� ����

    while (1) {

        cin >> command;
        // Ŀ�ǵ忡 ���� ���� �ٸ� ���� Ŭ���� �޼��� ȣ��
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
        else { // � Ŀ�ǵ�͵� ��ġ���� �ʴ� Ŀ�ǵ�� ���Է� �䱸
            cout << "Enter valid command" << endl;
        }
    }

    delete stack; // ���� ���� �� ����

    return 0;
}