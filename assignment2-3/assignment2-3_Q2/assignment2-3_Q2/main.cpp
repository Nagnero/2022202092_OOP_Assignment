#include <iostream>

using namespace std;

class Student {
private:
	char* name;
	int age;
	char* class_name;
	
public:
	Student() {
		this->name = NULL;
		this->age = 0;
		this->class_name = NULL;
	}

	void setName(char name[]) { this->name = name; }
	char* getName() { return this->name; }
	void setAge(int age) { this->age = age; }
	int getAge() { return this->age; }
	void setClass(char class_name[]) { this->class_name = class_name; }
	char* getClass() { return this->class_name; }
};

class School {
private:
	class Student* student_list[100];
	int size = 0;

public:
	~School() {

	}

	void setStudent(char name[], int age, char class_name[]);
};

void School::setStudent(char name[], int age, char class_name[]) {
	
	Student* newstudent = new Student();

	newstudent->setName(name);
	newstudent->setAge(age);
	newstudent->setClass(class_name);

	this->student_list[this->size++] = newstudent;
}


int main() {

	School* school = new School;
	char command[20];

	while (1) {
		cin >> command;

		if (strcmp(command, "new_student") == 0) {
			char* name = new char;
			char* class_name = new char;
			int age = 0;

			cin >> name >> age >> class_name;
			school->setStudent(name, age, class_name);
		}
		else if (strcmp(command, "sort_by_name") == 0) {

		}
		else if (strcmp(command, "print_all") == 0) {

		}
		else if (strcmp(command, "print_class") == 0) {

		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
		else
			cout << "Enter vaild command." << endl;
	}

	delete school;

	return 0;
}