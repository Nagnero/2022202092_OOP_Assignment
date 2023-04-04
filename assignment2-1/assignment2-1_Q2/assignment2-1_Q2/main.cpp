#include <iostream>

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
	void setValue(int input) { this->value = input; };
	int getValue() { return this->value; };
	void setNext(Node* nextNode) { this->next = nextNode; };
	Node* getNext() { return this->next; };
	void setPrev(Node* prevNode) { this->prev = prevNode; };
	Node* getPrev() { return this->prev; };
};

class Queue {
private:
	Node* first;
	Node* last;
	int size;
	
public:
	Queue() {
		this->first = NULL;
		this->last = NULL;
		this->size = 0;
	}
	void push(int data);
	void pop();
	bool isEmpty();
};

void Queue::push(int data) {
	Node* newNode = new Node;
	newNode->setValue(data);

	if (!(isEmpty())) { // 큐가 비어있지 않다면
		last->setPrev(newNode);
		newNode->setNext(last);
		last = newNode;
		this->size++;
	}
	else {
		first = last = newNode;
		this->size++;
	}
}

void Queue::pop() {
	if (isEmpty()) {
		cout << "already empty";
	}
	else {
		if (this->size != 1) { // 큐에 요소가 2개 이상이면
			Node* delNode = first;
			first = first->getPrev();
			delete delNode;
			first->setNext(NULL);
			this->size--;
		}
		else { // 큐에 요소가 1개면
			delete first;
			first = NULL;
			last = NULL;
			this->size--;
		}
	}
}

bool Queue::isEmpty() {
	if (this->size == 0)
		return 1;
	else
		return 0;
}


int main() {
	int row, col, i, j, x1, x2, y1, y2, cnt=1;

	cin >> row >> col;

	char** maze = new char* [row];
	for (i = 0; i < col; i++)
		maze[i] = new char[col];

	for (i = 0; i < row; i++) {
		cin >> maze[i];
	}

	cin >> x1 >> y1 >> x2 >> y2;




	for (i = 0; i < col; i++)
		delete[] maze[i];
	
	delete[] maze;

	return 0;
}