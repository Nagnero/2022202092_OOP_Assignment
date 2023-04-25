#include <iostream>

using namespace std;

class Employee {
private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	Employee(char* name, int age, char* country, char* job);
	bool isNameCorrect(char* name);
	void print();
	void change(char* name, int age, char* country, char* job);
};

Employee::Employee(char* name, int age, char* country, char* job) {
	this->name = name;
	this->age = age;
	this->country = country;
	this->job = job;
}

bool Employee::isNameCorrect(char* name) {
	if (strcmp(name, this->name) == 0)
		return 1; // 이름이 같음을 의미
	else
		return 0; // 이름이 다름을 의미
}

void Employee::print() {
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl;
	cout << "----------" << endl;
}

void Employee::change(char* name, int age, char* country, char* job) {
	this->name = name;
	this->age = age;
	this->country = country;
	this->job = job;
}

int main() {
	Employee* employee[10];
	char command[10], temp_name[100];
	int index = 0;

	while (1) {
		cin >> command;

		if (strcmp(command, "insert") == 0) {
			if (index > 10) {
				cout << "stored information is already 10" << endl;
				continue;
			}
			
			char* name = new char[100];
			char* country = new char[100];
			char* job = new char[100];
			int age;

			cin >> name >> age >> country >> job;
			employee[index++] = new Employee(name, age, country, job);

			
		}
		else if (strcmp(command, "print") == 0) {
			cout << "=====print=====" << endl;
			for (int i = 0; i < index; i++)
				employee[i]->print();
			cout << endl;
		}
		else if (strcmp(command, "find") == 0) {
			cin >> temp_name;
			for (int i = 0; i < index; i++) {
				if (employee[i]->isNameCorrect(temp_name)) {
					cout << "=====find=====" << endl;
					employee[i]->print();
					cout << endl;
					break;
				}
			}
		}
		else if (strcmp(command, "change") == 0) {
			cin >> temp_name;
			for (int i = 0; i < index; i++) {
				if (employee[i]->isNameCorrect(temp_name)) { // 바꿀 이름의 데이터가 있으면
					char name[100], country[100], job[100];
					int age;

					cin >> name >> age >> country >> job;
					employee[i]->change(name, age, country, job);
					break;
				}
			}
		} 
		else if (strcmp(command, "exit") == 0) {

			return 0;
		}
		else {
			cout << "Enter valid command." << endl;
		}
	}
}