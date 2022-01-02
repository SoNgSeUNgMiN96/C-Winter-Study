## 재귀/백트래킹/순열·조합(Recursive_BackTracking_Permutation_Combination)

##### 담당자 : 송승민

# 재귀함수


- 재귀함수란 어떤 함수에서 자신을 다시 호출하여 작업을 수행하는 방식의 함수를 의미합니다.

## 💎 Tips
재귀의 탈출 조건이나 가지치기를 잘 하지못하면, 시간복잡도와 효율성이 매우 떨어질 수 있다!!


## 🏷️ 재귀함수 예제
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

