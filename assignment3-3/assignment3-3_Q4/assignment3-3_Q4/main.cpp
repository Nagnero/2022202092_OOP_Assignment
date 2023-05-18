#include <iostream>

using namespace std;

// Score Ŭ���� ����
class Score {
private:
    Score* m_pNext;
    Score* m_pPrev;
    double m_Avg;

public:
    // ������
    Score() {
        this->m_pNext = NULL;
        this->m_pPrev = NULL;
        this->m_Avg = 0;
    }
    Score(double avg) {
        this->m_pNext = NULL;
        this->m_pPrev = NULL;
        this->m_Avg = avg;
    }

    // �� ��ҿ� ���� setter & getter
    void SetAvg(double avg) { this->m_Avg = avg; }
    void SetNext(Score* pNext) { this->m_pNext = pNext; }
    void SetPrev(Score* pPrev) { this->m_pPrev = pPrev; }
    double getAvr() { return this->m_Avg; }
    Score* GetNext() { return this->m_pNext; }
    Score* GetPrev() { return this->m_pPrev; }
};

// ���Ḯ��Ʈ ����
class StudentScoreList {
private:
    Score* m_pHead;
    Score* m_pTail;

public:
    // ������
    StudentScoreList() {
        this->m_pHead = NULL;
        this->m_pTail = NULL;
    }
    // �Ҹ���
    ~StudentScoreList() {
        Score* curNode = this->m_pHead;
        Score* delNode = NULL;

        while (curNode) {
            delNode = curNode;
            curNode = curNode->GetNext();
            delete delNode;
        }
    }

    void Insert(Score* pScore);
    void PrintList(bool isAscending);
};

// Insert ����Լ� ����
void StudentScoreList::Insert(Score* pScore) {
    // �߰��� ��Ұ� �̹� �ִ� ���
    if (this->m_pHead) {
        Score* curScore = this->m_pHead;

        while (curScore) {
            // ������ ����� ���� ���� ����� ������ ���� ��� ����
            if (pScore->getAvr() <= curScore->getAvr()) {
                // �߰��� �����ϴ� ���
                if (curScore != this->m_pHead) {
                    Score* tempScore = curScore->GetPrev();

                    tempScore->SetNext(pScore);
                    pScore->SetPrev(tempScore);
                    pScore->SetNext(curScore);
                    curScore->SetPrev(pScore);
                    break;
                }
                // �� �տ� �����ϴ� ���
                else {
                    this->m_pHead->SetPrev(pScore);
                    pScore->SetNext(m_pHead);
                    this->m_pHead = pScore;
                    break;
                }
            }
            // ������ ����� ���� ���� ����� ������ ũ�� ���� ���� �̵�
            else
                curScore = curScore->GetNext();
        }
        // �߰��̳� �տ� ���� ���ϰ� �ݺ����� ���� ��� �������� ����
        if (!curScore) {
            this->m_pTail->SetNext(pScore);
            pScore->SetPrev(m_pTail);
            this->m_pTail = pScore;
        }
    }
    // ù��° ��Ұ� �߰��� ���
    else {
        this->m_pHead = pScore;
        this->m_pTail = pScore;
    }
}

int main() {
    StudentScoreList* list = new StudentScoreList;
    double Math, Eng, Sci, average;
    int command;

    while (1) {
        cout << "Enter command (1.Insert 2.Print_ascending 3. Print_descending): ";
        cin >> command;

        if (command == 1) {
            cout << "Insert 3 score" << endl;
            cin >> Math >> Eng >> Sci;
            average = (Math + Eng + Sci) / 3;

            Score* newScore = new Score(average);
            list->Insert(newScore);
        }
    }

}