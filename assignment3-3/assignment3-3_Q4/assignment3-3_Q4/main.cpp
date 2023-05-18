#include <iostream>

using namespace std;

// Score 클래스 정의
class Score {
private:
    Score* m_pNext;
    Score* m_pPrev;
    double m_Avg;

public:
    // 생성자
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

    // 각 요소에 대한 setter & getter
    void SetAvg(double avg) { this->m_Avg = avg; }
    void SetNext(Score* pNext) { this->m_pNext = pNext; }
    void SetPrev(Score* pPrev) { this->m_pPrev = pPrev; }
    double getAvr() { return this->m_Avg; }
    Score* GetNext() { return this->m_pNext; }
    Score* GetPrev() { return this->m_pPrev; }
};

// 연결리스트 정의
class StudentScoreList {
private:
    Score* m_pHead;
    Score* m_pTail;

public:
    // 생성자
    StudentScoreList() {
        this->m_pHead = NULL;
        this->m_pTail = NULL;
    }
    // 소멸자
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

// Insert 멤버함수 구현
void StudentScoreList::Insert(Score* pScore) {
    // 추가된 요소가 이미 있는 경우
    if (this->m_pHead) {
        Score* curScore = this->m_pHead;

        while (curScore) {
            // 삽입할 노드의 값이 현재 노드의 값보다 작을 경우 삽입
            if (pScore->getAvr() <= curScore->getAvr()) {
                // 중간에 삽입하는 경우
                if (curScore != this->m_pHead) {
                    Score* tempScore = curScore->GetPrev();

                    tempScore->SetNext(pScore);
                    pScore->SetPrev(tempScore);
                    pScore->SetNext(curScore);
                    curScore->SetPrev(pScore);
                    break;
                }
                // 맨 앞에 삽입하는 경우
                else {
                    this->m_pHead->SetPrev(pScore);
                    pScore->SetNext(m_pHead);
                    this->m_pHead = pScore;
                    break;
                }
            }
            // 삽입할 노드의 값이 현재 노드의 값보다 크면 다음 노드로 이동
            else
                curScore = curScore->GetNext();
        }
        // 중간이나 앞에 삽입 못하고 반복문을 나온 경우 마지막에 삽입
        if (!curScore) {
            this->m_pTail->SetNext(pScore);
            pScore->SetPrev(m_pTail);
            this->m_pTail = pScore;
        }
    }
    // 첫번째 요소가 추가될 경우
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