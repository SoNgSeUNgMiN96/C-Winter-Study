#include<stdio.h>
#include<stdlib.h>

int main(){

    int N , M ,* arr;
    long long  left=0,right =1000000001 , mid , answer=0, count;
    scanf("%d %d",&N, &M);
    arr = (int*) malloc(sizeof(int)*N);

    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
 
    while (left<=right)
    {
        mid = (left + right) /2;
        count =0;
        for(int i=0;i<N;i++)
            count += (mid<arr[i]) ? (arr[i]-mid) : 0 ;
        
        if(count>=M){
            answer = mid;
            left = mid +1;
        }else
            right = mid-1;  
    }
    printf("%d\n",answer);
}
