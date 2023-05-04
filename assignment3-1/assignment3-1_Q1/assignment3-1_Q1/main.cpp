#include <iostream>
#include <string>

using namespace std;

// 노드 클래스 정의
class Node {
private:
	Node* nextNode;
	string data;

public:
	// 생성자 및 소멸자 정의
	Node() {
		this->nextNode = NULL;
		this->data = "";
	}
	Node(string data) {
		this->nextNode = NULL;
		this->data = data;
	}
	~Node() {}

	// 멤버함수 정의
	void setNext(Node* nextNode) { this->nextNode = nextNode; }
	void INSERT(Node* nextNode);
	Node* getNext() { return this->nextNode; }
	void setData(string data) { this->data = data; }
	string getData() { return this->data; }

	void print_all();
	void deleteNodes(); // 노드 삭제 함수
};

// 노드 삽입 멤버함수
void Node::INSERT(Node* nextNode) {
	if (this->getNext() != NULL) { // 첫번째 노드가 아닐 경우
		Node* curNode = this->getNext();
		Node* prevNode = NULL;

		while (curNode) {
			// 전달받은 문자열이 더 클 경우
			if (_stricmp(curNode->getData().c_str(), nextNode->getData().c_str()) < 0) {
				prevNode = curNode;
				curNode = curNode->getNext();
			}
			else { // 전달받은 문자열이 더 작을 경우 삽입
				if (!prevNode) { // 첫번째로 삽입될 경우
					this->setNext(nextNode);
					nextNode->setNext(curNode);
				}
				else { // 첫번째가 아닐경우
					prevNode->setNext(nextNode);
					nextNode->setNext(curNode);
				}
				break;
			}
		}
		// 마지막에 삽입되는 경우
		if (!curNode) {
			prevNode->setNext(nextNode);
		}
	}
	else { // 첫번째 노드일 경우
		this->setNext(nextNode);
	}
}

// 출력 멤버함수
void Node::print_all() {
	// 첫 p3노드 건너뛰기
	Node* curNode = this->getNext();

	while (curNode) {
		cout << curNode->getData() << " ";
		curNode = curNode->getNext();
	}
}

// 노드 삭제 함수 
void Node::deleteNodes() {
	Node* curNode = this->getNext();
	Node* delNode = NULL;

	while (curNode) {
		delNode = curNode;
		curNode = curNode->getNext();

		delete delNode;
	}
}

// 노드 합병 함수
void Merge_List(Node* p1, Node* p2, Node* p3) {
	Node* curNode1 = p1->getNext();
	Node* curNode2 = p2->getNext();
	Node* curNode3 = p3;

	p1->setNext(NULL);
	p2->setNext(NULL);

	// curNode1과 curNode2 중 하나가 마지막이 될때까지 반복
	while (curNode1 && curNode2) {
		// curNode2에 저장된 문자열이 더 클 경우
		if (_stricmp(curNode1->getData().c_str(), curNode2->getData().c_str()) < 0) {
			curNode3->setNext(curNode1);
			curNode1 = curNode1->getNext();
			curNode3 = curNode3->getNext();
		}
		else {
			curNode3->setNext(curNode2);
			curNode2 = curNode2->getNext();
			curNode3 = curNode3->getNext();
		}
	}

	// 모든 노드를 돌았는지 확인. curNode1를 모두 탐색한 경우
	if (!curNode1) {
		while (curNode2) {
			curNode3->setNext(curNode2);
			curNode2 = curNode2->getNext();
			curNode3 = curNode3->getNext();
		}
	}
	else { // curNode2를 모두 탐색한 경우
		while (curNode1) {
			curNode3->setNext(curNode1);
			curNode1 = curNode1->getNext();
			curNode3 = curNode3->getNext();
		}
	}
}

int main() {
	Node* p1 = new Node;
	Node* p2 = new Node;
	Node* p3 = new Node;
	string input, temp;

	cout << "Input>>" << endl << "Input list 1: ";
	getline(cin, input);

	// 공백을 기준으로 문자열을 분리하고 노드에 삽입
	for (int i = 0; i < strlen(input.c_str()) + 1; i++) {
		if (input[i] == ' ' || input[i] == '\0') {
			Node* newNode = new Node(temp);
			p1->INSERT(newNode);
			newNode = NULL;
			temp = "";
			continue;
		}

		temp += input[i];
	}

	cout  << "Input list 2: ";
	getline(cin, input);

	// 공백을 기준으로 문자열을 분리하고 노드에 삽입
	for (int i = 0; i < strlen(input.c_str()) + 1; i++) {
		if (input[i] == ' ' || input[i] == '\0') {
			Node* newNode = new Node(temp);
			p2->INSERT(newNode);
			newNode = NULL;
			temp = "";
			continue;
		}

		temp += input[i];
	}

	// 노드를 합병하고 결과를 출력
	Merge_List(p1, p2, p3);
	cout << endl << "Output>>" << endl << "Result: ";
	p3->print_all();

	// 메모리 삭제
	p1->deleteNodes();
	p2->deleteNodes();
	p3->deleteNodes();

	// 객체 삭제
	delete p1;
	delete p2;
	delete p3;


	return 0;
}