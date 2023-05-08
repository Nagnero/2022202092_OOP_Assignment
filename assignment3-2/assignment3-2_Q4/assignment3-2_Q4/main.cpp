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

// ���� ����Լ� ����
void Polynomial::Insert(Term* pTerm) {

}




int main() {
    Polynomial polynomial1, polynomial2;
    char input[256]{}, temp[256]{};
    int index = 0, i = 0, j = 0;

    cout << "Enter first polynomial" << endl;
    cin.getline(temp, 256);

    // �Է°����� ���� ����
    while (true) {   
        if (temp[j] == '\0' || j == 255) { // ���� ���ڳ� ���� ũ�� ���ѿ� ������ ���
            break; // �Է� ����
        }
        else if (temp[j] != ' ' && temp[j] != '\t') { // ���� ���ڰ� �ƴ� ���
            input[i++] = temp[j++]; // ���ڿ��� �߰�
        }
        else
            j++;
    }


    while (1) {
        // �ݺ��� Ż�� ����
        if (input[index] == '\0')
            break;
        else if (input[index] == ' ') { // �����̸� �ǳ� �ٱ�
            index++;
            continue;
        }
        
        int coeff = 0, exponent = 0, sign = 1;
        // coeffi�� ��ȣ Ȯ��
        if (input[index] == '-') {
            sign = -1;
            index++;
        }
        // �տ������� coeff �Ǵ�
        while (input[index] >= '0' && input[index] <= '9') {
            coeff *= 10;
            coeff += input[index] - '0';
            index++;
        }

        // exponent Ȯ��. ������ ���ĺ��� ������ �ѱ��
        if (input[index] >= 'A' && input[index] <= 'z') 
            index++;
        // ���� ^ �Է� ������ �ѱ��
        if (input[index] == '^')
            index++;

        // ���� Exponent �Ǵ�
        while (input[index] >= '0' && input[index] <= '9') {
            exponent *= 10;
            exponent += input[index] - '0';
            index++;
        }

    }

    return 0;
}