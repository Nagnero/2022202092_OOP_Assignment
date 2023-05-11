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
        // �߰��� �뷡�� �������� �� �����̸�
        if (newSong->getTitle() > curNode->getTitle()) {
            prevNode = curNode;
            curNode = curNode->getNext();
        }
        else if (newSong->getTitle() < curNode->getTitle()) {
            // ù��° ���� �߰��ϴ� ���
            if (prevNode == NULL) {
                this->setFirst(newSong);
                newSong->setNext(curNode);
                return true;
            }
            // ù��° ���� �߰��ϴ°� �ƴ� ���
            else {
                prevNode->setNext(newSong);
                newSong->setNext(curNode);
                return true;
            }
            
        }
        // ������ �뷡 �߰��� ��� �ߺ����� ó��
        else {
            return true;
        } 
    } while (curNode);

    // ������ ���� �߰��ϴ� ���
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
    // ������ ������ �ʴ� ���
    if (!fin.is_open()) {
        cout << "Failed to open the file" << endl;
        return;
    }

    // ���پ� �о ó���ϱ� ���� ���� ����
    string input, temp_name, temp_song;
    int index = 0;
    getline(fin, input); // ù��°�� ����
    getline(fin, input); // ù��° ���� head������ ���� ���� ������
    // ���� �̸� ������
    while (input[index] != '/') {
        if (input[index] == '\t') {
            index++;
            continue;
        }
        // Artist ����
        temp_name += input[index++];
    }
    //temp_name += '\0';
    index++;
    // �� �̸� ������
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
    // ù��° ���Ʈ ����
    SongNode* newSong = new SongNode(temp_song);
    ArtistNode* newArtist = new ArtistNode(newSong, temp_name);
    newArtist->setNext(newArtist);
    this->setHead(newArtist);

    // ù��°�� ���� �߰�
    while (getline(fin, input)) {
        index = 0;
        temp_name = "";
        temp_song = "";
        // ���� �̸� ������
        while (input[index] != '/') {
            if (input[index] == '\t') {
                index++;
                continue;
            }
            // Artist ����
            temp_name += input[index++];
        }
        index++;
        // �� �̸� ������
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
        
        // �뷡 ������
        SongNode* newSong = new SongNode(temp_song);
        bool flag = false;
        // ���� �ߺ� Ȯ��
        ArtistNode* curNode = head;
        ArtistNode* lastNode = NULL;
        do {
            // �̹� ����� �������� �ƴϸ�
            if (curNode->getName() != temp_name) {
                lastNode = curNode;
                curNode = curNode->getNext();
            }
            // �̹� ����� �������̸�
            else {
                flag = curNode->addSong(newSong);
                break;
            }
        } while (curNode != head);

        // circular linked list ���� �� ���ĸ�
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

    // ���Ͽ��� �о�� ������ ���
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