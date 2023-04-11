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
	string getStr() { return this->str; }
	void setNext(Node* nextNode) { this->next = nextNode; }
	Node* getNext() { return this->next; }
};


int main() {
	int start = 0, end = 0;
	string input;
	Node* arr = new Node;

	getline(cin, input);

	for (int i = 0; i < input.length(); i++) {
		if (input[i] = '[') { // 배열의 시작을 알리면
			start++;
			Node* newNode = new Node;

		}
	}

	delete arr;
}