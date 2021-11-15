#include <stdio.h>
#include <stdlib.h> //랜덤함수 호출

void Swap(int arr[], int a, int b) // a,b 스왑 함수 
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;

    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (low <= right && pivot >= arr[low]) // 피벗보다 큰 값을 찾는 과정 
        {
            low++; // low를 오른쪽으로 이동 
        }
        while (high >= (left + 1) && pivot <= arr[high]) // 피벗보다 작은 값을 찾는 과정 
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
        {
            Swap(arr, low, high); //low와 high를 스왑 
        }
    }
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환 
    return high;  // 옮겨진 피벗의 위치정보를 반환 

}


void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right); // 둘로 나누어서
        QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}

//메인함수
int main()
{
    int N, M, i;
    //int arr[100];

    scanf("%d %d", &N, &M); // 배열 A의 크기 : N, 배열 B의 크기 : M

    //int arr[10];
    int* arr = (int*)malloc(sizeof(int) * (N + M));

    for (i = 0; i < N+M; i++) {
        scanf("%d", &arr[i]);
    }

    /*
    printf("정렬전 배열 :");
    for (i = 0; i < N+M; i++)
        printf("%d ", arr[i]);
    printf("\n");*/

    QuickSort(arr, 0, N+M - 1);

    //printf("정렬후 배열 :");
    for (i = 0; i < N+M; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}