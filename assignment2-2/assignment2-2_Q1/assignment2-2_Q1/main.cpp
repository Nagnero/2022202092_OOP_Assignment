#include <iostream>
#include <string>

using namespace std;

// ��� �����
class Node {
private:
    string str; // ������ ���� ���ڿ���
    Node* next; // ���� ����� �ּ�,
    Node* d_next; // ���� ������ ����Ʈ�� head �ּҸ� ����Ű�� ��Ҹ� ����

public:
    Node() { // ��� ������
        str = "";
        next = NULL;
        d_next = NULL;
    }

    void setInput(string input) { this->str = input; } // ����� ���ڿ��� �����ϴ� ����Լ�
    string getInput() { return this->str; } // ����� ���ڿ��� ��ȯ�ϴ� ����Լ�
    void setNext(Node* nextNode) { this->next = nextNode; } // ����� ���� ��带 �����ϴ� ����Լ�
    void d_setNext(Node* d_nextNode) { this->d_next = d_nextNode; } // ����� ���� ���� ����Ʈ�� �����ϴ� ����Լ�
    Node* getNext() { return this->next; } // ���� ����� �ּҸ� ��ȯ�ϴ� ����Լ�
    Node* d_getNext() { return this->d_next; } // ���� ������ ����Ʈ �ּҸ� ��ȯ�ϴ� ����Լ�
};

// ����Ʈ �����
class List {
private:
    Node* head; // ����Ʈ�� ���� ó���� �ǹ��ϴ� head
    int size; // ����Ʈ�� ����� ������ �ǹ��ϴ� size
    Node* tail; // ����Ʈ�� �������� �ǹ��ϴ� tail�� ����
public:
    List() { // ����Ʈ ������
        this->head = NULL;
        this->tail = NULL;
        size = 0;
    }

    ~List() { // ����Ʈ �Ҹ���
        Node* curNode = head;
        Node* delNode = NULL;
        while (curNode != NULL) {
            delNode = curNode;
            curNode = curNode->getNext();
            delete delNode;
        }
    }

    // ����Ʈ ����Լ� �����
    void Insert(string data);
    void d_Insert(List* temp_list);
    void Print_all(Node* curNode);
    void Print(Node* curNode, int index[100], int cnt);
    Node* getHead() { return this->head; }
};

// ����Ʈ�� ��� ���� ����Լ�
void List::Insert(string data) {
    // ���ο� ��带 ���� ���ڿ� ����
    Node* newNode = new Node;
    newNode->setInput(data);

    if (head == NULL) { // ��Ұ� �ϳ��� ������ ����Ʈ�� ù��° ��ҷ� ����
        tail = head = newNode;
        this->size++;
    }
    else { // ���� ��尡 ������
        tail->setNext(newNode); // �������� �̾� ���̰� 
        tail = newNode; // �ش� ��带 ������ ����
        this->size++;
    }
}

// ����Ʈ�� ���� ���� ���� ����Լ�
void List::d_Insert(List* temp_list) {
    Node* newNode = new Node; // ���ο� ��带 ����
    tail->setNext(newNode); // ������ �������� ����, �����͸� ���� ����
    tail = tail->getNext(); // ������ ��� �̾���� ���� ����

    tail->d_setNext(temp_list->head); // ������ ���޹��� �ӽ� ����Ʈ�� ����
}

// curNode���� ���� level�� �ִ� ��Ҹ� ��� ����ϴ� ����Լ�
void List::Print_all(Node* curNode) {
    // ���޹��� �����尡 ������� ������ �ݺ�
    while (curNode != NULL) {
        if (curNode->d_getNext()) { // �����忡�� ���� ������ ����Ʈ�� ������
            cout << "[";
            Print_all(curNode->d_getNext()); // �ش� ����Ʈ�� head���� ��������� ���
            cout << "]";
        }

        // �������� ���� ��尡 �����ϸ�
        if (curNode->getNext()) {
            cout << curNode->getInput() << ", "; // ��� �� �޸� ���̱�
        }
        else // ���� ��尡 ������ �޸� ���� ���
            cout << curNode->getInput();

        // �����带 ������带 ���� �� �ݺ��� �ݺ�
        curNode = curNode->getNext();
    }
}

// �Է¹��� index��ŭ ����ϴ� ����Լ�
void List::Print(Node* curNode, int index[100], int cnt) {
    Node* printNode = new Node; // ��³�� �ӽ� ����

    // �Է¹��� index ������ŭ �ݺ�
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < index[i]; j++) { // �Է¹��� index��ŭ �ݺ��ϸ� ��� �̵�
            curNode = curNode->getNext();
        }
        // �̵� �� ������ ����
        printNode = curNode;
        if (curNode->d_getNext()) { // �̵��� ��忡 ���� ������ ����Ǿ� ������    
            curNode = curNode->d_getNext(); // �����带 ���� ���� ����Ʈ�� ����
        }
    }

    // ��³�忡 ����� ���� ������ ���� ������ �ּҰ� ����� ��带 �ǹ�
    if (printNode->getInput() == "") {
        cout << "[";
        Print_all(printNode->d_getNext()); // ���� ������ ����Ʈ�� ���� ���
        cout << "]" << endl;
    }
    else { // ���� ������ ������� �ʾ����� �׳� ����� �� ���
        cout << curNode->getInput() << endl;
    }

}

// �Է¹��� ���� ������ �Լ�
int parse(List* Linked_list, string input, int i, int level) {
    string temp = ""; // �ӽ� ���ڿ�

    for (; i < input.length();) { // �Է¹��� ���ڿ���ŭ �ݺ�
        if (input[i] == '[') { // �迭 ������ ������ 
            i++; // i 1���� �� 
            List* temp_list = new List; // �ӽ÷� ����Ʈ�� ����
            i = parse(temp_list, input, i, level); // ���� ���� �����ϱ� ���� ��������� ȣ��
            Linked_list->d_Insert(temp_list); // �ش� ����Ʈ�� ����
        }
        else if (input[i] == ']') { // �迭 Ż���� ������
            Linked_list->Insert(temp); // temp�� ����� ���� ����
            temp = "";
            i = i + 2;
            return i; // i ��ȯ
        }
        else if (input[i] == ',') {
            i++;
            Linked_list->Insert(temp);
            temp = "";

        }
        else {
            temp.push_back(input[i]); // ������ �ƴϸ� �Է°� �ӽ� �迭�� ����
            i++;
        }
    }
}


int main() {
    List* Linked_list = new List;
    string input, temp, command = "";
    int begin = 1, end = 0, level = 1, i = 1;

    getline(cin, input); // �Է°� input�� ����

    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    parse(Linked_list, input, i, level);

    while (1) {
        cin >> command;
        if (command == "arr") { // ��ü �迭 ���
            cout << '[';
            Linked_list->Print_all(Linked_list->getHead());
            cout << ']' << endl;
        }
        else if (command == "exit")
            break;
        else { // �迭 �����ؼ� ��� �� ��
            int cnt = 0, index[100] {}; // 100���� �迭���� ��� ����
            for (int i = 3; i < command.length(); i++) 
                if (command[i] == '[') {
                    temp = "";
                    i++;
                    while (command[i] != ']') {
                        temp.push_back(command[i]);
                        i++;
                    }
                    index[cnt++] = stoi(temp);
                }

            Linked_list->Print(Linked_list->getHead(), index, cnt);
        }
    }

    delete Linked_list;

    return 0;
}