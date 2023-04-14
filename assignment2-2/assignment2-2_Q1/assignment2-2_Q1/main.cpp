#include <iostream>
#include <string>

using namespace std;

// 노드 선언부
class Node {
private:
    string str; // 각각의 노드는 문자열과
    Node* next; // 다음 노드의 주소,
    Node* d_next; // 다음 차원의 리스트의 head 주소를 가리키는 요소를 가짐

public:
    Node() { // 노드 생성자
        str = "";
        next = NULL;
        d_next = NULL;
    }

    void setInput(string input) { this->str = input; } // 노드의 문자열을 저장하는 멤버함수
    string getInput() { return this->str; } // 노드의 문자열을 반환하는 멤버함수
    void setNext(Node* nextNode) { this->next = nextNode; } // 노드의 다음 노드를 설정하는 멤버함수
    void d_setNext(Node* d_nextNode) { this->d_next = d_nextNode; } // 노드의 다음 차원 리스트를 설정하는 멤버함수
    Node* getNext() { return this->next; } // 다음 노드의 주소를 반환하는 멤버함수
    Node* d_getNext() { return this->d_next; } // 다음 차원의 리스트 주소를 반환하는 멤버함수
};

// 리스트 선언부
class List {
private:
    Node* head; // 리스트는 각각 처음의 의미하는 head
    int size; // 리스트에 저장된 갯수를 의미하는 size
    Node* tail; // 리스트의 마지막을 의미하는 tail로 구성
public:
    List() { // 리스트 생성자
        this->head = NULL;
        this->tail = NULL;
        size = 0;
    }

    ~List() { // 리스트 소멸자
        Node* curNode = head;
        Node* delNode = NULL;
        while (curNode != NULL) {
            delNode = curNode;
            curNode = curNode->getNext();
            delete delNode;
        }
    }

    // 리스트 멤버함수 선언부
    void Insert(string data);
    void d_Insert(List* temp_list);
    void Print_all(Node* curNode);
    void Print(Node* curNode, int index[100], int cnt);
    Node* getHead() { return this->head; }
};

// 리스트에 요소 삽입 멤버함수
void List::Insert(string data) {
    // 새로운 노드를 만들어서 문자열 저장
    Node* newNode = new Node;
    newNode->setInput(data);

    if (head == NULL) { // 요소가 하나도 없으면 리스트의 첫번째 요소로 삽입
        tail = head = newNode;
        this->size++;
    }
    else { // 기존 노드가 있으면
        tail->setNext(newNode); // 마지막에 이어 붙이고 
        tail = newNode; // 해당 노드를 꼬리로 설정
        this->size++;
    }
}

// 리스트에 다음 차원 연결 멤버함수
void List::d_Insert(List* temp_list) {
    Node* newNode = new Node; // 새로운 노드를 만들어서
    tail->setNext(newNode); // 꼬리의 다음으로 설정, 데이터를 갖지 않음
    tail = tail->getNext(); // 꼬리를 방금 이어붙인 노드로 설정

    tail->d_setNext(temp_list->head); // 꼬리를 전달받은 임시 리스트와 연결
}

// curNode부터 같은 level에 있는 요소를 모두 출력하는 멤버함수
void List::Print_all(Node* curNode) {
    // 전달받은 현재노드가 비어있지 않으면 반복
    while (curNode != NULL) {
        if (curNode->d_getNext()) { // 현재노드에서 다음 차원의 리스트가 있으면
            cout << "[";
            Print_all(curNode->d_getNext()); // 해당 리스트의 head부터 재귀적으로 출력
            cout << "]";
        }

        // 현재노드의 다음 노드가 존재하면
        if (curNode->getNext()) {
            cout << curNode->getInput() << ", "; // 출력 후 콤마 붙이기
        }
        else // 다음 노드가 없으면 콤마 없이 출력
            cout << curNode->getInput();

        // 현재노드를 다음노드를 설정 후 반복문 반복
        curNode = curNode->getNext();
    }
}

// 입력받은 index만큼 출력하는 멤버함수
void List::Print(Node* curNode, int index[100], int cnt) {
    Node* printNode = new Node; // 출력노드 임시 설정

    // 입력받은 index 갯수만큼 반복
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < index[i]; j++) { // 입력받은 index만큼 반복하며 노드 이동
            curNode = curNode->getNext();
        }
        // 이동 후 현재노드 저장
        printNode = curNode;
        if (curNode->d_getNext()) { // 이동한 노드에 다음 차원이 저장되어 있으면    
            curNode = curNode->d_getNext(); // 현재노드를 다음 차원 리스트로 설정
        }
    }

    // 출력노드에 저장된 값이 없으면 다음 차원의 주소가 저장된 노드를 의미
    if (printNode->getInput() == "") {
        cout << "[";
        Print_all(printNode->d_getNext()); // 다음 차원의 리스트를 전부 출력
        cout << "]" << endl;
    }
    else { // 다음 차원이 저장되지 않았으면 그냥 저장된 값 출력
        cout << curNode->getInput() << endl;
    }

}

// 입력받은 값을 나누는 함수
int parse(List* Linked_list, string input, int i, int level) {
    string temp = ""; // 임시 문자열

    for (; i < input.length();) { // 입력받은 문자열만큼 반복
        if (input[i] == '[') { // 배열 시작을 만나면 
            i++; // i 1증가 후 
            List* temp_list = new List; // 임시로 리스트를 만들어서
            i = parse(temp_list, input, i, level); // 차원 노드와 연결하기 위해 재귀적으로 호출
            Linked_list->d_Insert(temp_list); // 해당 리스트를 연결
        }
        else if (input[i] == ']') { // 배열 탈출을 만나면
            Linked_list->Insert(temp); // temp에 저장된 값을 삽입
            temp = "";
            i = i + 2;
            return i; // i 반환
        }
        else if (input[i] == ',') {
            i++;
            Linked_list->Insert(temp);
            temp = "";

        }
        else {
            temp.push_back(input[i]); // 무엇도 아니면 입력값 임시 배열에 저장
            i++;
        }
    }
}


int main() {
    List* Linked_list = new List;
    string input, temp, command = "";
    int begin = 1, end = 0, level = 1, i = 1;

    getline(cin, input); // 입력값 input에 저장

    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    parse(Linked_list, input, i, level);

    while (1) {
        cin >> command;
        if (command == "arr") { // 전체 배열 출력
            cout << '[';
            Linked_list->Print_all(Linked_list->getHead());
            cout << ']' << endl;
        }
        else if (command == "exit")
            break;
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

            Linked_list->Print(Linked_list->getHead(), index, cnt);
        }
    }

    delete Linked_list;

    return 0;
}