#include <stdio.h>
#define HEAP_SIZE 500000

int heap[HEAP_SIZE];
int heapCount = 0;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int x){
    heap[++heapCount] = x;
    
    int child = heapCount;
    int parent = child/2;
    
    while(child>1 && heap[child]>heap[parent]){
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = child/2;
    }
    
}

int pop(){
    int ret = heap[1];
    
    swap(&heap[1], &heap[heapCount]);
    heapCount = heapCount-1;
    
    int parent = 1;
    int child = parent*2;
    
    if(child+1 <= heapCount){
        child = (heap[child]>heap[child+1]) ? child : child+1;
    }
    
    while(child<=heapCount && heap[child]>heap[parent]){
        swap(&heap[child], &heap[parent]);
        parent = child;
        child = parent*2;
        
        if(child+1 <= heapCount){
            child = (heap[child]>heap[child+1])? child : child+1;
        }
    }
    
    return ret;
}
 
int main(){

    int N, a , temp;


    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&a);
        if (a ==0){
            if (heapCount==0){
                printf("-1\n");
            }else{
                printf("%d\n",pop());
            }

        }else for (int j=0;j<a;j++){
            scanf("%d",&temp);
            push(temp);
        }
    }
        
    return 0;
} 

