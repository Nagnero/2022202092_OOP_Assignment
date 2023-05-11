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

// 연결된 모드 노드 출력 멤버함수
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
	// head가 있는 경우
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

// 반복 확인 멤버함수
bool List::checkDup(int data) {
	// 첫번째 노드부터 탐색
	Node* curNode = this->head;

	while (curNode) {
		if (curNode->getData() == data)
			return false;

		curNode = curNode->getNext();
	}

	return true;
}

// 리스트의 모든 노드 data 출력
void List::printAll() {
	Node* curNode = this->getHead();

	while (curNode) {
		cout << curNode->getData() << " ";
		curNode = curNode->getNext();
	}
	cout << endl;
}

// 이진 서치 함수
Node* Binary_Search(Node* p, int n);
Node* Insertion_Sort(Node* p);

List* list = new List;

int main() {
	int n;

	srand(time(NULL));

	for (int i = 0; i < 16; i++) {
		int temp_data = rand() % 201;
		// 반복되는지 확인하여 반복되지 않으면 데이터 추가
		if (list->checkDup(temp_data)) {
			Node* newNode = new Node(temp_data);
			list->Insert(newNode);
		}
		else { // 반복된다면 다시 반복문 다시 반복
			i--;
		}		
	}

	// 랜덤 생성한 수열 출력
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
		// 가장 가까운 값이 head나 tail 노드면
		if (printNode == list->getHead() || printNode == list->getTail())
			cout << printNode->getData();
		else {
			int left, right;
			// 반환받은 노드가 찾는 값보다 클 경우
			if (printNode->getData() > n) {
				left = printNode->getData();
				right = printNode->getNext()->getData();
			}
			// 반환받은 노드가 찾는 값보다 작은 경우
			else {
				left = printNode->getPrev()->getData();
				right = printNode->getData();
			}
			
			// 큰 값이 더 가까울 경우
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
	// 정렬 후 list의 head 변경
	list->setHead(Insertion_Sort(p));
	while (p) {
		list->setTail(p);
		p = p->getNext();
	}

	// 이진 탐색 시작
	cout << endl <<  "Binary Search: ";
	Node* left = list->getHead();
	Node* right = list->getTail();
	Node* mid = NULL;
	int low = 0, middle = 0, high = 0;
	bool first = true;
	// 길이 카운트
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
		// 가운데 노드 저장
		tempNode = left;
		for (int i = low; i < middle; i++)
			tempNode = tempNode->getNext();
		mid = tempNode;
		cout << mid->getData();

		// 서치 성공
		if (mid->getData() == n) {
			return mid;
		}
		// 중간 노드값이 찾는 값보다 클 경우
		else if (mid->getData() > n && mid != list->getTail()) {
			low = middle + 1;
			left = mid->getNext();
		}
		// 중간 노드값이 찾는 값보다 작을 경우
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
	// 바이너리 서치를 진행하기 전 정렬 진행
	Node* head = p;
	Node* curNode = p->getNext(); // 비교를 진행할 기준

	while (curNode) {
		bool changed = false;
		Node* nextNode = curNode->getNext();
		Node* compare = head; // 비교를 진행할 대상
		while (compare != curNode) {
			// 기준 데이터가 더 크면 앞에 끼워넣기
			if (compare->getData() < curNode->getData()) {
				// curNode 옮기기 전 앞 뒤 노드 수정
				// curNode가 마지막이 아닌 경우
				if (curNode->getNext()) {
					Node* tempNode = curNode->getPrev();
					tempNode->setNext(curNode->getNext());
					curNode->getNext()->setPrev(tempNode);
				}
				// curNode가 마지막인 경우
				else {
					curNode->getPrev()->setNext(NULL);
					// curNode의 prev는 이후 수정 예정
				}

				// curNode 옮긴 후 앞 뒤 노드 수정
				// 옮긴 자리가 맨 앞이 아닌 경우
				if (compare != head) {
					Node* tempNode = compare->getPrev();
					tempNode->setNext(curNode);
					curNode->setPrev(tempNode);
					curNode->setNext(compare);
					compare->setPrev(curNode);
				}
				// 옮긴 자리가 맨 앞인 경우
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