#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
private:
	Node* nextNode;
	Node* prevNode;
	int data;

public:
	Node(int data) {
		this->nextNode = NULL;
		this->prevNode = NULL;
		this->data = data;
	}

	void setNext(Node* nextNode) { this->nextNode = nextNode; }
	void setPrev(Node* prevNode) { this->prevNode = prevNode; }
	void setData(int data) { this->data = data; }

	Node* getNext() { return this->nextNode; }
	Node* getPrev() { return this->prevNode; }
	int getData() { return this->data; }

	void print_all_Node();
};

// ����� ��� ��� ��� ����Լ�
void Node::print_all_Node() {
	Node* curNode = this;

	while (curNode) {
		cout << curNode->getData() << " ";
		curNode = curNode->getNext();
	}
	cout << endl;
}

class List {
private:
	Node* head;
	Node* tail;

public:
	List() {
		this->head = NULL;
		this->tail = NULL;
	}
	~List() {
		Node* curNode = head;
		Node* delNode = NULL;

		while (curNode) {
			delNode = curNode;
			curNode = curNode->getNext();
			delete delNode;
		}
	}

	void setHead(Node* head) { this->head = head; }
	Node* getHead() { return this->head; }
	void setTail(Node* tail) { this->tail = tail; }
	Node* getTail() { return this->tail; }

	void Insert(Node* nextNode);
	bool checkDup(int data);
	void printAll();
};

void List::Insert(Node* nextNode) {
	// head�� �ִ� ���
	if (head) {
		tail->setNext(nextNode);
		nextNode->setPrev(tail);
		tail = nextNode;
	}
	else {
		head = nextNode;
		tail = nextNode;
	}
}

// �ݺ� Ȯ�� ����Լ�
bool List::checkDup(int data) {
	// ù��° ������ Ž��
	Node* curNode = this->head;

	while (curNode) {
		if (curNode->getData() == data)
			return false;

		curNode = curNode->getNext();
	}

	return true;
}

// ����Ʈ�� ��� ��� data ���
void List::printAll() {
	Node* curNode = this->getHead();

	while (curNode) {
		cout << curNode->getData() << " ";
		curNode = curNode->getNext();
	}
	cout << endl;
}

// ���� ��ġ �Լ�
Node* Binary_Search(Node* p, int n);
Node* Insertion_Sort(Node* p);

List* list = new List;

int main() {
	int n;

	srand(time(NULL));

	for (int i = 0; i < 16; i++) {
		int temp_data = rand() % 201;
		// �ݺ��Ǵ��� Ȯ���Ͽ� �ݺ����� ������ ������ �߰�
		if (list->checkDup(temp_data)) {
			Node* newNode = new Node(temp_data);
			list->Insert(newNode);
		}
		else { // �ݺ��ȴٸ� �ٽ� �ݺ��� �ٽ� �ݺ�
			i--;
		}		
	}

	// ���� ������ ���� ���
	cout << "--- Random creation ---" << endl;
	list->printAll();
	cout << endl << "Enter search value: ";
	cin >> n;

	Node* printNode = Binary_Search(list->getHead(), n);

	cout << endl;
	if (printNode->getData() == n) {
		cout << "Target found" << endl;
		cout << "Result: " << n;
	}
	else {
		cout << "Target not found" << endl;
		cout << "Nearest: ";
		// ���� ����� ���� head�� tail ����
		if (printNode == list->getHead() || printNode == list->getTail())
			cout << printNode->getData();
		else {
			int left, right;
			// ��ȯ���� ��尡 ã�� ������ Ŭ ���
			if (printNode->getData() > n) {
				left = printNode->getData();
				right = printNode->getNext()->getData();
			}
			// ��ȯ���� ��尡 ã�� ������ ���� ���
			else {
				left = printNode->getPrev()->getData();
				right = printNode->getData();
			}
			
			// ū ���� �� ����� ���
			if (n - left > right - n)
				cout << right;
			else
				cout << left;
		}
	}
	cout << endl;


	delete list;

	return 0;
}

Node* Binary_Search(Node* p, int n) {

	cout << endl << "Insertion sort process" << endl;
	// ���� �� list�� head ����
	list->setHead(Insertion_Sort(p));
	while (p) {
		list->setTail(p);
		p = p->getNext();
	}

	// ���� Ž�� ����
	cout << endl <<  "Binary Search: ";
	Node* left = list->getHead();
	Node* right = list->getTail();
	Node* mid = NULL;
	int low = 0, middle = 0, high = 0;
	bool first = true;
	// ���� ī��Ʈ
	Node* tempNode = left;
	while (tempNode != right) {
		tempNode = tempNode->getNext();
		high++;
	}


	while (high > low) {
		middle = (high + low) / 2;
		if (!first)
			cout << " -> ";
		else
			first = false;
		// ��� ��� ����
		tempNode = left;
		for (int i = low; i < middle; i++)
			tempNode = tempNode->getNext();
		mid = tempNode;
		cout << mid->getData();

		// ��ġ ����
		if (mid->getData() == n) {
			return mid;
		}
		// �߰� ��尪�� ã�� ������ Ŭ ���
		else if (mid->getData() > n && mid != list->getTail()) {
			low = middle + 1;
			left = mid->getNext();
		}
		// �߰� ��尪�� ã�� ������ ���� ���
		else if (mid->getData() < n && mid != list->getHead()) {
			high = middle - 1;
			right = mid->getPrev();
		}
	}

	if (high == low) {
		return left;
	}

	return mid;
}

Node* Insertion_Sort(Node* p) {
	// ���̳ʸ� ��ġ�� �����ϱ� �� ���� ����
	Node* head = p;
	Node* curNode = p->getNext(); // �񱳸� ������ ����

	while (curNode) {
		bool changed = false;
		Node* nextNode = curNode->getNext();
		Node* compare = head; // �񱳸� ������ ���
		while (compare != curNode) {
			// ���� �����Ͱ� �� ũ�� �տ� �����ֱ�
			if (compare->getData() < curNode->getData()) {
				// curNode �ű�� �� �� �� ��� ����
				// curNode�� �������� �ƴ� ���
				if (curNode->getNext()) {
					Node* tempNode = curNode->getPrev();
					tempNode->setNext(curNode->getNext());
					curNode->getNext()->setPrev(tempNode);
				}
				// curNode�� �������� ���
				else {
					curNode->getPrev()->setNext(NULL);
					// curNode�� prev�� ���� ���� ����
				}

				// curNode �ű� �� �� �� ��� ����
				// �ű� �ڸ��� �� ���� �ƴ� ���
				if (compare != head) {
					Node* tempNode = compare->getPrev();
					tempNode->setNext(curNode);
					curNode->setPrev(tempNode);
					curNode->setNext(compare);
					compare->setPrev(curNode);
				}
				// �ű� �ڸ��� �� ���� ���
				else {
					head = curNode;
					curNode->setNext(compare);
					compare->setPrev(curNode);
					curNode->setPrev(NULL);
				}
				changed = true;
				break;
			}

			compare = compare->getNext();
		}
		if (changed)
			head->print_all_Node();

		curNode = nextNode;
	}

	return head;
}