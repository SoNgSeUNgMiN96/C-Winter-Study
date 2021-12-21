#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// strtok 내용 참고 : https://dojang.io/mod/page/view.php?id=376

int main() {
	char str[51];
	scanf("%s", str);

	char* ptr = strtok(str, "-");
	char *sArr[50] = { NULL, }; // 문자열 포인터 배열
	int i = 0;

	while (ptr != NULL) {
		int sum = 0;
		sArr[i] = ptr;
		i++;
		ptr = strtok(NULL, "-");
	}

	int Arr[50] = { NULL, };
	int j = 0;
	
	for (int i = 0; i < 50; i++)
	{	
		int sum = 0;
		if (sArr[i] != NULL) {          // 문자열 포인터 배열의 요소가 NULL이 아닐 때만
			if (strstr(sArr[i], "+")) {
				char* ptr2 = strtok(sArr[i], "+"); // 뒤 문자를 기준으로 문자열을 자름
				while (ptr2 != NULL) {
					sum += atoi(ptr2);
					ptr2 = strtok(NULL, "+"); // 다음 문자열을 잘라서 포인터를 반환
				}
				Arr[j] = sum;
				j++;
			}
			else {
				Arr[j] = atoi(sArr[i]);
				j++;
			}
		}
	}

	int answer = Arr[0];

	for (int i = 1; i < 50; i++) {
		if (Arr[i] != NULL) {
			answer -= Arr[i];
		}
	}

	printf("%d", answer);
}