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
	int list[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	selection_sort(list, 10);
	
	for(int i = 0; i < 10; i++){
		printf("%d ", list[i]);
	}
	
	return 0;
}
