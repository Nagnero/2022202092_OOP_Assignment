#include <iostream>

using namespace std;

char* my_strtok(char* str);

int main() {
	char str[200]{};
	int num = 0;

	cin >> str;

	// @의 개수를 확인하는 반복문
	for (int i = 0; str[i]; i++)
		if (str[i] == '@')
			num++;

	// @이 1개가 아닌 경우 예외처리
	if (num != 1) {
		cout << "Unvalid e-mail address" << endl;
		return 0;
	}

	// token 초기 선언 및 할당
	char* token = my_strtok(str);

	// 반복문을 돌며 출력
	while (token != 0) {
		cout << token << endl;
		token = my_strtok(NULL); // 한번 값을 전달한 이후엔 nullptr 전달
	}

	return 0;
}

char* my_strtok(char* str) {
	static char* static_str = NULL;

	if (!str) // 전달받은 매개변수가 NULL이면
		static_str++;
	else // 전달받은 매개변수가 초기 입력값이면 해당 값 저장
		static_str = str;

	char* return_tok = static_str;

	while (*static_str != '@' && *static_str != '.' && *static_str != '\0')
		static_str++;

	// 입력값의 마지막이면
	if (*static_str == '\0')
		return return_tok;
	else { // 마지막이 아니면
		*static_str = '\0';
		return return_tok;
	}
}