/*
ex) 
100 + 50 - 80 + 50 - 40 + 10 ->
100 + 50 - (80 + 50) - (40 + 10)

처음 - 나올 때 까진 더하고, 그 뒤로는 괄호로 묶어서 빼버리면 최솟값이 됨

atoi(), strtok() 같은 라이브러리함수 안쓰고 구현
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int i = 0;
int res = 0;
int temp = 0;
int posMinus = 0;

bool isMinus(char* s) {
	i = 0;
	while (s[i]) {
		if (s[i] == '-') { return true; }

		i++;
	}
	return false;
}

int sumAll(char* s) {
	i = 0;
	res = 0;
	temp = 0;

	while (s[i]) {
		if (s[i] == '+') {
			res += temp;
			temp = 0;

			i++;
		}
		else {
			temp *= 10;
			temp += s[i] - '0';

			i++;		
		}
	}
	res += temp;

	return res;
}

int sumBeforeMinus(char* s) {
	i = 0;
	res = 0;
	temp = 0;

	while (s[i] != '-') 
	{
		if (s[i] == '+')
		{
			res += temp;
			temp = 0;

			i++;
		}
		else {
			temp *= 10;
			temp += s[i] - '0';

			i++;			
		}		
	}
	res += temp;
	posMinus = i;		// 처음 나온 -의 인덱스를 저장

	return res;
}

int sumAfterMinus(char* s) {
	i = ++posMinus;	// - 다음의 인덱스부터 탐색
	res = 0;
	temp = 0;

	while (s[i]) {
		if (s[i] == '+' || s[i] == '-') {
			res += temp;
			temp = 0;

			i++;
		}
		else {
			temp *= 10;
			temp += s[i] - '0';

			i++;
		}
	}
	res += temp;

	return res;

}

int main() {
	char s1[51];	//입력용	

	scanf("%s", s1);

	if (isMinus(s1)) {		//입력 식에 '-'가 있을 때
		printf("%d\n", sumBeforeMinus(s1) - sumAfterMinus(s1));
	}
	else {					//입력 식에 '-'가 없을 때
		printf("%d\n", sumAll(s1));
	}
}

