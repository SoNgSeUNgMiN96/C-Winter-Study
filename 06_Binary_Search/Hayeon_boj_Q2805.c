// 나무자르기 (백준 2805번)
// 퀵정렬과 같은 정렬알고리즘 사용시 -> 시간초과 뜸

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int N; // 나무의 수
    long M; // 상근이가 집으로 가져가려고 하는 나무의 길이

    scanf("%d %ld", &N, &M);

    long* arr = (long*)malloc(sizeof(long) * N);
    long max = 0;

    for (int i = 0; i < N; i++) {
        scanf("%ld", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }

    long left = 0;
    long right = max;
    long mid = 0;
    long sum = 0;
    long cutting = 0; // 절단기 위치

    while (left <= right) {
        mid = (left + right) / 2;
        sum = 0;
       
        for (int i = N-1; i >= 0; i--) {
            long value = arr[i] - mid;
            if (value >= 0) sum += value;
        }

        if (sum >= M) {
            cutting = mid; 
            left = mid + 1;
        }
        
        else right = mid - 1;
    }
    printf("%ld", cutting);
    return 0;
}
