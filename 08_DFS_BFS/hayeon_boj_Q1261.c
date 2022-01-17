// 알고스팟 (백준 1261번)

// 다익스트라 알고리즘 이용 (우선순위큐 사용)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TRUE 1
#define FALSE 0
#define HEAP_LEN 10000

int map[110][110];
bool isVisited[110][110];
int dx[4] = { 0, 0, -1, 1 }; // 상 하 좌 우
int dy[4] = { 1, -1, 0, 0 }; // 상 하 좌 우

int bfs(int x, int y, int N, int M);

typedef struct value
{
    int x;
    int y;
    int cnt;
}values;

struct heap_element // 정수 값을 저장하는 힙의 노드 구조체로 우선 순위를 지정할 수 있다.
{
    int priority;
    values data;
};
typedef struct heap_element heap_element;

struct heap
{
	int count;
	heap_element heap_arr[HEAP_LEN]; // 힙은 배열 구조를 기반으로 구현된다.
};
typedef struct heap heap;

void HeapInit(heap* h);
int HIsEmpty(heap* h);
void HInsert(heap* h, values data, int priority);
values HDelete(heap* h);
void ShowHeap(heap* h);

int GetParentIndex(int child_index);
int GetLeftChildIndex(int parent_index);
int GetRightChildIndex(int parent_index);
int GetChildIndex(heap* h, int parent_index);

int main() {
	int M, N; // 가로크기, 세로크기
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int answer = bfs(0, 0, N, M);
	printf("%d", answer);
	return 0;
	
}

int bfs(int x, int y, int N, int M) {
    heap h;
    HeapInit(&h);

    values p;
    p.x = x;
    p.y = y;
    p.cnt = 0;

    HInsert(&h, p, p.cnt); // 벽을 부수는 횟수(p.cnt)로 우선순위 정함

    while (!HIsEmpty(&h)) {
        values t = HDelete(&h);

        if (t.x == M - 1 && t.y == N - 1) return t.cnt;

        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

            if (!isVisited[ny][nx]) {
                values v;
                if (map[ny][nx] == 0) { // 빈 방일 경우
                    v.x = nx;
                    v.y = ny;
                    v.cnt = t.cnt;
                    HInsert(&h, v, t.cnt);
                    isVisited[ny][nx] = true;
                }
                else {
                    v.x = nx;
                    v.y = ny;
                    v.cnt = t.cnt+1;
                    HInsert(&h, v, t.cnt+1);
                    isVisited[ny][nx] = true;
                }
            }
        }
    }
    return 0;
}

void HeapInit(heap* h)
{
    int i = 0;
    h->count = 0;
    for (i = 0; i < HEAP_LEN; i++)
    {
        h->heap_arr[i].data.x = 0;
        h->heap_arr[i].data.y = 0;
        h->heap_arr[i].data.cnt = 0;
        h->heap_arr[i].priority = -1;
    }
    return;
}
int HIsEmpty(heap* h)
{
    return (h->count == 0) ? TRUE : FALSE;
}

void HInsert(heap* h, values data, int priority)
{
    int insert_index = h->count + 1;
    int parent_index = 0;
    heap_element new_element = { priority, data };

    while (insert_index != 1) // 처음 삽입되는 위치가 루트 노드가 아니면 혹은 갱신된 추가 인덱스가 루트 노드가 아니면
    {
        parent_index = GetParentIndex(insert_index);
        if (new_element.priority >= h->heap_arr[parent_index].priority) // 우선 순위가 부모가 높다면 구조 재조정이 필요 없다.
            break;
        else // 추가할 노드가 우선 순위가 높은 경우, 계속 구조 재조정이 필요함.
        {
            h->heap_arr[insert_index] = h->heap_arr[parent_index];
            insert_index = parent_index;
        }
    }
    h->heap_arr[insert_index] = new_element;
    h->count++;
    return;
}

