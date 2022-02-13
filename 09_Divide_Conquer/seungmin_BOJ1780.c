#include<stdio.h>
#include<stdlib.h>

int answer[3]= {0,},**arr;        //정답 배열

void checker(int size,int x,int y){
    int first = arr[x-1][y-1];
    for (int i = x; i > x-size; i--){
        for (int j = y; j > y-size; j--){
            if(arr[i-1][j-1]!=first){
                int newSize = size/3;
                checker(newSize,x-size/3,y);
                checker(newSize,x -size/3*2,y);
                checker(newSize,x,y);
                checker(newSize,x -size/3,y- size/3);
                checker(newSize,x -size/3*2,y- size/3);
                checker(newSize,x,y- size/3);
                checker(newSize,x -size/3,y- size/3*2);
                checker(newSize,x -size/3*2,y- size/3*2);
                checker(newSize,x,y- size/3*2);
                return;
            }
        }   
    }
    switch (arr[x-1][y-1])
    {
    case -1:
        answer[0]++;
        break;
    case 0:
        answer[1]++;
        break;
    case 1:
        answer[2]++;
        break;
    default:
        break;
    }
}

int main(){
    int N;
    scanf("%d",&N);
    arr = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++){
        arr[i] = (int*)malloc(sizeof(int)*N);
        for (int j = 0; j < N; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    checker(N,N,N);
    printf("%d\n%d\n%d",answer[0],answer[1],answer[2]);
}
