//
//  main.c
//  ChristmasGift
//
//  Created by rabbi on 2021/11/29.
//

// No. 14235
// 크리스마스에는 산타가 착한 아이들에게 선물을 나눠준다. 올해도 산타는 선물을 나눠주기 위해 많은 노력을 하고 있는데, 전세계를 돌아댕기며 착한 아이들에게 선물을 나눠줄 것이다. 하지만 산타의 썰매는 그렇게 크지 않기 때문에, 세계 곳곳에 거점들을 세워 그 곳을 방문하며 선물을 충전해 나갈 것이다. 또한, 착한 아이들을 만날 때마다 자신이 들고있는 가장 가치가 큰 선물 하나를 선물해 줄 것이다.
//
// 이제 산타가 선물을 나눠줄 것이다. 차례대로 방문한 아이들과 거점지의 정보들이 주어졌을 때, 아이들이 준 선물들의 가치들을 출력하시오. 만약 아이들에게 줄 선물이 없다면 -1을 출력하시오.

// 입력
// 첫 번째 줄에서는 아이들과 거점지를 방문한 횟수 n이 주어진다.(1≤n≤5,000)
//
// 다음 n줄에는 a가 들어오고, 그 다음 a개의 숫자가 들어온다. 이는 거점지에서 a개의 선물을 충전하는 것이고, 그 숫자들이 선물의 가치이다. 만약 a가 0이라면 거점지가 아닌 아이들을 만난 것이다. 선물의 가치는 100,000보다 작은 양의 정수이다.(1≤a≤100)
//
// 출력
// a가 0일 때마다, 아이들에게 준 선물의 가치를 출력하시오. 만약 줄 선물이 없다면 -1을 출력하라. 적어도 하나의 출력이 있음을 보장한다.

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 500000 // 힙 안에 저장된 요소의 개수

typedef struct{
  int heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void InitHeap(HeapType* h) {
    h->heap_size = 0;
}

/* 현재 요소의 개수가 heap_size인 힙 h에 item을 삽입한다. */
// 최대 힙(max heap) 삽입 함수
void insert_max_heap(HeapType *h, int item){
    int i;
    i = ++(h->heap_size); // 힙 크기를 하나 증가
    
    /* 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 */
    // i가 루트 노트(index: 1)이 아니고, 삽입할 item의 값이 i의 부모 노드(index: i/2)보다 크면
    while((i != 1) && (item > h->heap[i/2])){
        // i번째 노드와 부모 노드를 교환환다.
        h->heap[i] = h->heap[i/2];
        // 한 레벨 위로 올라단다.
        i /= 2;
    }
    h->heap[i] = item; // 새로운 노드를 삽입
}

// 최대 힙(max heap) 삭제 함수
int delete_max_heap(HeapType *h){
    if(h->heap_size == 0) return -1;
    int parent, child;
    int item, temp;
    
    item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
    temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size){
        // 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. (루트 노드의 왼쪽 자식 노드(index: 2)부터 비교 시작)
        if( (child < h->heap_size) && ((h->heap[child]) < h->heap[child+1]) ){
            child++;
        }
        // 더 큰 자식 노드보다 마지막 노드가 크면, while문 중지
        if(temp >= h->heap[child]){
            break;
        }
        
        // 더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환
        h->heap[parent] = h->heap[child];
        // 한 단계 아래로 이동
        parent = child;
        child *= 2;
    }
    
    // 마지막 노드를 재구성한 위치에 삽입
    h->heap[parent] = temp;
    // 최댓값(루트 노드 값)을 반환
    return item;
}


int main(int argc, const char * argv[]) {
    HeapType heap;
    int n; // 아이들과 거점지를 방문한 횟수 (1≤n≤5,000)
    int input;
    int gift; // 선물의 가치
    
    InitHeap(&heap);
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &input);
        if(input == 0) {
            printf("%d\n", delete_max_heap(&heap));
        } else {
            for(int j = 0; j < input; j++) {
                scanf("%d", &gift);
                insert_max_heap(&heap, gift);
            }
        }
    }
    return 0;
}
