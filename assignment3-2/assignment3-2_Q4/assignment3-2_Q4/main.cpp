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

// »ğÀÔ ¸â¹öÇÔ¼ö Á¤ÀÇ
void Polynomial::Insert(Term* pTerm) {

}


int main() {
    Polynomial polynomial1, polynomial2;
}