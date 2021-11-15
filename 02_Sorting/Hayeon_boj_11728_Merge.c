#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, i, j, k;

    scanf("%d %d", &N, &M); // 배열 A의 크기 : N, 배열 B의 크기

    int* list = (int*)malloc(sizeof(int) * (N+M));

    for (i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }

    for (i = N; i < N+M; i++) {
        scanf("%d", &list[i]);
    }
    
    int* Merge = (int*)malloc(sizeof(int) * (N+M));

    i = 0; j = N; k = 0;

    while (i < N && j < N+M) {
        if (list[i] < list[j]) {
            Merge[k++] = list[i++];
        }
        else {
            Merge[k++] = list[j++];
        }
    }
    if (i >= N) {
        for (int idx = j; idx < N+M; idx++) {
            Merge[k++] = list[idx];
        }
    }
    else {
        for (int idx = i; idx < N; idx++) {
            Merge[k++] = list[idx];
        }
    }
    for (i = 0; i < N + M; i++) {
        list[i] = Merge[i];
    }

    for (i = 0; i < N + M; i++)
        printf("%d ", list[i]);
}