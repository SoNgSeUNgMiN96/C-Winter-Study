// 벽 부수고 이동하기 (백준 2206번)

#include <stdio.h>
#include <stdlib.h>

int map[1010][1010];
int isVisited[1010][1010];
int dx[4] = { 0, 0, -1, 1 }; // 상 하 좌 우
int dy[4] = { 1, -1, 0, 0 }; // 상 하 좌 우

int BFS(int x, int y, int N, int M);

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
	int N, M;

	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			isVisited[i][j] = 2;
		}
	}

	int answer = BFS(0, 0, N, M);
	printf("%d", answer);
	return 0;
}

int BFS(int x, int y, int N, int M) {
	Queue queue_x, queue_y, queue_distance, queue_drill; // x, y, 이동거리, 벽을 부순 횟수
	InitQueue(&queue_x);
	InitQueue(&queue_y);
	InitQueue(&queue_distance);
	InitQueue(&queue_drill);

	Enqueue(&queue_x, x);
	Enqueue(&queue_y, y);
	Enqueue(&queue_distance, 1); // 출발지점과 도착지점도 이동거리에 포함
	Enqueue(&queue_drill, 0);

	isVisited[y][x] = 0;

	while (!IsEmpty(&queue_x)) {
		int p_x = Dequeue(&queue_x);
		int p_y = Dequeue(&queue_y);
		int p_distance = Dequeue(&queue_distance);
		int p_drill = Dequeue(&queue_drill);

		if (p_x == M - 1 && p_y == N - 1)
			return p_distance;

		for (int i = 0; i < 4; i++) {
			int nx = p_x + dx[i];
			int ny = p_y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (isVisited[ny][nx] > p_drill) {
					if (map[ny][nx] == 0) { // 벽이 아닐 때
						Enqueue(&queue_x, nx);
						Enqueue(&queue_y, ny);
						Enqueue(&queue_distance, p_distance + 1); // 출발지점과 도착지점도 이동거리에 포함
						Enqueue(&queue_drill, p_drill);
						isVisited[ny][nx] = p_drill;
					}
					else { // 벽일 때
						if (p_drill == 0) { // 지금까지 벽을 부순 횟수가 0이라면
							Enqueue(&queue_x, nx);
							Enqueue(&queue_y, ny);
							Enqueue(&queue_distance, p_distance + 1); // 출발지점과 도착지점도 이동거리에 포함
							Enqueue(&queue_drill, p_drill+1);
							isVisited[ny][nx] = p_drill+1;
						}
					}
				}
			}
		}
	}
	return -1;
}

