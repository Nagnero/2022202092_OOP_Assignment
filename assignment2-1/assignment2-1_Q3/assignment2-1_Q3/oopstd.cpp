#include "oopstd.h"

namespace oopstd {

	// memset 사용자 정의 함수
	void* memset(void* ptr, int value, size_t num) {
		// 문자형 포인터 변수 임시로 선언 후 전달 받은 주소값 저장
		char* temp = (char*)ptr; 

		// 임시 저장 변수에 전달 받은 value 문자형으로 변환 후 대입
		// num만큼 반복
		for (int i = 0; i < num; i++) {
			*temp = (char)value;
			temp = temp + 1;
		}

		// 기존 포인터 반환
		return ptr;
	}

	// memcpy 사용자 정의 함수
	void* memcpy(void* destination, const void* source, size_t num) {
		// 문자형 포인터 변수 임시로 선언 후 저장할 주소와 데이터를 가져올 주소 각각 저장
		char* temp = (char*)source;
		char* temp_dest = (char*)destination;

		// 데이터를 가져올 주소에 접근하여 저장할 주소에 데이터 저장
		for (int i = 0; i < num; i++)
			temp_dest[i] = temp[i];

		// destination 반환
		return destination;
	}

	// strcmp 사용자 정의 함수 
	int strcmp(const char* str1, const char* str2) {
		int i = 0;

		// 두 문자열 중 하나라도 저장된 값이 없으면 종료
		while (str1[i] != NULL || str2[i] != NULL) {
			// 같은 위치에 같은 문자가 저장되어 있으면 i 1 증가
			if (str1[i] == str2[i]) {
				i++;
			}
			// 같은 위치에 저장된 문자가 str1이 더 크면 1 반환
			else if (str1[i] > str2[i]) {
				return 1;
			}
			// 같은 위치에 저장된 문자가 str2가 더 크면 -1 반환
			else {
				return -1;
			}
		}

		return 0;
	}

	// strncmp 사용자 정의 함수
	int strncmp(const char* str1, const char* str2, size_t num) {

		// 입력받은 num 만큼 반복문 반복
		for (int i = 0; i < num; i++) {
			// 같은 위치에 같은 문자가 저장되어 있으면 i 1 증가
			if (str1[i] == str2[i]) {
				continue;
			}
			// 같은 위치에 저장된 문자가 str1이 더 크면 1 반환
			else if (str1[i] > str2[i]) {
				return 1;
			}
			// 같은 위치에 저장된 문자가 str2가 더 크면 -1 반환
			else {
				return -1;
			}
		}

		return 0;
	}

	// strcpy 사용자 정의 함수
	char* strcpy(char* destination, const char* source) {
		int i = 0;

		// 저장할 주소에 기존 주소에 저장된 데이터 복사
		while (source[i]) {
			destination[i] = source[i];
			i++;
		}
		// 마지막에 NULL문자 삽입
		destination[i] = '\0';

		// 데이터를 복사한 주소 반환
		return destination;
	}

	// strncpy 사용자 정의 함수
	char* strncpy(char* destination, const char* source, size_t num) {
		int i = 0;

		// num만큼이거나 저장할 데이터가 있는 동안반복
		for (; i < num && source[i] != NULL; i++) {
			destination[i] = source[i]; // 데이터 복사
		}

		// 복사할 데이터가 NULL이면 저장할 데이터에도 NULL문자 삽입
		if (source[i] == NULL) {
			destination[i] = NULL;
		}

		// 데이터를 복사한 주소 반환
		return destination;
	}

	// strlen 사용자 정의 함수
	size_t strlen(const char* str) {
		size_t result = 0;

		// 문자열에 데이터가 있으면 result 증가
		while (str[result])
			result++;

		// result 반환
		return result;
	}

	// atoi 사용자 정의 함수
	int atoi(const char* str) {
		int len = 0, result = 0, sign = 1;

		// 문자열의 길이 카운트
		while (!(str[len] == '\n'))
			len++;

		// 문자열의 길이만큼 반복하며
		for (int i = 0; i < len; i++) {
			// 두번째 자리부터 숫자로 입력
			if (i > 0) {
				result += (str[i] - '0') * pow(10, len - i - 1);
			}
			// 첫번째 자리에서
			else {
				// 첫번째 문자가 -이면 sign을 -1로
				if (str[i] == '-')
					sign = -1;
				// 첫번재 문자가 +이면 그대로 진행
				else if (str[i] == '+')
					continue;
				// 그냥 숫자면 정수형으로 변환
				else
					result += (str[i] - '0') * pow(10, len - i - 1);
			}
		}

		// sign을 곱해서 반환
		return sign * result;
	}

	// atof 사용자 정의 함수
	float atof(const char* str) {
		float result = 0;
		int len = 0, len_num = 0, i = 0, period = 0, sign = 1;
		bool under = false;
		
		// 전체 문자열의 길이 len
		while (!(str[len] == '\n')) {
			len++;
			// 문자가 -나 .이 아니면
			if (str[len] != '-' && str[len] != '.')
				len_num++;
		}

		// 첫번째 부호가 -이면 sign -1, 반복분 1부터 시작.
		// 반복문 내에 쓸데없는 조건문을 없애기 위해 밖으로 빼냄
		if (str[0] == '-') {
			sign = -1;
			i = 1;
		}

		for (; i < len; i++) {
			// 소수점을 만나면 소수점 아래로 판단
			if (str[i] == '.') {
				under = true;
				period++;
				continue;
			}

			// 소수점 아래 몇번째 자리인지 판단하고 값 저장
			if (under) {
				period++;
				result += (str[i] - '0') * pow(10, len_num - i);
			}
			else 
				result += (str[i] - '0') * pow(10, len_num - i - 1);

		}

		// 소수점 아래 몇번째 자리인지 구해서 소수점 계산
		result *= pow(0.1, period - 1);

		// 부호를 위해 sign과 곱해서 반환
		return sign * result;
	}
}