values HDelete(heap* h)
{
    values r_data; 
    r_data.x= h->heap_arr[1].data.x; // 삭제할 데이터(Pop 할 데이터와 같은 의미)
    r_data.y = h->heap_arr[1].data.y; // 삭제할 데이터(Pop 할 데이터와 같은 의미)
    r_data.cnt = h->heap_arr[1].data.cnt; // 삭제할 데이터(Pop 할 데이터와 같은 의미)
    heap_element last_element = h->heap_arr[h->count]; // 비교 대상인 마지막 노드 지정( 마지막 노드를 루트 자리로 올려 비교하기 때문 )
    // 최종 결정된 인덱스
    int parent_index = 1; // 루트 노드 부터 시작한다.
    int child_index = 0;

    while (child_index = GetChildIndex(h, parent_index))
    {
        if (last_element.priority <= h->heap_arr[child_index].priority) // 자식 노드보다 우선 순위가 높다면 현재 구한 인덱스로의 변경만 하면 된다.
            break;
        else // 계속해서 구조의 재조정이 필요한 경우
        {
            h->heap_arr[parent_index] = h->heap_arr[child_index];
            parent_index = child_index;
        }
    }
    h->heap_arr[parent_index] = last_element;
    h->count--;
    return r_data;
}
// Heap의 내용을 트리의 계층(레벨) 별로 보여준다.
void ShowHeap(heap* h)
{
    int begin = 1, end = 1, index = 1;
    int i = 0;

    if (h->count == 0)
    {
        printf("heap이 비었습니다!\n");
        return;
    }

    printf("%d, %d, %d(%d), \n", h->heap_arr[1].data.x, h->heap_arr[1].data.y, h->heap_arr[1].data.cnt, h->heap_arr[1].priority);

    while (index <= h->count)
    {
        begin = GetLeftChildIndex(begin), end = GetRightChildIndex(end); // 각 레벨 층의 시작과 끝 인덱스 설정 후 출력한다
        if (end > h->count)    end = h->count; // end가 마지막 노드보다 넓은 범위에 있다면 end를 마지막 노드의 인덱스로 설정

        index = end + 1; // 위에서 지정한 end 다음 값으로 변경한다.

        for (i = begin; i <= end; i++)
            printf("%d, %d, %d(%d), ", h->heap_arr[i].data.x, h->heap_arr[i].data.y, h->heap_arr[i].data.cnt, h->heap_arr[i].priority);
        fputc('\n', stdout);
    }
    return;
}

// 부모 노드의 인덱스를 구한다.
int GetParentIndex(int child_index)
{
    return child_index / 2;
}
// 왼쪽 자식 노드의 인덱스를 구한다.
int GetLeftChildIndex(int parent_index)
{
    return parent_index * 2;
}
// 오른쪽 자식 노드의 인덱스를 구한다.
int GetRightChildIndex(int parent_index)
{
    return (parent_index * 2) + 1;
}
// 두 자식 노드 중 우선 순위에 따라 반환한다.
int GetChildIndex(heap* h, int parent_index)
{
    if (GetLeftChildIndex(parent_index) > h->count) // 자식 노드가 없으면 0 반환
        return 0;
    else if (GetLeftChildIndex(parent_index) == h->count) // 자식 노드가 하나인 경우에는 해당 인덱스 반환
        return GetLeftChildIndex(parent_index);
    else // 두 자식 노드 중 우선 순위가 높은 것의 인덱스 반환
    {
        int left_child_index = GetLeftChildIndex(parent_index), right_child_index = GetRightChildIndex(parent_index);
        if (h->heap_arr[left_child_index].priority > h->heap_arr[right_child_index].priority) // 오른쪽 자식 노드가 더 우선 순위가 높다면
            return right_child_index; // 오른쪽 자식 노드의 인덱스 반환
        else // 왼쪽 자식 노드가 더 우선 순위가 높거나 양쪽 노드의 우선 순위가 같다면
            return left_child_index; // 왼쪽 자식 노드의 인덱스 반환
    }
}