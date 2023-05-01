#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	Node* head;
	Node* nextNode;
	string data;

public:
	Node() {
		this->head = NULL;
		this->nextNode = NULL;
		data = "";
	}
	~Node() {
		
	}

	void setNext(Node* nextNode) { this->nextNode = nextNode; }
	Node* getNext() { return this->nextNode; }
	void setData(string data);
	string getData() { return this->data; }

};

void Node::setData(string data) {
	if (head == NULL) { // 값이 없는 경우
		this->head->setData(data);
	}
}

int main() {
	Node* p1 = new Node;
	string input, temp;

	cout << "Input>>" << endl << "Input list 1: ";
	getline(cin, input);
	for (int i = 0; input[i]; i++) {
		if (input[i] = ' ') {
			Node* newNode = new Node;
			p1->setNext(newNode);
			newNode->setData(temp);
			temp = "";
		}
		temp += input[i];
	}

}