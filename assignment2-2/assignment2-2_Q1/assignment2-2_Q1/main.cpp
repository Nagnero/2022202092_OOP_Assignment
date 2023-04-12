#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	string data = "";
	struct Node* next = nullptr;
	struct Node* d_next = nullptr;
	struct Node* prev = nullptr;
} Node;



int main() {
	string input, temp;

	cin >> input;

	// 첫번째는 항상 [로 시작되므로 조건문 생략하고 시작 노드 생성
	Node* head = new Node;
	Node* curNode = head;

	// 입력받은 문자열을 리스트에 저장하는 반복문
	for (int i = 1; i < input.length(); i++) {
		// 새로운 리스트 선언
		if (input[i] == '[') {
			Node* newNode = new Node;
			
		}
		// 콤마를 만나면 temp를 배열에 저장
		else if (input[i] == ',') {
			i++; // comma뒤에 항상 공백이 오기 때문
			Node* newNode = new Node;

			if (temp == "") { // 빈 문자열이면 그대로 리스트 추가

			}
		}
		// 리스트 나가기
		else if (input[i] == ']') {

		}
		// 문자열의 요소면
		else {
			// 삽입할 문자열이 빈 것이면
			
			temp.push_back(input[i]);
		}
	}


	delete head;
}