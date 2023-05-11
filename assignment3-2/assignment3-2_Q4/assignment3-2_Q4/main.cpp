#include <iostream>

using namespace std;

// 변수 판단
char variable = 'x';

class Term {
private:
    int m_Coefficient;
    int m_Exponent;
    Term* m_pNext;

public:
    Term(int coeff, int exponent) {
        this->m_Coefficient = coeff;
        this->m_Exponent = exponent;
        this->m_pNext = NULL;
    }
    ~Term() {}

    void setCoeffi(int coeff) { this->m_Coefficient = 0; }
    void setExponent(int exponent) { this->m_Exponent = 0; }
    void setNext(Term* pNext) { this->m_pNext = pNext; }

    int getCoeff() { return this->m_Coefficient; }
    int getExponent() { return this->m_Exponent; }
    Term* getNext() { return this->m_pNext; }
};

class Polynomial {
private:
    Term* m_pHead;

public:
    Polynomial() {
        this->m_pHead = NULL;
    }
    ~Polynomial() {
        Term* curNode = m_pHead;
        Term* delNode = nullptr;

        while (curNode) {
            delNode = curNode;
            curNode = curNode->getNext();
            delete delNode;
        }
    }

    void Insert(Term* pTerm);
    void PrintList();
    void Add(Polynomial& poly);
    void Sub(Polynomial& poly);
};

// print 멤버함수
void Polynomial::PrintList() {
    Term* curNode = this->m_pHead;

    while (curNode) {
        int print_coeff = curNode->getCoeff();
        // 양수인 경우 + 붙여서 출력
        if (print_coeff > 0)
            cout << '+';
        // 지수가 0이 아닌 경우
        if (curNode->getExponent() != 0) {
            cout << print_coeff;
            cout << variable << "^";
            cout << curNode->getExponent();
            curNode = curNode->getNext();
        }
        // 지수가 0인 경우
        else {
            cout << print_coeff;
            curNode = curNode->getNext();
        }
        cout << " ";
    }
    cout << endl;
}

// 합 멤버함수
void Polynomial::Add(Polynomial& poly) {
    // 출력할 임시 객체 선언
    Polynomial* tempPoly = new Polynomial;
    // 탐색 노드 각각 선언
    Term* cur1 = this->m_pHead;
    Term* cur2 = poly.m_pHead;

    while (cur1 && cur2) {
        // 지수가 같은 값에 대해
        if (cur1->getExponent() == cur2->getExponent()) {
            // 계수 임시 저장 변수
            int sum = cur1->getCoeff() + cur2->getCoeff();
            
            // 계수가 0이 아니면 저장
            if (sum != 0) {
                Term* newTerm = new Term(sum, cur1->getExponent());
                tempPoly->Insert(newTerm);
            }            
            cur1 = cur1->getNext();
            cur2 = cur2->getNext();
        }
        // 첫번째 다항식의 지수가 더 작은 경우
        else if (cur1->getExponent() < cur2->getExponent()) {
            Term* newTerm = new Term(cur2->getCoeff(), cur2->getExponent());
            tempPoly->Insert(newTerm);
            cur2 = cur2->getNext();
        }
        // 두번째 다항식의 지수가 더 작은 경우
        else {
            Term* newTerm = new Term(cur1->getCoeff(), cur1->getExponent());
            tempPoly->Insert(newTerm);
            cur1 = cur1->getNext();
        }
    }
    // 첫번째 다항식을 모두 처리한 경우
    if (!cur1) {
        while (cur2) {
            Term* newTerm = new Term(cur2->getCoeff(), cur2->getExponent());
            tempPoly->Insert(newTerm);
            cur2 = cur2->getNext();
        }
    }
    else if (!cur2) {
        while (cur1) {
            Term* newTerm = new Term(cur1->getCoeff(), cur1->getExponent());
            tempPoly->Insert(newTerm);
            cur1 = cur1->getNext();
        }
    }

    tempPoly->PrintList();

    delete tempPoly;
}

