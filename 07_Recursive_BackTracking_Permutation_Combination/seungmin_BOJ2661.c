#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isgood(int *arr,int count, int N){
    int *temp;
    bool notgood = true;

    for (int i = 1; i <= count/2; i++)      //i 는 뽑을 갯수
    {   
        temp = (int*)malloc(sizeof(int)*i); //뽑을 갯수만큼의 temp 생성
        for (int j = 0; j <count-i-i+1; j++)        //뽑기 시작할 위치
        {
            for (int k = j; k < j+i; k++)   //그 위치부터 i개를 뽑아 저장.
            {
                temp[k-j] = arr[k];     //비교할 문자열 저장
            }
            notgood = true;

            for (int k=j+i;k<j+i+i;k++){        //뽑은 수열 다음구간에서, i개만큼 일치하는지 확인
                if(temp[k-i-j]!=arr[k]){        //계속해서 일치한다면 true유지
                    notgood = false;
                    break;
                }
            }
            if(notgood){        //한번이라도 나쁜수열이라면
                return false;
            }
        }
        
    }
    return true;
}

void good(int N,int count,int *arr, int before){

    if(N==count){
        for (int i = 0; i < N; i++)
        {
            printf("%d",arr[i]+1);
        }
        exit(0);
    }

    for (int i = 0; i < 3; i++)
    {
        if(i==before)
            continue;
        arr[count] = i;
        if (isgood(arr,count+1,N)){
            good(N,count+1,arr,i);
        }
    }
    
}

int main(){
    int N;
    int *arr;
    scanf("%d",&N);
    arr = (int*)malloc(sizeof(int)*N);
    good(N,0,arr,4);
}
