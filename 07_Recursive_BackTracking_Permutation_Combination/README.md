## 재귀/백트래킹/순열·조합(Recursive_BackTracking_Permutation_Combination)

##### 담당자 : 송승민

# 재귀함수


- 재귀함수란 어떤 함수에서 자신을 다시 호출하여 작업을 수행하는 방식의 함수를 의미합니다.

## 💎 Tips
재귀의 탈출 조건이나 가지치기를 잘 하지못하면, 시간복잡도와 효율성이 매우 떨어질 수 있다!!


## 🏷️ 재귀함수 예제
```
#include<stdio.h>

void recur(int N){
    if(N!=6){
        recur(N+1);
        printf("N = %d\n",N);
    }
}

int main(){
    recur(1);
}
```

이렇게 사용할 시 recur 함수가 스택 구조로 쌓이며 진행이됩니다.

recur(1) → recur(2) → recur(3) → recur(4) → recur(5) → recur(6) → recur(6) 종료 → recur(5) print문 출력  → recur(5) 종료 → recur(4) print 문 출력 → recur(4) 종료 → recur(3) print 문 출력 → recur(3) 종료 → recur(2) print 문 출력 → recur(2) 종료 → recur(1) print 문 출력 → recur(1) 종료


# 백트래킹


- 백트래킹은 재귀적으로 함수를 구현하되, 정답이 될 수 없는 경우를 미리 가지치기하여, 정답이 될 것같은 경우만 살펴보는 알고리즘입니다.

## 💎 Tips
재귀를 도는 조건설정을 잘하자!


# 조합


- 조합이란 nCr 이라는 기호으로 많이 쓰이는데, 
n개 중에서 r개를 뽑는 경우의 수를 말합니다.
ex)  빨주노초파 색상 중 2가지를 뽑는 경우 5C2  = 10가지이며
빨주, 빨노, 빨초, 빨파, 주노, 주초, 주파, 노초, 노파, 초파  가 경우로 올 수 있습니다.

## 💎 Tips
유형이 비슷하니 재귀함수의 구조를 익히시면 쉽습니다.



## 🏷️ 조합 (백트래킹포함) 예제
```
#include<stdio.h>
#include<stdlib.h>

int pick[6];

void combi(int N, int *arr, int start,int count){
		    if(count==6){   //6개를 pick에 다 넣어줬을경우 담긴요소 출력
        for (int i = 0; i < 6; i++)
        {
            printf("%d ",pick[i]);
        }   
        printf("\n");     
        return;
    }
    for(int i=start;i<N-5+count;i++){   //여기의 조건식이 백트래킹에 해당함. 6개를 다 뽑을 수 없는경우엔 미리 탈출
        pick[count] = arr[i];
        combi(N,arr,i+1,count+1);   //다음 요소를 추가로 뽑을 재귀함수 실행,
    }
}

int main(){
		int N;    //S의 원소 수
    int *arr;  //S를 받을 배열
    while (1)
    {
        scanf("%d",&N);  //N을 입력받는다.
        if(N==0) break;   //N이 0이면 탈출조건
        arr = (int*)malloc(sizeof(int)*N);  //배열공간 할당
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&arr[i]);  //배열의 원소를 받음
        }
        combi(N,arr,0,0); //현재 S에 대한 조합함수 실행.
        printf("\n");     
    }
}
```


# 순열


-순열이란 nPr 이라는 기호로 많이 쓰이는데, 
n개 중에서 r개를 뽑는 경우의 수를 말하지만, 조합과 가장 큰 차이점은 순서의 영향이 있는 경우입니다.
ex)  빨,주,노 색상 중 2가지를 뽑는 경우 3C2  = 3 x 2 = 6가지이며
빨주,  주빨, 빨노, 노빨, 주노, 노주가 경우로 올 수 있습니다.

## 💎 Tips
유형이 비슷하니 재귀함수의 구조를 익히시면 쉽습니다. 방문확인은 필수!



## 🏷️순열 예제
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *pick;  //뽑을 pick배열
bool *visited;//방문확인 bool배열

void permutation(int N , int start, int count){
    if(count==N){
        for (int i = 0; i < N; i++)
        {
            printf("%d ",pick[i]);
        }
        printf("\n");
				return;
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i]==false){
            pick[count] =i+1;
            visited[i] = true;
            permutation(N,i+1,count+1);
            visited[i] = false;
        }
    }
}

int main(){
    int N;
    scanf("%d",&N);
    pick = (int*)malloc(sizeof(int)*N);
    visited = (bool*)malloc(sizeof(bool)*N);
    permutation(N,0,0);
}
```



