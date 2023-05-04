#include <iostream>
#include <string>

using namespace std;

// ��� Ŭ���� ����
class Node {
private:
	Node* nextNode;
	string data;

public:
	// ������ �� �Ҹ��� ����
	Node() {
		this->nextNode = NULL;
		this->data = "";
	}
	Node(string data) {
		this->nextNode = NULL;
		this->data = data;
	}
	~Node() {}

	// ����Լ� ����
	void setNext(Node* nextNode) { this->nextNode = nextNode; }
	void INSERT(Node* nextNode);
	Node* getNext() { return this->nextNode; }
	void setData(string data) { this->data = data; }
	string getData() { return this->data; }

	void print_all();
	void deleteNodes(); // ��� ���� �Լ�
};

// ��� ���� ����Լ�
void Node::INSERT(Node* nextNode) {
	if (this->getNext() != NULL) { // ù��° ��尡 �ƴ� ���
		Node* curNode = this->getNext();
		Node* prevNode = NULL;

		while (curNode) {
			// ���޹��� ���ڿ��� �� Ŭ ���
			if (_stricmp(curNode->getData().c_str(), nextNode->getData().c_str()) < 0) {
				prevNode = curNode;
				curNode = curNode->getNext();
			}
			else { // ���޹��� ���ڿ��� �� ���� ��� ����
				if (!prevNode) { // ù��°�� ���Ե� ���
					this->setNext(nextNode);
					nextNode->setNext(curNode);
				}
				else { // ù��°�� �ƴҰ��
					prevNode->setNext(nextNode);
					nextNode->setNext(curNode);
				}
				break;
			}
		}
		// �������� ���ԵǴ� ���
		if (!curNode) {
			prevNode->setNext(nextNode);
		}
	}
	else { // ù��° ����� ���
		this->setNext(nextNode);
	}
}

// ��� ����Լ�
void Node::print_all() {
	// ù p3��� �ǳʶٱ�
	Node* curNode = this->getNext();

	while (curNode) {
		cout << curNode->getData() << " ";
		curNode = curNode->getNext();
	}
}

// ��� ���� �Լ� 
void Node::deleteNodes() {
	Node* curNode = this->getNext();
	Node* delNode = NULL;

	while (curNode) {
		delNode = curNode;
		curNode = curNode->getNext();

		delete delNode;
	}
}

// ��� �պ� �Լ�
void Merge_List(Node* p1, Node* p2, Node* p3) {
	Node* curNode1 = p1->getNext();
	Node* curNode2 = p2->getNext();
	Node* curNode3 = p3;

	p1->setNext(NULL);
	p2->setNext(NULL);

	// curNode1�� curNode2 �� �ϳ��� �������� �ɶ����� �ݺ�
	while (curNode1 && curNode2) {
		// curNode2�� ����� ���ڿ��� �� Ŭ ���
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

	// ��� ��带 ���Ҵ��� Ȯ��. curNode1�� ��� Ž���� ���
	if (!curNode1) {
		while (curNode2) {
			curNode3->setNext(curNode2);
			curNode2 = curNode2->getNext();
			curNode3 = curNode3->getNext();
		}
	}
	else { // curNode2�� ��� Ž���� ���
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

	// ������ �������� ���ڿ��� �и��ϰ� ��忡 ����
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

	// ������ �������� ���ڿ��� �и��ϰ� ��忡 ����
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

	// ��带 �պ��ϰ� ����� ���
	Merge_List(p1, p2, p3);
	cout << endl << "Output>>" << endl << "Result: ";
	p3->print_all();

	// �޸� ����
	p1->deleteNodes();
	p2->deleteNodes();
	p3->deleteNodes();

	// ��ü ����
	delete p1;
	delete p2;
	delete p3;


	return 0;
}