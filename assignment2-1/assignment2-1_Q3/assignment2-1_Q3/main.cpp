#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "oopstd.h"

using namespace std;

struct {
	char name[40];
	int age;
} person, person_copy;

int main() {
	// memset 메서드 test부
	/*char str1[] = "almost";
	char str2[] = "almost";
	memset(str1, '-', 3);
	oopstd::memset(str2, '-', 3);
	cout << "original memset method : ";
	puts(str1);
	cout << "custom memset method : ";
	puts(str2);

	cout << endl << endl;
	// memcpy 메서드 test부
	char myname[] = "Pierre de Fermat";
	//
	memcpy(person.name, myname, strlen(myname) + 1);*/


	// strcmp 메서드 test
	/*
	cout << "Origianl" << endl;
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
	/*cout << "Origianl" << endl;
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
	/*cout << "Origianl" << endl;
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
	/*cout << "Origianl" << endl;
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
	/*cout << "Origianl" << endl;
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
	int i_atoi;
	char buffer_atoi[256];
	printf("Enter a number: ");
	fgets(buffer_atoi, 256, stdin);
	i_atoi = atoi(buffer_atoi);
	printf("The value entered is %d. Its double is %d.\n", i_atoi, i_atoi * 2);
	

	return 0;
 }