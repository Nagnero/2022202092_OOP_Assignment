#pragma once
#include <cmath>

namespace oopstd {

	void* memset(void* ptr, int value, size_t num) {
		void* temp = ptr;

		for (int i = 0; i < num; i++) {
			*(char*)temp = (char)value;
			temp = (char*)temp + 1;
		}

		return ptr;
	}


	void* memcpy(void* destination, const void* source, size_t num) {
		for (int i = 0; i < num; i++) {
			destination[i]
		}
	}



	int strcmp(const char* str1, const char* str2) {
		int i = 0;

		while (str1[i] != NULL || str2[i] != NULL) {
			if (str1[i] == str2[i]) {
				i++;
			}
			else if (str1[i] > str2[i]) {
				return 1;
			}
			else {
				return -1;
			}
		}
		
		return 0;
	}


	int strncmp(const char* str1, const char* str2, size_t num) {

		for (int i = 0; i < num; i++) {
			if (str1[i] == str2[i]) {
				continue;
			}
			else if (str1[i] > str2[i]) {
				return 1;
			}
			else {
				return -1;
			}
		}

		return 0;
	}


	char* strcpy(char* destination, const char* source) {
		int i = 0;

		while (source[i]) {
			destination[i] = source[i];
			i++;
		}
		destination[i] = '\0';

		return destination;
	}


	char* strncpy(char* destination, const char* source, size_t num) {
		int i = 0;

		for (; i < num || source[i] == NULL; i++) {
			destination[i] = source[i];
		}
		if (source[i] == NULL) {
			destination[i] == NULL;
		}

		return destination;
	}


	size_t strlen(const char* str) {
		size_t result = 0;

		while (str[result])
			result++;

		return result;
	}


	int atoi(const char* str) {
		int len = 0, result = 0;

		while (!(str[len] == '\n'))
			len++;

		for (int i = 0; i < len; i++)
			result += (str[i] - '0') * pow(10, len - i - 1);

		return result;
	}


	float atof(const char* str) {
		int len = 0, result = 0;

		while (!(str[len] == '\n'))
			len++;

		for (int i = 0; i < len; i++)
			result += (str[i] - '0') * pow(10, len - i - 1);

		return (float)result;
	}
}

/*int len = 0; // 문자열의 길이


while ((char *)temp == NULL) {
	len++;
	temp = (char*)temp + 1;
}*/
