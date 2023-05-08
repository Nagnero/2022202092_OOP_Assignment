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
    // 생성자로 private 변수 초기화
    myMusic() {
        this->m_title[0] = '\0'; // 곡 제목 초기화
        this->m_singer[0] = '\0'; // 가수 이름 초기화
        this->m_album[0] = '\0'; // 앨범 이름 초기화
        this->m_track_no = 0; // 트랙 번호 초기화
        this->m_year = 0; // 발매 연도 초기화
    }
    ~myMusic() {}

    void setTitle(char* title); // 곡 제목 설정 함수
    void setSinger(char* singer); // 가수 이름 설정 함수
    void setAlbum(char* album); // 앨범 이름 설정 함수
    void setTrackNo(int track_no) { this->m_track_no = track_no; } // 트랙 번호 설정 함수
    void setYear(int year) { this->m_year = year; } // 발매 연도 설정 함수

    char* getTitle() { return this->m_title; } // 곡 제목 반환 함수
    char* getSinger() { return this->m_singer; } // 가수 이름 반환 함수
    char* getAlbum() { return this->m_album; } // 앨범 이름 반환 함수
    int getYear() { return this->m_year; } // 발매 연도 반환 함수
    int getTrackNo() { return this->m_track_no; } // 트랙 번호 반환 함수
};

// title 저장 멤버함수
void myMusic::setTitle(char* title) {
    size_t len = strlen(title);
    len = (len > 31) ? 31 : len; // 최대 길이가 31인 문자열로 복사
    strncpy(this->m_title, title, len);
    this->m_title[len] = '\0'; // 문자열 마지막에 NULL 문자 추가
}

// 가수 저장 멤버함수
void myMusic::setSinger(char* singer) {
    size_t len = strlen(singer);
    len = (len > 31) ? 31 : len;
    strncpy(this->m_singer, singer, len);
    this->m_singer[len] = '\0';
}

// 앨범명 저장 멤버함수
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
    cin.getline(title, 32); // 문자열 입력 받기 (공백 포함)
    music.setTitle(title); // 곡 제목 설정

    // 이하 동일
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

    cout << endl << "Title: " << music.getTitle() << endl; // 곡 제목 출력
    cout << "Singer: " << music.getSinger() << endl; // 가수 이름 출력
    cout << "Album: " << music.getAlbum() << endl; // 앨범 이름 출력
    cout << "Track No.: " << music.getTrackNo() << endl; // 트랙 번호 출력
    cout << "Year: " << music.getYear() << endl; // 발매 연도 출력

    return 0;
}