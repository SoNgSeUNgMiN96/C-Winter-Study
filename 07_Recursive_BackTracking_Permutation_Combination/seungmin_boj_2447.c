#include<stdio.h>
#include<stdlib.h>

int N;
char **map;

void draw(int row,int col,int size){

    if (size==3){
        for (int i=row;i>row-3;i--){
            for(int j=col;j>col-3;j--){
                map[i][j] = '*';
            }
        }
        map[row-1][col-1] = ' ';
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            if(!(i==1&&j==1))
                draw(row - (size/3*i),col - (size/3*j),size/3);
        }
    }
}

int main(){
    scanf("%d",&N);
    map = (char**)malloc(sizeof(char*)*N);
    for (int i = 0; i < N; i++)
    {
        map[i] = (char*)malloc(sizeof(char)*N);
        for (int j = 0; j < N; j++)
        {
            map[i][j]= ' ';
        }
        
    }
    draw(N-1,N-1,N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    
}
