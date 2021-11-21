//
//  main.c
//  Queue
//
//  Created by rabbi on 2021/08/07.
//
// Queue (FIFO)
// 선형 큐는 배열에서의 인덱스를 단순히 증가시키는 방식으로 Data를 추가하므로
// 나중에 Dequeue 해주었을때 비어있는 인덱스를 활용하지 못하는 문제점이 있어
// 원형 큐로 구현하였습니다.

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Queue {
    int rear; 
    int front;
    int QueueSize;
    Data* data; // 동적 할당으로 크기를 정할 예정
}Queue;

// Queue의 멤버들을 초기화해주는 함수
void initQueue(Queue* queue, int MAX_SIZE) {
    queue->rear = 0;
    queue->front = 0;
    queue->data = (Data*)malloc(sizeof(Data) * MAX_SIZE);
    queue->QueueSize = MAX_SIZE;
}

// Queue가 비어 있는지 확인해주는 함수
int IsEmpty(Queue* queue) {
    if(queue->front == queue->rear) return 1; // front와 rear가 같은 곳을 가리키고 있다면 비어있다
    return 0;
}

// Queue가 꽉 차 있는지 확인해주는 함수
int IsFull(Queue* queue) {
    if(((queue->rear + 1) % queue->QueueSize) == queue->front) return 1;
    return 0;
}

// data를 Queue에 Enqueue 해주는 함수
void Enqueue(Queue *queue, Data data) {
    if(IsFull(queue)) {
        printf("\n");
        printf("포화 상태입니다.\n");
    } else {
        queue->data[(++queue->rear) % queue->QueueSize] = data;
    }
}

// Queue에서 Dequeue 하고 data를 리턴해주는 함수
Data Dequeue(Queue *queue) {
    if(IsEmpty(queue)) {
        printf("비어 있습니다.\n");
        return -1;
    }
    Data ret_data = queue->data[(++queue->front) % queue->QueueSize];
    return ret_data;
}

// Queue의 첫 번째 data를 출력해주는 함수
Data Peek(Queue *queue) {
    return queue->data[(queue->front + 1) % queue->QueueSize];
}

// Queue의 Data를 출력해주는 함수
void PrintQueue(Queue * queue) {
    if(IsEmpty(queue)) {
        printf("비어 있습니다.\n");
    } else {
        for(int i = queue->front + 1; i <= queue->rear; i++) {
                printf("%d --> ", queue->data[i % queue->QueueSize]);
            }
            printf("END\n");
    }
}

int main(int argc, const char * argv[]) {
    int input = -1; // 선택 input
    int MAX_SIZE;
    Queue queue;
    
    printf("Queue 시작...\n");
    printf("Queue의 크기 지정: ");
    scanf("%d", &MAX_SIZE);
    initQueue(&queue, MAX_SIZE);
    
    printf("\n");
    
    while(1) {
        printf("1. 추가\n\
2. 삭제\n\
3. 탐색\n\
4. 종료\n");
        scanf("%d", &input);
        printf("\n");
        switch (input) {
            case 1: // 1. 추가
                printf("추가할 데이터를 입력하세요\n");
                Data data;
                scanf("%d", &data);
                Enqueue(&queue, data);
                printf("\n");
                break;
            case 2: // 2. 삭제
                if(!IsEmpty(&queue)) {
                    printf("삭제하려는 데이터가 %d 맞나요? 예(1)/아니요(0) ", Peek(&queue));
                    scanf("%d", &input);
                    if(input == 1) {
                        printf("%d 삭제 완료\n", Dequeue(&queue));
                    } else {
                        break;
                    }
                } else {
                    printf("비어 있습니다.\n");
                }
                printf("\n");
                break;
            case 3: // 3. 탐색
                printf("front: %d rear: %d\n", queue.front,queue.rear);
                PrintQueue(&queue);
                printf("\n");
                break;
            case 4:
                goto EXIT;
            default:
                printf("잘못된 입력입니다.\n\n");
        }
    EXIT:
        if(input==4) break; // 4. 종료
    }
    return 0;
}
