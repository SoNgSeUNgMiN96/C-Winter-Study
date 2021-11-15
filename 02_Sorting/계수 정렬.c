#include <stdio.h>
#define MAXSIZE 30
#define MAXCOUNT 5

int count[MAXCOUNT];

void counting_sort(int list[], int n)
{
	for(int i = 0; i < MAXCOUNT; i++){
		count[i] = 0;
	}
	for(int i = 0; i < n; i++){
		count[list[i] - 1]++;
	}
	for(int i = 0; i < MAXCOUNT; i++){
		if(count[i] != 0){
			for(int j = 0; j < count[i]; j++){
				printf("%d ", i + 1);
			}
		}
	}
}

int main(void)
{
	int i;
	int list[MAXSIZE] = {
		1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
		3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
		3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
		
	counting_sort(list, MAXSIZE);
	
	return 0;
}
