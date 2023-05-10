#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class myMusic {
private:
    char m_title[32];
    char m_singer[32];
    char m_album[32];
    int m_track_no;
    int m_year;

public:
    // �����ڷ� private ���� �ʱ�ȭ
    myMusic() {
        this->m_title[0] = '\0'; // �� ���� �ʱ�ȭ
        this->m_singer[0] = '\0'; // ���� �̸� �ʱ�ȭ
        this->m_album[0] = '\0'; // �ٹ� �̸� �ʱ�ȭ
        this->m_track_no = 0; // Ʈ�� ��ȣ �ʱ�ȭ
        this->m_year = 0; // �߸� ���� �ʱ�ȭ
    }
    ~myMusic() {}

    void setTitle(char* title); // �� ���� ���� �Լ�
    void setSinger(char* singer); // ���� �̸� ���� �Լ�
    void setAlbum(char* album); // �ٹ� �̸� ���� �Լ�
    void setTrackNo(int track_no) { this->m_track_no = track_no; } // Ʈ�� ��ȣ ���� �Լ�
    void setYear(int year) { this->m_year = year; } // �߸� ���� ���� �Լ�

    char* getTitle() { return this->m_title; } // �� ���� ��ȯ �Լ�
    char* getSinger() { return this->m_singer; } // ���� �̸� ��ȯ �Լ�
    char* getAlbum() { return this->m_album; } // �ٹ� �̸� ��ȯ �Լ�
    int getYear() { return this->m_year; } // �߸� ���� ��ȯ �Լ�
    int getTrackNo() { return this->m_track_no; } // Ʈ�� ��ȣ ��ȯ �Լ�
};

// title ���� ����Լ�
void myMusic::setTitle(char* title) {
    size_t len = strlen(title);
    len = (len > 31) ? 31 : len; // �ִ� ���̰� 31�� ���ڿ��� ����
    strncpy(this->m_title, title, len);
    this->m_title[len] = '\0'; // ���ڿ� �������� NULL ���� �߰�
}

// ���� ���� ����Լ�
void myMusic::setSinger(char* singer) {
    size_t len = strlen(singer);
    len = (len > 31) ? 31 : len;
    strncpy(this->m_singer, singer, len);
    this->m_singer[len] = '\0';
}

// �ٹ��� ���� ����Լ�
void myMusic::setAlbum(char* album) {
    size_t len = strlen(album);
    len = (len > 31) ? 31 : len;
    strncpy(this->m_album, album, len);
    this->m_album[len] = '\0';
}

char* checkSpace(char* input);
int change_to_int(char* input);

int main() {
    myMusic music;

    char input[128], track_no[10], year[10];
    char* token;


    cin.getline(input, 128);
    
    token = strtok(input, ",");
    music.setTitle(checkSpace(token));

    token = strtok(NULL, ",");
    music.setSinger(checkSpace(token));

    token = strtok(NULL, ",");
    music.setAlbum(checkSpace(token));

    token = strtok(NULL, ",");
    strcpy(track_no, checkSpace(token));
    music.setTrackNo(change_to_int(track_no));

    token = strtok(NULL, ",");
    strcpy(year, checkSpace(token));
    music.setYear(change_to_int(year));

    cout << endl << "Title: " << music.getTitle() << endl; // �� ���� ���
    cout << "Singer: " << music.getSinger() << endl; // ���� �̸� ���
    cout << "Album: " << music.getAlbum() << endl; // �ٹ� �̸� ���
    cout << "Track No.: " << music.getTrackNo() << endl; // Ʈ�� ��ȣ ���
    cout << "Year: " << music.getYear() << endl; // �߸� ���� ���

    return 0;
}

char* checkSpace(char* input) {
    int j = 0, i = 0;
    char temp[32]{};

    // �޸� �ڿ� �������
    for (; input[i] == ' '; i++);

    while (input[i]) {
        temp[j++] = input[i++];
    }


    return temp;
}

int change_to_int(char* input) {
    int temp = 0;

    for (int i = 0; input[i]; i++) {
        temp *= 10;
        temp += input[i] - '0';
    }

    return temp;
}