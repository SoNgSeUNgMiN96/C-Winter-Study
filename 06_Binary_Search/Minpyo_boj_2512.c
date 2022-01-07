//
//  main.c
//  Budget
//
//  Created by rabbi on 2022/01/03.
//

// No. 2512

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n; // 지방의 수
    scanf("%d", &n);
    
    int* budget = (int*)malloc(sizeof(int) * n); // 각 지방의 예산 배열
    
    int totalBudget = 0; // 국가 예산
    int maximum = 0;
    int upperbound = 0; // 상한액
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &budget[i]);
        if(budget[i] > maximum) maximum = budget[i];
    }
    
    scanf("%d", &totalBudget);
    
    int left = 0;
    int right = maximum;


    while(left<=right) {
        int temp = 0;
        int mid = (left+right) / 2;

        for(int i = 0; i < n; i++) {
            temp += (budget[i] > mid)? mid: budget[i];
        }

        if(totalBudget>=temp) {
            left = mid + 1;
            upperbound = mid;
        } else {
            right = mid - 1;
        }
    }
    
    printf("%d", upperbound);

    return 0;
}
