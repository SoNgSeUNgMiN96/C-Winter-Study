// 소수 사이 수열 (백준 3896번)

/* [ 알고리즘 ]
*  
*  1. 입력된 k가 소수인지 아닌지 판별
*  2. k가 소수일 경우 0 을 출력, k가 소수가 아닐 경우 이분탐색 해줌
*  3. 2번의 이분탐색의 경우 left값과 right 값을 각각 감소시키고 증가시키며 소수를 찾아줌 (두 소수의 차를 출력) -> 길이가 n인 소수 사이 수열
*  
* (주의) : 소수 판별 알고리즘
*   - case 1 (양의 약수를 두개만 가지는 자연수) : O(N) -> 모든 경우의 수를 다 돔(비효율적)   -> 시간초과(실패)
*   - case 2 (에라토스테네스의 체) : O(N log log N) -> 거의 선형 시간                        -> 성공
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool prime_number(int num);
int binary_search(int num, int arr[]);
int* primeNumber(int num);
int N = 1299710;

int main() {
	int T = 0; // 테스트 케이스 개수
	scanf("%d", &T);
	
	// 에라토스테네스의 체
	int* arr = primeNumber(N);

	int num = 0;
	int* answer = (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &num);

		if (arr[num]!=0) {          // 소수일 경우
			answer[i] = 0;
		}
		else {                      // 소수가 아닐 경우
			answer[i] = binary_search(num, arr);
		}
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", answer[i]);
	}

	free(answer);
	return 0;
}

bool prime_number(int num) { // 시간복잡도 O(N)
	//printf("%d", num);
	if (num == 1) return false;
	
	int count = 0;
	
	for (int i = 2; i <= num - 1; i++) {
		if (num % i == 0) count++;
	}
	return (count == 0) ? true : false;
}

// 에라토스테네스의 체
int* primeNumber(int num) { // 시간복잡도 O(N log log N)
	//int arr[1299710] = { 0, };
	int* arr = (int*)malloc(sizeof(int) * num);
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= num; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= num; j += i) {
			arr[j] = 0; // 소수가 아닐 경우
		}
	}
	return arr;
}

int binary_search(int num, int arr[]) {
	int left = num - 1;
	int right = num + 1;
	int answer = 0;

	while (arr[left]==0) left--;
	while (arr[right]==0) right++;
	return right - left;
}