#include <stdio.h>

int main(){
    int E, EM, M, MH, H ,left = 0, right=200000, mid,answer,temp; 
    int EMTEMP, MHTEMP;
    scanf("%d %d %d %d %d", &E, &EMTEMP, &M, &MHTEMP, &H);
    while (left<=right)
    {
        mid = (left+right)/2;
        EM = EMTEMP;
        MH = MHTEMP;
        if(E<mid){
            temp = mid - E; //temp = E가 모자란 양
            if(temp<=EM){       //모자란 양을 채울 수 있다면
                EM -= temp;
            }else{  
                right = mid -1;
                continue;
            }
        }
        if (M<mid){
            temp = mid - M;
            if(temp<=EM+MH){
                temp -= (temp<=EM) ? temp : EM;         //temp= 방금 더해준 만큼을 빼준다.
                MH -= (temp<=MH) ? temp: MH;
            }else{
                right = mid -1;
                continue; 
            }
        }
        if(H<mid){
            temp = mid - H;
            if (temp>MH){
                right = mid -1;
                continue; 
            }
        }
        answer = mid;
        left = mid +1;
    }
    printf("%d",answer);
}
