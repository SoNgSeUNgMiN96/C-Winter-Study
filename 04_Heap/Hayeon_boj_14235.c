// 크리스마스 선물 (백준 14235번)

/*
* 컴파일 : ctrl+alt+C
* 실행 : ctrl+alt+R
*/

/*알고리즘
숫자를 저장

0이 들어오면 힙을 탐색(힙에 원소가 없으면 -1 출력 있으면 최대힙 삭제)
0이 아닌 다른 수가 들어오면 그 다음 숫자부터 저장

최대힙으로 저장한 뒤

0을 만나면 삭제
다른 숫자를 만나면 해당 숫자만큼 삽입 
*/

#include <stdio.h>
#include <stdlib.h>
#define HEAP_SIZE 500000

int heap[HEAP_SIZE];
int heapCount = 0;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int x)
{
    heap[++heapCount] = x;

    int child = heapCount;
    int parent = child / 2;

    while (child > 1 && heap[child] > heap[parent])
    {
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = child / 2;
    }
}

int pop()
{
    int ret = heap[1];

    swap(&heap[1], &heap[heapCount]);
    heapCount = heapCount - 1;

    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= heapCount)
    {
        child = (heap[child] > heap[child + 1]) ? child : child + 1;
    }

    while (child <= heapCount && heap[child] > heap[parent])
    {
        swap(&heap[child], &heap[parent]);
        parent = child;
        child = parent * 2;

        if (child + 1 <= heapCount)
        {
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }
    }
    return ret;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    int check = 0;

    for (int i = 0; i < N; i++)
    {
        int num = 0;
        scanf("%d", &num);

        if (num == 0)
        {
            if (check == 0)
            {
                printf("%d\n", -1);
            }
            else
            {
                printf("%d\n", pop());
                check--;
            }
        }
        else
        {
            for (int j = 0; j < num; j++)
            {
                int s = 0;
                scanf("%d", &s);
                push(s);
                check++;
            }
        }
    }
}