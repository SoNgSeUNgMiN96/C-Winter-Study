//
//  main.c
//  CombineArray
//
//  Created by rabbi on 2021/11/15.
//

// No. 11728
// 정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.
// 첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
// 둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int array[], int size) {
    for(int i = size - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[j] > array[j+1]) Swap(&array[j], &array[j+1]);
        }
    }
}

void MergeSort(int array[], int N, int M) {
    int sorted[N+M];
    int i = 0; int j = N; int k = 0;
    
    while(i < N && j < N+M) {
        if(array[i] < array[j]) {
            sorted[k++] = array[i++];
        } else {
            sorted[k++] = array[j++];
        }
    }
    
    if(i >= N) {
        for(int idx = j; idx < N+M; idx++) {
            sorted[k++] = array[idx];
        }
    } else {
        for(int idx = i; idx < N; idx++) {
            sorted[k++] = array[idx];
        }
    }
    
    for(int idx = 0; idx < N+M; idx++) {
        array[idx] = sorted[idx];
    }
    
}

int main(int argc, const char * argv[]) {
    int N, M; // 배열 A와 B의 크기
    scanf("%d %d", &N, &M); // 두 개의 배열 크기를 입력받는다
    int AandB[N+M]; // 정렬이 되지 않은 합 배열
    int temp;
    for(int i = 0; i < N + M; i++) {
        scanf("%d", &temp);
        AandB[i] = temp;
    }
    
    // BubbleSort
//    BubbleSort(AandB, N+M);
    
    // MergeSort
    MergeSort(AandB, N, M);
    
    // 출력
    for(int i = 0; i < N + M; i++) {
        printf("%d ", AandB[i]);
    }
    return 0;
}
