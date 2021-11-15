#include <stdio.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t))

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for(i = n - 1; i > 0; i--)
	{
		for(j = 0; j < i; j++){
			if(list[j] > list[j + 1]){
				SWAP(list[j], list[j + 1], temp);
			}
		}
	}
}

int main(void)
{
	int list[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	bubble_sort(list, 10);
	
	for(int i = 0; i < 10; i++){
		printf("%d ", list[i]);
	}
	
	return 0;
}
