#include <iostream>

using namespace std;

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
    ~Polynomial() {}

    void Insert(Term* pTerm);
    void PrintList();
    void Add(Polynomial& poly);
    void Sub(Polynomial& poly);
};

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

        int coeff = 0, exponent = 0, sign = 1;
        // coeffi의 부호 확인
        if (input[index] == '-') {
            sign = -1;
            index++;
        }
        else {
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

            // 이후 Exponent 판단
            while (input[index] >= '0' && input[index] <= '9') {
                exponent *= 10;
                exponent += input[index] - '0';
                index++;
            }

            if (!exponent)
                exponent++;
        }
        

        

        // 첫번째 다항식 저장
        Term* newTerm = new Term(coeff, exponent);
        Poly->Insert(newTerm);
    }
}


int main() {
    Polynomial* polynomial1 = new Polynomial;
    Polynomial* polynomial2 = new Polynomial;
    char temp[256]{};

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

    delete polynomial1;
    delete polynomial2;

    return 0;
}