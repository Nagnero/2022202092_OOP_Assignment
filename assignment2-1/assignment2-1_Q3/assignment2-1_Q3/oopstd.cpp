#include <cmath>

namespace oopstd {

	void* memset(void* ptr, int value, size_t num) {
		char* temp = (char*)ptr;

		for (int i = 0; i < num; i++) {
			*temp = (char)value;
			temp = temp + 1;
		}

		return ptr;
	}


	void* memcpy(void* destination, const void* source, size_t num) {
		char* temp = (char*)source;
		char* temp_dest = (char*)destination;

		for (int i = 0; i < num; i++)
			temp_dest[i] = temp[i];

		return destination;
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
		bool minus = false;

		while (!(str[len] == '\n'))
			len++;

		for (int i = 0; i < len; i++) {
			if (i > 0) {
				result += (str[i] - '0') * pow(10, len - i - 1);
			}
			else {
				if (str[i] == '-')
					minus = true;
				else
					result += (str[i] - '0') * pow(10, len - i - 1);
			}
		}

		if (minus)
			result = -(result);

		return result;
	}


	float atof(const char* str) {
		int len = 1, result = 0;
		bool minus = false;

		if(str[0] == '-')


		while (!(str[len] == '\n'))
			len++;

		for (int i = 0; i < len; i++) {
			if (i > 0) {
				result += (str[i] - '0') * pow(10, len - i - 1);
			}
			else {
				if (str[i] == '-')
					minus = true;
				else
					result += (str[i] - '0') * pow(10, len - i - 1);
			}
		}

		if (minus)
			result = -(result);

		return (float)result;
	}
}