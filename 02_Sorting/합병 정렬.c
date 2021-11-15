#include <stdio.h>
#define MAXSIZE 8

int sorted[MAXSIZE];  // 추가 공간이 필요 
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left, j = mid + 1, k = left;
	
	while(i <= mid && j <= right){
		if(list[i] <= list[j])
			sorted[k++] = list[i++];
		else 
			sorted[k++] = list[j++];
	}
	// 남은 데이터 삽입 
	if(i > mid)
		for(l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 
		for(l = i; l <= mid; l++)
			sorted[k++] = list[l];
			
	for(l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main(void)
{
	int list[MAXSIZE] = {7, 6, 5, 8, 3, 5, 9, 1};
	merge_sort(list, 0, MAXSIZE - 1);
	
	for(int i = 0; i < MAXSIZE; i++){
		printf("%d ", list[i]);
	}
	
	return 0;
}
