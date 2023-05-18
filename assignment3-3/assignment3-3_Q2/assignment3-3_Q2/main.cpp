#include <iostream>

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
	void setName(char* name);
	void setStudentNum(const char* studentNum);
	void setMajor(const char* major);
	void setSchoolYear(int schoolYear) { this->schoolYear = schoolYear; }

	// getter들 정의
	int getAge() { return this->age; }
	char* getNage() { return this->name; }
	char* getStudentNum() { return this->studentNum; }
	char* getmajor() { return this->major; }
	int getSchoolYear() { return this->schoolYear; }

	void Say();
};

int main() {

	return 0;
}