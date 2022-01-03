// 예산 (백준 2512번)

/* [ 알고리즘 ]
* 
*  1. left(0), right(입력된 값중 제일 최대값)으로 초기화
*  2. mid = (left+right)/2;
*  3. 전체 배열을 반복문 돌림 해당 값이 mid보다 작으면 그냥 해당값을 temp에 더해줌
*  4. 3번의 경우 -> 해당 값이 mid보다 크거나 같으면 mid값을 temp에 더해줌
*  5. 만약 temp값이 M보다 작거나 같으면 left를 mid+1 해주고 answer= mid로 갱신 (배정된 예산중에 최댓값을 구하는 것이므로)
*  6. temp값이 M보다 클 경우 right를 mid-1로 해줌
*  7. left<=right 조건에 해당하지 않을 경우까지 2-6번 과정을 반복
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0; // 지방의 수
	int M = 0; // 전체(총) 국가 예산
	
	scanf("%d", &N);
	
	int* list = (int*)malloc(sizeof(int) * N); // 지방의 예산요청 리스트
	
	int max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
		if (max < list[i]) max = list[i];
	}

	scanf("%d", &M);

	int left = 0;
	int right = max;
	int mid = 0;
	int answer = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (list[i] < mid) temp += list[i];
			else temp += mid;
		}

		if (temp <= M) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%d", answer);
}