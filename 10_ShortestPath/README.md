## 최단 경로
📌 최단경로
-네트워크에서 정점 u와 정점 v를 연결하는 경로 중에서 간선들의 가중치 합이 최소가 되는 경로
-간선의 가중치는 비용, 거리, 시간 등

# Dijkstra의 최단경로 알고리즘
- 하나의 노드에서 다른 하나의 노드로 가는 최단경로를 구하는 알고리즘

- distance배열 : 최단경로가 알려진 정점들만을 이용한 다른 정점들까지의 최단경로 길이
distance배열에서 가장 작은값을 뽑아(U)  최단경로 갱신
최단경로를 모르는경우(연결되어있지 않은경우 무한대로 표시)

### [ dijkstra 알고리즘 ]
```c
#include <stdio.h>
#include <limits.h> // INT_MAX(int의 최댓값)에 이용
#include <stdbool.h>
// 정점의 개수를 정의
#define V 5
 
 
int minDistance(int dist[V], bool sptSet[V])
{
    int min = INT_MAX, min_index;
 	int v;
    for (v = 0; v < V; v++)
    {
        if (!sptSet[v] && min > dist[v])
        {
            min_index = v;
            min = dist[v];
        }
    }
 
    return min_index;
}
 
 
// 시작점에서 그 정점까지의 최단 거리를 출력해준다.
void printSolution(int dist[], int n)
{
	int i;
    printf("Vertex   Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // 최단 거리를 파악하는 배열
    bool sptSet[V]; // 방문 했는지 체크 하는 bool형 배열
 	int i;
 	
	 //모든 노드의 최단거리를 max,방문안함상태로 설정
    for (i = 0; i<V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;	 
 
    
    dist[src] = 0;	//시작노드는 0 
 	int count, v;
 	
    // V-1번 루프를 수행한다는 것은 첫 src노드를 제외한 모든 노드들에 접근을 해 계산을 한다는 의미.
    for (count = 0; count < V - 1; count++)
    {
        // 최단거리 정보를 알고 있는 노드들 중 가장 거리가 짧은 노드의 인덱스를 가져온다.
        int u = minDistance(dist, sptSet);
 
        // 그래프 상의 모든 노드들을 탐색하며 u 노드의 주변 정보를 갱신한다.
        for (v = 0; v < V; v++)
        {
            // 1. 아직 처리가 되지 않은 노드이어야 하며 (무한루프 방지)
            // 2. u-v 간에 edge가 존재하고
            // 3. src부터 u까지의 경로가 존재하고
            // 4. 기존의 v노드까지의 최단거리 값보다 새로 계산되는 최단거리가 더 짧을 경우
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v])
            {
                // 최단거리를 갱신해준다.
                dist[v] = dist[u] + graph[u][v];
            }
        }
 
        // 이제 이 노드(u)는 접근할 일이 없다. 플래그를 true로 설정.
        sptSet[u] = true;
 
        // 현재까지의 최단 거리를 출력해준다.
        printSolution(dist, V);
    }
}
 
int main()
{
    // 다익스트라를 이용할 그래프
    int graph[V][V] = 
    { 
        { 0, 3, 6, 8, 7 },
        { 3, 0, 2, 4, 8 },
        { 6, 2, 0, 5, 5 },
        { 8, 4, 5, 0, 2 },
        { 7, 8, 5, 2, 0 },
    };
 
    // dijkstra(최단 거리를 구하고자 하는 그래프, 시작 하고자 하는 정점);
    dijkstra(graph, 0);
 
    return 0;
}


//출처: https://www.crocus.co.kr/533 [Crocus]
```
# Floyd 알고리즘
-그래프에 존재하는 모든 정점사이의 최단경로를 찾음
-3중for문을 이용
![image](https://user-images.githubusercontent.com/87978447/150762266-5a6a16e6-8711-48ac-9538-04ec0259940a.png)



if (A[i][k]+A[k][j] < A[i][j])  //정점k를 거칠때 거리가 더 짧은경우
  A[i][j] = A[i][k] + A[k][j] //최단거리 갱신
 
 
 
![image](https://user-images.githubusercontent.com/87978447/150763828-5fd4b2a3-1c4b-4b51-bf1e-c317aeddf9e7.png)
 
 
### [ Floyd 알고리즘 ]
```c
#include<stdio.h>
#include <limits.h>
 
// 정점의 수를 지정한다.
#define V 5
 
// INF를 무한대라고 지정하고, INT_MAX를 이용한다.
#define INF 10000
 
 
 
// 플로이드 워셜의 결과를 출력하는 함수
void printSolution(int dist[][V])
{
    printf("Following matrix shows the shortest distances, between every pair of vertices \n\n");
 
    printf("\t   to→ ");
 	int i,j;
    for (i = 0; i < V; i++)
        printf("[%d]    ",i);
 
    printf("\n      ↓from \n");
 
    for (i = 0; i < V; i++)
    {
        printf("\t[%d]", i);
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
 
// 모든 경로에 대한 최단 거리를 찾아주는 플로이드 워셜 함수
void floydWarshall(int graph[][V])
{
    /*
        dist[][] 배열에 최단 거리에 대한 정보들이 모두 들어가게 된다.
    */
    int dist[V][V], i, j, k;
 
    /*
        dist[][] 배열에 초기값은 그래프에서 주어진 값들이다.
        (즉, 아직 최단 거리를 구하기 전에는 기존의 거리를 최단 거리라 생각한다.)
    */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
 
    /*
        플로이드 워셜 알고리즘의 핵심
    */
    // 한 점을 경유하여 
    for (k = 0; k < V; k++)
    {
        // x에서
        for (i = 0; i < V; i++)
        {
            // y로 갈때
            for (j = 0; j < V; j++)
            {
                // 최단거리면 업데이트 해준다.
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // 모든 최단거리가 구해지고 난 뒤, 출력을 해준다.
    printSolution(dist);
}
 
 
int main()
{
    int graph[V][V] = 
    {
        { 0, 8, 4, 5, 5 },
        { 7, 0, 6, 2, 2 },
        { 3, 2, 0, 3, 7 },
        { 7, 3, 7, 0, 1 },
        { 3, 7, 4, 2, 0 },
    };
 
    // 플로이드 워셜 알고리즘으로 진입
    floydWarshall(graph);
 
    return 0;
}


//출처: https://www.crocus.co.kr/537 [Crocus]
```
