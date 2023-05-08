#include <iostream>

using namespace std;

class Term {
private:
    int m_Coefficient;
    int m_Exponent;
    Term* m_pNext;

public:
    Term() {
        this->m_Coefficient = 0;
        this->m_Exponent = 0;
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

}




int main() {
    Polynomial polynomial1, polynomial2;
    char input[256]{}, temp[256]{};
    int index = 0, i = 0, j = 0;

    cout << "Enter first polynomial" << endl;
    cin.getline(temp, 256);

    // 입력값에서 공백 제거
    while (true) {   
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
        // 앞에서부터 coeff 판단
        while (input[index] >= '0' && input[index] <= '9') {
            coeff *= 10;
            coeff += input[index] - '0';
            index++;
        }

        // exponent 확인. 변수로 알파벳을 받으면 넘기기
        if (input[index] >= 'A' && input[index] <= 'z') 
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

    }

    return 0;
}