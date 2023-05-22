#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Person {
protected:
	int age;
	char name[32];

public:
	Person() {
		this->age = 0;
		this->name[0] = '\0';
	}
	virtual void Say()=0;
};

class Student :public Person {
protected:
	char studentNum[11];
	char major[32];
	int schoolYear;

public:
	Student() {
		this->studentNum[0] = '\0';
		this->major[0] = '\0';
		this->schoolYear = 0;
	}

	// setter들 정의
	void setAge(int age) { this->age = age; }
	void setName(const char* name);
	void setStudentNum(const char* studentNum);
	void setMajor(const char* major);
	void setSchoolYear(int schoolYear) { this->schoolYear = schoolYear; }

	// getter들 정의
	int getAge() { return this->age; }
	char* getName() { return this->name; }
	char* getStudentNum() { return this->studentNum; }
	char* getmajor() { return this->major; }
	int getSchoolYear() { return this->schoolYear; }

	void Say();
};

void Student::setName(const char* name) {
	strncpy(this->name, name, sizeof(this->name) - 1);
	this->name[sizeof(this->name) - 1] = '\0'; // 문자열 끝을 명시적으로 설정
}

void Student::setStudentNum(const char* studentNum) {
	strncpy(this->studentNum, studentNum, sizeof(this->studentNum) - 1);
	this->studentNum[sizeof(this->studentNum) - 1] = '\0'; // 문자열 끝을 명시적으로 설정
}

void Student::setMajor(const char* major) {
	strncpy(this->major, major, sizeof(this->major) - 1);
	this->major[sizeof(this->major) - 1] = '\0'; // 문자열 끝을 명시적으로 설정
}

void Student::Say() {
	cout << "I'm a student of KW University." << endl;
	cout << "My name is " << this->getName() << "." << endl;
	cout << "I'm " << this->getAge() << "years old and I'm a ";
	switch (this->getSchoolYear()) {
	case 1:
		cout << "Freshman." << endl;
		break;
	case 2:
		cout << "Sophomore." << endl;
		break;
	case 3:
		cout << "Junior." << endl;
		break;
	case 4:
		cout << "Senior." << endl;
		break;
	}
	cout << "I'm majoring in " << this->getmajor() << "." << endl;
	cout << "My student ID is " << this->getStudentNum() << "." << endl;

}

class Professor : public Person {
protected:
	char professorNum[11];
	char major[32];

public:
	Professor() {
		this->professorNum[0] = '\0';
		this->major[0] = '\0';
	}

	// setter들 정의
	void setAge(int age) { this->age = age; }
	void setName(const char* name);
	void setProfessorNum(const char* professorNum);
	void setMajor(const char* major);

	// getter들 정의
	int getAge() { return this->age; }
	char* getName() { return this->name; }
	char* getProfessorNum() { return this->professorNum; }
	char* getMajor() { return this->major; }

	void Say();
};

void Professor::setName(const char* name) {
	strncpy(this->name, name, sizeof(this->name) - 1);
	this->name[sizeof(this->name) - 1] = '\0'; // 문자열 끝을 명시적으로 설정
}

void Professor::setProfessorNum(const char* professorNum) {
	strncpy(this->professorNum, professorNum, sizeof(this->professorNum) - 1);
	this->professorNum[sizeof(this->professorNum) - 1] = '\0'; // 문자열 끝을 명시적으로 설정
}

void Professor::setMajor(const char* major) {
	strncpy(this->major, major, sizeof(this->major) - 1);
	this->major[sizeof(this->major) - 1] = '\0'; // 문자열 끝을 명시적으로 설정
}

void Professor::Say() {
	cout << "I'm a professor at KW University." << endl;
	cout << "My name is " << this->getName() << "." << endl;
	cout << "I'm " << this->getAge() << " years old." << endl;
	cout << "I work in the " << this->getMajor() << " department." << endl;
	cout << "My employee ID is " << this->getProfessorNum() << "." << endl;
}


int main() {
	Student student;
	cout << "======== Student Information ========" << endl;
	student.setName("Hong Gill Dong");
	student.setAge(21);
	student.setStudentNum("2022202092");
	student.setMajor("Computer Engineering");
	student.setSchoolYear(2);
	student.Say();


	Professor professor;
	cout << endl << "======== Professor Information ========" << endl;
	professor.setName("Kim Sun");
	professor.setAge(35);
	professor.setProfessorNum("P1234567");
	professor.setMajor("Computer Science");
	professor.Say();

	return 0;
}