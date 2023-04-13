#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string str;
    Node* next;
    Node* d_next;

public:
    Node() {
        str = "";
        next = NULL;
        d_next = NULL;
    }

    void setInput(string input) { this->str = input; }
    string getInput() { return this->str; }
    void setNext(Node* nextNode) { this->next = nextNode; }
    void d_setNext(Node* d_nextNode) { this->d_next = d_nextNode; }
    Node* getNext() { return this->next; }
    Node* d_getNext() { return this->d_next; }
};

class List {
private:
    Node* head;
    int size;
    Node* tail;
public:
    List() {
        this->head = NULL;
        this->tail = NULL;
        size = 0;
    }
    ~List() {
        Node* curNode = head;
        Node* delNode = NULL;
        while (curNode != NULL) {
            delNode = curNode;
            curNode = curNode->getNext();
            delete delNode;
        }
    }
    void INSERT(string data);
    void d_INSERT(List* temp_list);
    void Print_all(Node* curNode);
    Node* getHead() { return this->head; }
};

void List::INSERT(string data) {
    Node* newNode = new Node;
    newNode->setInput(data);

    if (head == NULL) {
        tail = head = newNode;
        this->size++;
    }
    else {
        tail->setNext(newNode);
        tail = newNode;
        this->size++;
    }
}

void List::d_INSERT(List* temp_list) {
    Node* newNode = new Node;
    tail->setNext(newNode);
    tail = tail->getNext();

    tail->d_setNext(temp_list->head);
}

void List::Print_all(Node* curNode) {

    while (curNode != NULL) {
        if (curNode->d_getNext()) {
            cout << "[";
            Print_all(curNode->d_getNext());
            cout << "]";
        }


        if (curNode->getNext()) {
            cout << curNode->getInput() << ", ";
        }
        else
            cout << curNode->getInput();

        curNode = curNode->getNext();
    }
}


int parse(List* Linked_list, string input, int i, int level) {
    string temp = "";

    for (; i < input.length();) {
        if (input[i] == '[') { // 배열 시작을 만나면 
            i++;
            List* temp_list = new List;
            i = parse(temp_list, input, i, level);
            Linked_list->d_INSERT(temp_list);
        }
        else if (input[i] == ']') { // 배열 탈출을 만나면
            Linked_list->INSERT(temp); // temp에 저장된 값을 삽입
            temp = "";
            i = i + 3;
            return i;
        }
        else if (input[i] == ',') {
            i = i + 2; // 콤마와 공백은 세트이므로
            Linked_list->INSERT(temp);
            temp = "";

        }
        else {
            temp.push_back(input[i]);
            i++;
        }
    }
}


int main() {
    List* Linked_list = new List;
    string input, temp, command = "";
    int begin = 1, end = 0, level = 1, i = 1;

    getline(cin, input);

    parse(Linked_list, input, i, level);

    while (command != "exit") {
        cin >> command;
        if (command == "arr") { // 전체 배열 출력
            cout << '[';
            Linked_list->Print_all(Linked_list->getHead());
            cout << ']' << endl;
        }
        else { // 배열 지정해서 출력 할 시
            int cnt = 0, index[100] {}; // 100차원 배열까지 출력 가능
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


        }
    }



}