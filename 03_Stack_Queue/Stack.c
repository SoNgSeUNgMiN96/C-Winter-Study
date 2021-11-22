//
//  main.c
//  Stack
//
//  Created by rabbi on 2021/08/14.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Stack {
    Data* data;
    int cursor;
    int StackSize;
}Stack;

// Stack의 배열을 동적할당 해주고, cursor를 -1로 초기화해주는 Stack 초기화 함수
void InitStack(Stack* Stack, int MAX_SIZE) {
    Stack->data = (Data*)malloc(sizeof(Data) * MAX_SIZE);
    Stack->cursor = -1;
    Stack->StackSize = MAX_SIZE;
}

// Stack이 비어있는지 확인하는 함수
int IsEmpty(Stack* Stack) {
    if(Stack->cursor == -1) { // cursor가 index 0을 가리킨다면 비어있다
        return 1;
    } else {
        return 0;
    }
}

// Stack이 포화 상태인지 확인하는 함수
int IsFull (Stack* Stack) {
    if(Stack->cursor ==  Stack->StackSize - 1) { // cursor가 배열의 끝의 index를 가리킨다면 포화 상태이다
        return 1;
    } else {
        return 0;
    }
}

// Stack에 Data를 Push하는 함수
void Push(Stack* Stack, Data data) {
    if(IsFull(Stack)) {
        printf("포화 상태입니다.\n");
    } else {
        Stack->data[++Stack->cursor] = data;
    }
}

// Stack에서 Data를 Pop하는 함수
Data Pop(Stack* Stack) {
    if(IsEmpty(Stack)) {
        printf("비어있는 상태입니다.\n");
        return -1;
    } else {
        return Stack->data[Stack->cursor--];
    }
}

// Stack에서 cursor가 가리키는 Data를 Peek하는 함수
Data Peek(Stack* Stack) {
    if(IsEmpty(Stack)) {
        printf("비어있는 상태입니다.\n");
        return -1;
    } else {
        return Stack->data[Stack->cursor];
    }
}

// Stack에 있는 Data를 출력하는 함수
void PrintStack(Stack* Stack) {
    if(IsEmpty(Stack)) {
        printf("비어 있습니다.\n");
    } else {
        for(int i = 0; i <= Stack->cursor; i++) {
                printf("%d --> ", Stack->data[i]);
            }
            printf("END\n");
    }
}

int main(int argc, const char * argv[]) {
    int input = -1; // 선택 input
    int MAX_SIZE;
    Stack Stack;
    
    printf("Stack 시작...\n");
    printf("Stack의 크기 지정: ");
    scanf("%d", &MAX_SIZE);
    
    InitStack(&Stack, MAX_SIZE);
    
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
                Push(&Stack, data);
                printf("\n");
                break;
            case 2: // 2. 삭제
                if(!IsEmpty(&Stack)) {
                    printf("삭제하려는 데이터가 %d 맞나요? 예(1)/아니요(0) ", Peek(&Stack));
                    scanf("%d", &input);
                    if(input == 1) {
                        printf("%d 삭제 완료\n", Pop(&Stack));
                    } else {
                        break;
                    }
                } else {
                    printf("비어 있습니다.\n");
                }
                printf("\n");
                break;
            case 3: // 3. 탐색
                PrintStack(&Stack);
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
