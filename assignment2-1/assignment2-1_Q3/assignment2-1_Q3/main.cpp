#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "oopstd.h"

using namespace std;

struct {
	char name[40];
	int age;
} person1, person1_copy, person2, person2_copy;

int main() {
	// memset method test
	cout << "Origianl" << endl;
	char str1_memset[] = "almost";
	memset(str1_memset, '-', 3);
	puts(str1_memset);
	// custom method test
	cout << "Custom" << endl;
	char str2_memset[] = "almost";
	oopstd::memset(str2_memset, '-', 3);
	puts(str2_memset);

	
	// memcpy method test
	cout << endl << "Origianl" << endl;
	char myname[] = "Pierre de Fermat";
	memcpy(person1.name, myname, strlen(myname) + 1);
	person1.age = 46;
	memcpy(&person1_copy, &person1, sizeof(person1));
	printf("person1_copy: %s, %d \n", person1_copy.name, person1_copy.age);
	// custom method test
	cout << "Custom" << endl;
	memcpy(person2.name, myname, strlen(myname) + 1);
	person2.age = 46;
	memcpy(&person2_copy, &person2, sizeof(person2));
	printf("person2_copy: %s, %d \n", person2_copy.name, person2_copy.age);



	// strcmp 메서드 test
	/*
	cout << endl << "Origianl" << endl;
	char key[] = "apple";
	char buffer[80];
	do {
		printf("Guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (strcmp(key, buffer) != 0);
	puts("Correct anwser!");
	// custom method test
	cout << "Custom" << endl;
	do {
		printf("Guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s", buffer);
	} while (oopstd::strcmp(key, buffer) != 0);
	puts("Correct anwser!"); */


	// strncmp 메서드 test
	/*cout << endl << "Origianl" << endl;
	char str[][5] = {"R2D2", "C3P0", "R2A6"};
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++) {
		if (strncmp(str[n], "R2xx", 2) == 0)
			printf("found %s\n", str[n]);
	}
	// custom method test
	cout << "Custom" << endl;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++) {
		if (oopstd::strncmp(str[n], "R2xx", 2) == 0)
			printf("found %s\n", str[n]);
	} */


	// strcpy 메서드 test
	/*cout << endl << "Origianl" << endl;
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	// custom method test
	cout << "Custom" << endl;
	char str4[40];
	char str5[40];
	oopstd::strcpy(str4, str1);
	oopstd::strcpy(str5, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3); */


	// strncpy method test
	/*cout << endl << "Origianl" << endl;
	char str1_stncpy[] = "To be or not to be";
	char str2_stncpy[40];
	char str3_stncpy[40];
	strncpy(str2_stncpy, str1_stncpy, sizeof(str2_stncpy));
	strncpy(str3_stncpy, str2_stncpy, 5);
	str3_stncpy[5] = '\0';
	puts(str1_stncpy);
	puts(str2_stncpy);
	puts(str3_stncpy);
	// custom method test
	cout << "Custom" << endl;
	char str4_stncpy[40];
	char str5_stncpy[40];
	oopstd::strncpy(str4_stncpy, str1_stncpy, sizeof(str4_stncpy));
	oopstd::strncpy(str5_stncpy, str4_stncpy, 5);
	str5_stncpy[5] = '\0';
	puts(str1_stncpy);
	puts(str4_stncpy);
	puts(str5_stncpy); */


	// strlen method test
	/*cout << endl << "Origianl" << endl;
	char szInput[256];
	printf("Enter a sentece: ");
	gets_s(szInput, sizeof(szInput));
	printf("The sentence entered is %u characters long.\n", (unsigned)strlen(szInput));
	// custom method test
	cout << "Custom" << endl;
	printf("Enter a sentece: ");
	gets_s(szInput, sizeof(szInput));
	printf("The sentence entered is %u characters long.\n", (unsigned)oopstd::strlen(szInput)); */
	
	// atoi method test
	/*cout << endl << "Origianl" << endl;
	int i_atoi;
	char buffer_atoi[256];
	printf("Enter a number: ");
	fgets(buffer_atoi, 256, stdin);
	i_atoi = atoi(buffer_atoi);
	printf("The value entered is %d. Its double is %d.\n", i_atoi, i_atoi * 2);
	// custom method test
	cout << "Custom" << endl;
	printf("Enter a number: ");
	fgets(buffer_atoi, 256, stdin);
	i_atoi = oopstd::atoi(buffer_atoi);
	printf("The value entered is %d. Its double is %d.\n", i_atoi, i_atoi * 2);*/


	// atof method test
	/*cout << endl << "Origianl" << endl;
	double n_atof;
	char buffer_atof[256];
	printf("Enter a number: ");
	fgets(buffer_atof, 256, stdin);
	n_atof = atof(buffer_atof);
	printf("The value entered is %f.\n", n_atof);
	// custom method test
	cout << "Custom" << endl;
	printf("Enter a number: ");
	fgets(buffer_atof, 256, stdin);
	n_atof = oopstd::atof(buffer_atof);
	printf("The value entered is %f.\n", n_atof);*/

	return 0;
 }