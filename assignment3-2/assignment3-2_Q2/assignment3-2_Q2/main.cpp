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
    // 생성자로 private 변수 초기화
    myMusic() {
        this->m_title[0] = '\0';
        this->m_singer[0] = '\0';
        this->m_album[0] = '\0';
        this->m_track_no = 0;
        this->m_year = 0;
    }
    ~myMusic() {}

    void setTitle(char* title);
    void setSinger(char* singer);
    void setAlbum(char* album);
    void setTrackNo(int track_no) { this->m_track_no = track_no; }
    void setYear(int year) { this->m_year = year; }

    char* getTitle() { return this->m_title; }
    char* getSinger() { return this->m_singer; }
    char* getAlbum() { return this->m_album; }
    int getYear() { return this->m_year; }
    int getTrackNo() { return this->m_track_no; }
};

void myMusic::setTitle(char* title) {
    size_t len = strlen(title);
    len = (len > 31) ? 31 : len;
    strncpy(this->m_title, title, len);
    this->m_title[len] = '\0';
}

void myMusic::setSinger(char* singer) {
    size_t len = strlen(singer);
    len = (len > 31) ? 31 : len;
    strncpy(this->m_singer, singer, len);
    this->m_singer[len] = '\0';
}

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
    cin.getline(title, 32);
    music.setTitle(title);

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

    cout << endl << "Title: " << music.getTitle() << endl;
    cout << "Singer: " << music.getSinger() << endl;
    cout << "Album: " << music.getAlbum() << endl;
    cout << "Track No.: " << music.getTrackNo() << endl;
    cout << "Year: " << music.getYear() << endl;

    return 0;
}