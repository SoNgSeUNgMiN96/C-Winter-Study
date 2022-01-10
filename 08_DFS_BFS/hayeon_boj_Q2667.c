// 단지 번호 붙이기 (백준 2667번)

#include <stdio.h>
#include <stdlib.h>

int graph[26][26];
int isVisited[26][26];

int dx[4] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[4] = {1, -1, 0, 0}; // 상 하 좌 우

int BFS(int x, int y, int N, int count);

void BubbleSort(int list[], int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

typedef int Data;
typedef struct Node {
	Data data;
	struct Node* next;
}Node;
typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
}Queue;

void InitQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int IsEmpty(Queue* queue) {
	return queue->count == 0;
}

void Enqueue(Queue* queue, Data data) {
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = data;
	now->next = NULL;

	if (IsEmpty(queue)) {
		queue->front = now;
	}
	else queue->rear->next = now;

	queue->rear = now;
	queue->count++;
}
int Dequeue(Queue* queue) {
	Data requeue = 0;
	Node* now;
	if (IsEmpty(queue)) return requeue;
	now = queue->front;
	requeue = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return requeue;
}
void Printqueue(Queue* queue) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = queue->front;
	printf("[ ");
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}

int main() {
	int N;

	scanf("%d", &N);

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			scanf("%1d", &graph[j][k]); // 입력 한개씩 받기
		}
	}

	int count = 2;

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (graph[j][k] == 1) {
				count = BFS(j, k, N, count);
			}
		}
	}

	printf("%d\n", count - 2); // 2부터 시작하기 때문

	int* list = (int*)malloc(sizeof(int) * (count - 2));

	for (int i = 0; i < (count - 2); i++) {
		list[i] = 0; // 초기화
	}

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (graph[j][k] >= 2) {
				int num = graph[j][k]; // 단지번호
				list[num-2]++;
			}
		}
	}

	BubbleSort(list, count - 2);

	for (int i = 0; i < (count - 2); i++) {
		printf("%d\n", list[i]);
	}

	return 0;
}

int BFS(int x, int y, int N, int count) {
	Queue queue_x;
	InitQueue(&queue_x);
	Queue queue_y;
	InitQueue(&queue_y);
	Enqueue(&queue_x, x);
	Enqueue(&queue_y, y); 

	graph[x][y] = count; // 처음 시작 지점도 포함해서 count
	isVisited[x][y] = 1;

	while (!IsEmpty(&queue_x)) {
		int Pop_x = Dequeue(&queue_x);
		int Pop_y = Dequeue(&queue_y);

		for (int i = 0; i < 4; i++) {
			int nx = Pop_x + dx[i];
			int ny = Pop_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (graph[nx][ny] == 1 && isVisited[nx][ny] == 0) {
				Enqueue(&queue_x, nx);
				Enqueue(&queue_y, ny);
				graph[nx][ny] = count;
			}
		}
	}

	return count+1;
}