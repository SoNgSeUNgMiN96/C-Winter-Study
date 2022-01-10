#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{       //여기서 데이터 타입만 수정하면 됨
    int x;
    int y;
    struct queue *next;
}typedef queue;

typedef struct {
    queue *front;
}front;

typedef struct {
    queue *rear;
}rear;

front *Q;
rear *R;

void createqueue(){   //큐를 만들면 큐의 프론트가 초기값0xFFFFFFF 을 가지게 하고 큐가 비었는지를 검사하는 값으로 쓰임
    Q = (front*)malloc(sizeof(front));
    Q->front = (queue *)malloc(sizeof(queue));
    Q->front->x = 0xFFFFFFF;
    Q->front->y = 0xFFFFFFF;
}
void enqueuefirst(int X, int Y){   //이 시점에 rear 가 생성되고 rear 를 반납함 
    queue *temp =(queue *)malloc(sizeof(queue)); 
    temp->y = Y;
    temp->x = X;
    temp->next= NULL;
    Q->front->next =temp;
    R = (rear *)malloc(sizeof(rear));
    R->rear  = Q->front->next;    //첫 큐는 프론트의 넥스트를 레어가 가르킴
}

void enqueue(int X, int Y){     // rear와 X(좌표) 와  Time(시간)을 받아 새로운 노드를 생성하고 레어 뒤를 이어줌
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->x = X;
    temp->y = Y;
    temp->next = NULL;
    R->rear->next =temp;
    R ->rear = temp;
}


queue *dequeue(){   //temp 에 front 를 가르키게 한 후 front 를 한칸 미룬다 . 그리고 방금 temp를 반납한다  -> 메인함수에서받은 템프를 free해주어야함
    queue *temp;
    if(Q->front->next == NULL){
        return NULL;
    }
    temp = Q->front->next;
    if (Q->front->next->next!=NULL){
        Q->front->next = Q->front->next->next;
    }
    else if (Q->front->next->next==NULL){ 
        Q->front->next = NULL;
        R->rear = Q->front;
    }
    return temp;
}

void swap(int *a,int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int *arr, int l, int r){
    int pivot, i,j,temp;
    pivot = l;
    i = l; j = l+1;
    for (;j<=r;j++){
        if (arr[j]<arr[pivot]){
            i++;
            if (i!=j)
                swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[pivot],&arr[i]);
    return i;
}

void quickSort(int *arr, int l,int r){

    if (l<r){
        int j = partition(arr,l,r);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,r);
    }
}


int N, numbering[400],numCount=0, dx[4] = {0,0,-1,1},dy[4] = {1,-1,0,0} , direccode=0;
char **map;

void bfs(int x,int y){

    createqueue();
    enqueuefirst(x,y);
    map[x][y] = 0 ;
    numbering[numCount]++;
    int tempx, tempy;
    while (Q->front->next!=NULL)
    {
        queue* temp = dequeue();

        for (int i = 0; i < 4; i++)
        {
            tempx = temp->x + dx[i];
            tempy = temp->y + dy[i];
            if (tempx>=0&&tempx<N&&tempy>=0&&tempy<N&&map[tempx][tempy]=='1'){        //방문안했고 1이라면
                numbering[numCount]++;
                map[tempx][tempy] = 0;
                enqueue(tempx,tempy);
            }
        }
    }
}



int main(){
   
    scanf("%d",&N);

    map = (char**)malloc(sizeof(char*)*(N));

    for (int i = 0; i < N; i++)
    {
        map[i] = (char*)malloc(sizeof(char)*(N+1));

        scanf("%s",map[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(map[i][j]=='1'){
                bfs(i,j);
                numCount++;
            }
        }
    } 

    printf("%d\n",numCount);
    quickSort(numbering,0,numCount-1);
    for (int i = 0; i < numCount; i++)
    {
        printf("%d\n",numbering[i]);
    }
}
