#include <stdio.h>

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++)
	{
		key = list[i];
		for(j = i - 1; j >= 0 && list[j] > key; j--){
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
	
}

int main(void)
{
	int list[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	insertion_sort(list, 10);
	
	for(int i = 0; i < 10; i++){
		printf("%d ", list[i]);
	}
	
	return 0;
}
