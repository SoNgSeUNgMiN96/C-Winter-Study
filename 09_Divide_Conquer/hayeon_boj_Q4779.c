// 칸토어 집합 (백준 4779번)

/* [ 알고리즘 ]
 *
 * 1. 처음 입력받은 N에 대해 3^N개의 -로 이루어진 문자열을 만듦
 * 2. 3등분 한 뒤 가운데 문자열을 공백으로 바꾼다.
 * 3. 나머지 문자열 2개에서 2의 과정을 반복한다.
 * 4. 모든 선의 길이가 1일 때까지 2-3의 과정을 반복
 * 5. 만약 선의 길이가 1이 될 경우 해당 문자열을 출력
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void partition(int start, int num);
char* Line;

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int num = (int)pow(3, N);

		Line = (char*)malloc(sizeof(char) * num);

		for (int i = 0; i < num; i++) {
			Line[i] = '-';
		}
		
		partition(0, num);
		
		for (int i = 0; i < num; i++) {
			printf("%c", Line[i]);
		}
		printf("\n");
	}
	return 0;
}
void partition(int start, int num) {

	if (num < 3) {
		return;
	}

	/* A B C
	 *
	 * A : start ~ start+num/3
	 * B : start+num/3 ~ start+num/3*2
	 * C : start+num/3*2 ~ start+num
	 */

	partition(start, num / 3);
	for (int i = start + num / 3; i < start + num / 3 * 2; i++) {
		Line[i] = ' '; // '-' -> ' '
	}
	partition(start + num / 3 * 2, num / 3);
}
