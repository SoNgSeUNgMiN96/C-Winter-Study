// K번째 수 (백준 1300번)

/* [ 알고리즘 ]
* 
*  1. k번째 숫자는 무조건 k보다는 작음
*  2. 인덱스 1부터 k번까지 이분탐색을 실행 (mid = (left+right)/2)
*  3. 크기가 N일 경우 mid가 각 행에서 몇개씩 가지고 있는지 카운트
*  4. 그 갯수가 k 보다 작을경우 left를 mid+1
*  5. 그 갯수가 k보다 같거나 클 경우 right를 mid-1
*  6. 이때, temp가 k를 만족시키는 경우 중, 제일 최소의 mid를 출력시켜줘야 하므로 answer은 right 부분에서 갱신
*/

#include <stdio.h>
#include <stdlib.h>

int binary_search(int N, int k);

int main() {
	int N, k; // 배열의 크기 N, B[k]의 값
	scanf("%d %d", &N, &k);

	printf("%d", binary_search(N, k));
}

int binary_search(int N, int k) {
	int left = 1;
	int right = k; // 최대가 k 이하이기 때문
	int answer = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int temp = 0;

		for (int i = 1; i <= N; i++) {
			int a = mid / i;
			if (a < N) temp += a;
			else temp += N;
		}

		if (temp < k) {
			left = mid+1;
		} else {
			right = mid - 1;
			answer = mid;
		}
	}
	return answer;
}