#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
private:
	Node* nextNode;
	int data;

public:
	Node(int data) {
		this->nextNode = NULL;
		this->data = 0;
	}

	void setNext(Node* nextNode) { this->nextNode = nextNode; }
	void setData(int data) { this->data = data; }

	Node* getNext() { return this->nextNode; }
	int getData() { return this->data; }
};

class List {
private:
	Node* head;
	Node* tail;

public:
	List() {
		this->head = NULL;
	}

	void setHead(Node* head) { this->head = head; }
	Node* getHead() { return this->head; }

	void Insert(Node* nextNode);
};

void List::Insert(Node* nextNode) {
	// head가 있는 경우
	if (head) {
		tail->setNext(nextNode);
		tail = nextNode;
	}
	else {
		head = nextNode;
		tail = nextNode;
	}
}

Node* Binary_Search(Node* p, int n);

int main() {
	List* list = new List;

	srand(time(NULL));

	for (int i = 0; i < 16; i++) {
		Node* newNode = new Node(rand() % 201);
		list->Insert(newNode);
	}

	delete list;

	return 0;
}