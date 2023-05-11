#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SongNode {
private:
    SongNode* nextNode;
    string title;

public:
    SongNode(string title) {
        this->nextNode = NULL;
        this->title = title;
    }

    void setNext(SongNode* nextNode) { this->nextNode = nextNode; }
    SongNode* getNext() { return this->nextNode; }
    string getTitle() { return this->title; }
};


class ArtistNode {
private:
    ArtistNode* nextNode;
    SongNode* first;
    string name;

public:
    ArtistNode(SongNode* first, string name) {
        this->nextNode = NULL;
        this->first = first;
        this->name = name;
    }
    ~ArtistNode() {
        SongNode* curNode = first;
        SongNode* delNode = nullptr;

        while (curNode) {
            delNode = curNode;
            curNode = curNode->getNext();
            delete delNode;
        }
    }

    void setNext(ArtistNode* nextNode) { this->nextNode = nextNode; }
    void setFirst(SongNode* newNode) { this->first = newNode; }
    bool addSong(SongNode* newSong);

    ArtistNode* getNext() { return this->nextNode; }
    SongNode* getFirst() { return this->first; }
    string getName() { return this->name; }
};

bool ArtistNode::addSong(SongNode* newSong) {
    SongNode* curNode = this->getFirst();
    SongNode* prevNode = NULL;

    do {
        // 추가할 노래가 오름차순 상 뒤쪽이면
        if (newSong->getTitle() > curNode->getTitle()) {
            prevNode = curNode;
            curNode = curNode->getNext();
        }
        else if (newSong->getTitle() < curNode->getTitle()) {
            // 첫번째 노드로 추가하는 경우
            if (prevNode == NULL) {
                this->setFirst(newSong);
                newSong->setNext(curNode);
                return true;
            }
            // 첫번째 노드로 추가하는게 아닌 경우
            else {
                prevNode->setNext(newSong);
                newSong->setNext(curNode);
                return true;
            }
            
        }
        // 동일한 노래 추가인 경우 중복으로 처리
        else {
            return true;
        } 
    } while (curNode);

    // 마지막 노드로 추가하는 경우
    if (!curNode) {
        prevNode->setNext(newSong);
        return true;
    }

}


class MyMusicManagementList {
private:
    ArtistNode* head;

public:
    MyMusicManagementList() { head = NULL; }

    void setHead(ArtistNode* head) { this->head = head; }
    void loadFile(const char* filename);
    ArtistNode* getHead() { return this->head; }
};

void MyMusicManagementList::loadFile(const char* filename) {
    ifstream fin(filename);
    // 파일이 열리지 않는 경우
    if (!fin.is_open()) {
        cout << "Failed to open the file" << endl;
        return;
    }

    // 한줄씩 읽어서 처리하기 위한 변수 선언
    string input, temp_name, temp_song;
    int index = 0;
    getline(fin, input); // 첫번째줄 생략
    getline(fin, input); // 첫번째 가수 head설정을 위해 따로 빼내기
    // 가수 이름 따오기
    while (input[index] != '/') {
        if (input[index] == '\t') {
            index++;
            continue;
        }
        // Artist 저장
        temp_name += input[index++];
    }
    //temp_name += '\0';
    index++;
    // 곡 이름 따오기
    while (index < input.length()) {
        if(input[index] == '\t') {
            index++;
            continue;
        }
        if (input[index] >= 'A' && input[index] <= 'Z')
            temp_song += input[index++] - 'A' + 'a';
        else
            temp_song += input[index++];
    }
    //temp_song += '\0';
    // 첫번째 곡리스트 저장
    SongNode* newSong = new SongNode(temp_song);
    ArtistNode* newArtist = new ArtistNode(newSong, temp_name);
    newArtist->setNext(newArtist);
    this->setHead(newArtist);

    // 첫번째값 이후 추가
    while (getline(fin, input)) {
        index = 0;
        temp_name = "";
        temp_song = "";
        // 가수 이름 따오기
        while (input[index] != '/') {
            if (input[index] == '\t') {
                index++;
                continue;
            }
            // Artist 저장
            temp_name += input[index++];
        }
        index++;
        // 곡 이름 따오기
        while (index < input.length()) {
            if (input[index] == '\t') {
                index++;
                continue;
            }
            if (input[index] >= 'A' && input[index] <= 'Z')
                temp_song += input[index++] - 'A' + 'a';
            else
                temp_song += input[index++];
        }
        
        // 노래 노드생성
        SongNode* newSong = new SongNode(temp_song);
        bool flag = false;
        // 가수 중복 확인
        ArtistNode* curNode = head;
        ArtistNode* lastNode = NULL;
        do {
            // 이미 저장된 가수명이 아니면
            if (curNode->getName() != temp_name) {
                lastNode = curNode;
                curNode = curNode->getNext();
            }
            // 이미 저장된 가수명이면
            else {
                flag = curNode->addSong(newSong);
                break;
            }
        } while (curNode != head);

        // circular linked list 돌고 난 이후면
        if (curNode == head && !flag) {
            ArtistNode* newArtist = new ArtistNode(newSong, temp_name);
            newArtist->setNext(head);
            lastNode->setNext(newArtist);
        }
    }

    cout << "Music info loaded" << endl;
}

int main() {
    MyMusicManagementList List;
    string command;

    List.loadFile("Music_info.txt");

    // 파일에서 읽어온 데이터 출력
    ArtistNode* curArtistNode = List.getHead();
    do {
        cout << "Artist: " << curArtistNode->getName() << endl;
        SongNode* curSongNode = curArtistNode->getFirst();
        while (curSongNode) {
            cout << "\t - Song: " << curSongNode->getTitle() << endl;
            curSongNode = curSongNode->getNext();
        }
        curArtistNode = curArtistNode->getNext();
    } while (curArtistNode != List.getHead());


    return 0;
}