#include <stdio.h>

int n,answer=0,list[15];

void search(int count){
    
    if(count==n){
        answer++;
        return;
    }
 
    for(int i=0;i<n;i++){
        int code = 1;
        for(int j=0;j<count;j++){
            if(list[j]==i){
                code = 0;
                break;
            }
            if(count-j== (list[j]-i>0?list[j]-i:i-list[j]) ){
                code = 0;
                break;
            }
        }
        if (code){  //이 자리를 설치할 수 있다면
            list[count]=i;
            search(count+1);
        }
    }
}

int main(){
    scanf("%d",&n);
    search(0);
    printf("%d",answer);
}
