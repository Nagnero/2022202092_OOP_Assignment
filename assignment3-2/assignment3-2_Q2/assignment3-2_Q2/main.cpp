#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

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

int main() {
    myMusic music;

    char title[32], singer[32], album[32];
    int track_no, year;

    cout << "Enter music title: ";
    cin.getline(title, 32); // ���ڿ� �Է� �ޱ� (���� ����)
    music.setTitle(title); // �� ���� ����

    // ���� ����
    cout << "Enter singer name: ";
    cin.getline(singer, 32);
    music.setSinger(singer);

    cout << "Enter album title: ";
    cin.getline(album, 32);
    music.setAlbum(album);

    cout << "Enter track number: ";
    cin >> track_no;
    music.setTrackNo(track_no);

    cout << "Enter published year: ";
    cin >> year;
    music.setYear(year);

    cout << endl << "Title: " << music.getTitle() << endl; // �� ���� ���
    cout << "Singer: " << music.getSinger() << endl; // ���� �̸� ���
    cout << "Album: " << music.getAlbum() << endl; // �ٹ� �̸� ���
    cout << "Track No.: " << music.getTrackNo() << endl; // Ʈ�� ��ȣ ���
    cout << "Year: " << music.getYear() << endl; // �߸� ���� ���

    return 0;
}