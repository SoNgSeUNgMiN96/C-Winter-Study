#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, K , *arr;
    long long left=0, right , mid, sum ,answer , temp;
    scanf("%d %d",&N,&K);
    right = (long)N*N;
    
    while (left<=right)
    {
        mid = (left + right)/2;
        sum = 0;
        for (int i = 1; i <=N; i++){
            temp = mid/i;
            sum += (N<temp) ? N:temp;
        }
               
        if (sum>=K){
            answer = mid;
            right = mid-1;
        }else
            left = mid +1;
    }
    printf("%d\n",answer);
}