// 차 멤버함수
void Polynomial::Sub(Polynomial& poly) {
    // 출력할 임시 객체 선언
    Polynomial* tempPoly = new Polynomial;
    // 탐색 노드 각각 선언
    Term* cur1 = this->m_pHead;
    Term* cur2 = poly.m_pHead;

    while (cur1 && cur2) {
        // 지수가 같은 값에 대해
        if (cur1->getExponent() == cur2->getExponent()) {
            // 계수 임시 저장 변수
            int sub = cur1->getCoeff() - cur2->getCoeff();

            // 계수가 0이 아니면 저장
            if (sub != 0) {
                Term* newTerm = new Term(sub, cur1->getExponent());
                tempPoly->Insert(newTerm);
            }
            cur1 = cur1->getNext();
            cur2 = cur2->getNext();
        }
        // 첫번째 다항식의 지수가 더 작은 경우
        else if (cur1->getExponent() < cur2->getExponent()) {
            Term* newTerm = new Term(-cur2->getCoeff(), cur2->getExponent());
            tempPoly->Insert(newTerm);
            cur2 = cur2->getNext();
        }
        // 두번째 다항식의 지수가 더 작은 경우
        else {
            Term* newTerm = new Term(cur1->getCoeff(), cur1->getExponent());
            tempPoly->Insert(newTerm);
            cur1 = cur1->getNext();
        }
    }
    // 첫번째 다항식을 모두 처리한 경우
    if (!cur1) {
        while (cur2) {
            Term* newTerm = new Term(-cur2->getCoeff(), cur2->getExponent());
            tempPoly->Insert(newTerm);
            cur2 = cur2->getNext();
        }
    }
    else if (!cur2) {
        while (cur1) {
            Term* newTerm = new Term(cur1->getCoeff(), cur1->getExponent());
            tempPoly->Insert(newTerm);
            cur1 = cur1->getNext();
        }
    }

    tempPoly->PrintList();

    delete tempPoly;
}

// 삽입 멤버함수 정의
void Polynomial::Insert(Term* pTerm) {
    // 첫번째 노드가 아닌 경우
    if (this->m_pHead) {
        Term* curNode = this->m_pHead;
        // 마지막 노드로 curNode 이동
        while (curNode->getNext())
            curNode = curNode->getNext();

        curNode->setNext(pTerm);
    }
    else { // 첫번째 노드인 경우
        this->m_pHead = pTerm;
    }
}

// 객체에 다항식 저장 함수
void createPolynomial(char temp[], Polynomial* Poly) {

    char input[256]{};
    int index = 0, i = 0, j = 0;

    // 입력값에서 공백 제거
    while (1) {
        if (temp[j] == '\0' || j == 255) { // 개행 문자나 버퍼 크기 제한에 도달한 경우
            break; // 입력 종료
        }
        else if (temp[j] != ' ' && temp[j] != '\t') { // 공백 문자가 아닌 경우
            input[i++] = temp[j++]; // 문자열에 추가
        }
        else
            j++;
    }

    while (1) {
        // 반복문 탈출 조건
        if (input[index] == '\0')
            break;
        else if (input[index] == ' ') { // 공백이면 건너 뛰기
            index++;
            continue;
        }

        int coeff = 0, exponent = 0, sign_coeff = 1, sign_expo = 1;
        // coeffi의 부호 확인
        if (input[index] == '-') {
            sign_coeff = -1;
            index++;
        }
        else if (input[index] == '+') {
            index++;
        }

        // 앞에서부터 coeff 판단
        // 1이 생략되어 있는 경우
        if (input[index] >= 'A' && input[index] <= 'z') {
            coeff = 1;
        }
        else {
            while (input[index] >= '0' && input[index] <= '9') {
                coeff *= 10;
                coeff += input[index] - '0';
                index++;
            }
        }

        // exponent 확인. 변수로 알파벳을 받으면 넘기기
        if (input[index] >= 'A' && input[index] <= 'z') {          
            index++;
            // 지수 ^ 입력 받으면 넘기기
            if (input[index] == '^')
                index++;

            // 지수의 부호 판단
            if (input[index] == '-') {
                sign_expo = -1;
                index++;
            }      

            // 이후 Exponent 판단
            while (input[index] >= '0' && input[index] <= '9') {
                exponent *= 10;
                exponent += input[index] - '0';
                index++;
            }

            // 지수가 0이면 1로 증가
            if (!exponent)
                exponent++;
        }        
        
        // 첫번째 다항식 저장
        Term* newTerm = new Term(coeff * sign_coeff, exponent * sign_expo);
        Poly->Insert(newTerm);
    }
}


int main() {
    Polynomial* polynomial1 = new Polynomial;
    Polynomial* polynomial2 = new Polynomial;
    char temp[256]{};
    int command = 0;

    // 첫번째 다항식 입력
    cout << "Enter first polynomial" << endl;
    cin.getline(temp, 256);
    // 첫번째 다항식 저장
    createPolynomial(temp, polynomial1);


    // 두번째 다항식 입력
    cout << "Enter second polynomial" << endl;
    cin.getline(temp, 256);
    // 두번째 다항식 저장
    createPolynomial(temp, polynomial2);

    // 어떤 변수인지 판단하고 저장 , 기본은 x
    for (int i = 0; i < 256; i++)
        if (temp[i] >= 'A' && temp[i] <= 'z') {
            variable = temp[i];
            break;
        }


    while (1) {
        cout << "Enter command (1.Add, 2.Subtract, else.exit): ";
        cin >> command;

        if (command == 1)
            polynomial1->Add(*polynomial2);
        else if (command == 2)
            polynomial1->Sub(*polynomial2);
        else
            break;
    }

    delete polynomial1;
    delete polynomial2;

    return 0;
}