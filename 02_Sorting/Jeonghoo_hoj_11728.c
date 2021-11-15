// 선택 정렬 - 시간 초과
#include <stdio.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t))

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for(i = 0; i < n - 1; i++){
		least = i;
		for(j = i + 1; j < n; j++){
			if(list[j] < list[least]) least = j;
		}
		SWAP(list[i], list[least], temp);
	}
 } 
 
 int main(void)
 {
 	int n_A, n_B, i, j, k = 0;
 	                  
 	scanf("%d %d", &n_A, &n_B);
 	
 	int list_C[n_A + n_B + 1];

	for(i = 0; i < (n_B + n_A); i++)
 	{
 		scanf("%d", &list_C[i]);
	}
	
	selection_sort(list_C, n_A + n_B);

	
	
	for(int i = 0; i < (n_A + n_B); i++){
		printf("%d ", list_C[i]);
	}
	
	return 0;
 }
