#include <stdio.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t))

void quick_sort(int list[], int start, int end)
{
	if(start >= end){// 원소가 1개인 경우 
		return 0;
	}
	
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){// 엇갈릴 때까지 반복 
		while(list[i] <= list[key]){// 키 값보다 큰 값 
			i++;
		}
		while(list[j] >= list[key] && j > start){// 키 값보다 작은 값 
			j--; 
		}
		if(i > j){// 현재 엇갈린 상태면 키 값과 교체 
			SWAP(list[key], list[j], temp);
		} else{
			SWAP(list[i], list[j], temp);
		}
	}
	
	quick_sort(list, start, j - 1);
	quick_sort(list, j + 1, end);
}

int main(void)
{
	int list[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	quick_sort(list, 0, 9);
	
	for(int i = 0; i < 10; i++){
		printf("%d ", list[i]);
	}
	
	return 0;
}
