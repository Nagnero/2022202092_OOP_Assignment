#include <iostream>

using namespace std;

// ���� �Ǵ�
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

// print ����Լ�
void Polynomial::PrintList() {
    Term* curNode = this->m_pHead;

    while (curNode) {
        int print_coeff = curNode->getCoeff();
        // ����� ��� + �ٿ��� ���
        if (print_coeff > 0)
            cout << '+';
        // ������ 0�� �ƴ� ���
        if (curNode->getExponent() != 0) {
            cout << print_coeff;
            cout << variable << "^";
            cout << curNode->getExponent();
            curNode = curNode->getNext();
        }
        // ������ 0�� ���
        else {
            cout << print_coeff;
            curNode = curNode->getNext();
        }
        cout << " ";
    }
    cout << endl;
}

// �� ����Լ�
void Polynomial::Add(Polynomial& poly) {
    // ����� �ӽ� ��ü ����
    Polynomial* tempPoly = new Polynomial;
    // Ž�� ��� ���� ����
    Term* cur1 = this->m_pHead;
    Term* cur2 = poly.m_pHead;

    while (cur1 && cur2) {
        // ������ ���� ���� ����
        if (cur1->getExponent() == cur2->getExponent()) {
            // ��� �ӽ� ���� ����
            int sum = cur1->getCoeff() + cur2->getCoeff();
            
            // ����� 0�� �ƴϸ� ����
            if (sum != 0) {
                Term* newTerm = new Term(sum, cur1->getExponent());
                tempPoly->Insert(newTerm);
            }            
            cur1 = cur1->getNext();
            cur2 = cur2->getNext();
        }
        // ù��° ���׽��� ������ �� ���� ���
        else if (cur1->getExponent() < cur2->getExponent()) {
            Term* newTerm = new Term(cur2->getCoeff(), cur2->getExponent());
            tempPoly->Insert(newTerm);
            cur2 = cur2->getNext();
        }
        // �ι�° ���׽��� ������ �� ���� ���
        else {
            Term* newTerm = new Term(cur1->getCoeff(), cur1->getExponent());
            tempPoly->Insert(newTerm);
            cur1 = cur1->getNext();
        }
    }
    // ù��° ���׽��� ��� ó���� ���
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

// �� ����Լ�
void Polynomial::Sub(Polynomial& poly) {
    // ����� �ӽ� ��ü ����
    Polynomial* tempPoly = new Polynomial;
    // Ž�� ��� ���� ����
    Term* cur1 = this->m_pHead;
    Term* cur2 = poly.m_pHead;

    while (cur1 && cur2) {
        // ������ ���� ���� ����
        if (cur1->getExponent() == cur2->getExponent()) {
            // ��� �ӽ� ���� ����
            int sub = cur1->getCoeff() - cur2->getCoeff();

            // ����� 0�� �ƴϸ� ����
            if (sub != 0) {
                Term* newTerm = new Term(sub, cur1->getExponent());
                tempPoly->Insert(newTerm);
            }
            cur1 = cur1->getNext();
            cur2 = cur2->getNext();
        }
        // ù��° ���׽��� ������ �� ���� ���
        else if (cur1->getExponent() < cur2->getExponent()) {
            Term* newTerm = new Term(-cur2->getCoeff(), cur2->getExponent());
            tempPoly->Insert(newTerm);
            cur2 = cur2->getNext();
        }
        // �ι�° ���׽��� ������ �� ���� ���
        else {
            Term* newTerm = new Term(cur1->getCoeff(), cur1->getExponent());
            tempPoly->Insert(newTerm);
            cur1 = cur1->getNext();
        }
    }
    // ù��° ���׽��� ��� ó���� ���
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

// ���� ����Լ� ����
void Polynomial::Insert(Term* pTerm) {
    // ù��° ��尡 �ƴ� ���
    if (this->m_pHead) {
        Term* curNode = this->m_pHead;
        // ������ ���� curNode �̵�
        while (curNode->getNext())
            curNode = curNode->getNext();

        curNode->setNext(pTerm);
    }
    else { // ù��° ����� ���
        this->m_pHead = pTerm;
    }
}

// ��ü�� ���׽� ���� �Լ�
void createPolynomial(char temp[], Polynomial* Poly) {

    char input[256]{};
    int index = 0, i = 0, j = 0;

    // �Է°����� ���� ����
    while (1) {
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

        int coeff = 0, exponent = 0, sign_coeff = 1, sign_expo = 1;
        // coeffi�� ��ȣ Ȯ��
        if (input[index] == '-') {
            sign_coeff = -1;
            index++;
        }
        else if (input[index] == '+') {
            index++;
        }

        // �տ������� coeff �Ǵ�
        // 1�� �����Ǿ� �ִ� ���
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

        // exponent Ȯ��. ������ ���ĺ��� ������ �ѱ��
        if (input[index] >= 'A' && input[index] <= 'z') {          
            index++;
            // ���� ^ �Է� ������ �ѱ��
            if (input[index] == '^')
                index++;

            // ������ ��ȣ �Ǵ�
            if (input[index] == '-') {
                sign_expo = -1;
                index++;
            }      

            // ���� Exponent �Ǵ�
            while (input[index] >= '0' && input[index] <= '9') {
                exponent *= 10;
                exponent += input[index] - '0';
                index++;
            }

            // ������ 0�̸� 1�� ����
            if (!exponent)
                exponent++;
        }        
        
        // ù��° ���׽� ����
        Term* newTerm = new Term(coeff * sign_coeff, exponent * sign_expo);
        Poly->Insert(newTerm);
    }
}


int main() {
    Polynomial* polynomial1 = new Polynomial;
    Polynomial* polynomial2 = new Polynomial;
    char temp[256]{};
    int command = 0;

    // ù��° ���׽� �Է�
    cout << "Enter first polynomial" << endl;
    cin.getline(temp, 256);
    // ù��° ���׽� ����
    createPolynomial(temp, polynomial1);


    // �ι�° ���׽� �Է�
    cout << "Enter second polynomial" << endl;
    cin.getline(temp, 256);
    // �ι�° ���׽� ����
    createPolynomial(temp, polynomial2);

    // � �������� �Ǵ��ϰ� ���� , �⺻�� x
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