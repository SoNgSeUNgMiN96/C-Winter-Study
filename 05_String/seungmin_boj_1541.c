#include <stdio.h>
#include <stdlib.h>

int main(){

    char formula[100];
    int numarr[50] = {0 ,}, numcounter=0 , plusminuscounter =0, sum =0 , sumtemp = 0, cursor=0,sector=0;
    int plusminus[50]; 
    char *temp;
    scanf(" %[^\n]",formula);
    temp = formula;

    while (*temp)
    {
        while (*temp>='0'&&*temp<='9')//숫자인동안
        {
            numarr[numcounter] *= 10;
            numarr[numcounter] += (*temp-'0');
            temp++;
        }
        numcounter++;
        
        if (*temp=='-'){        //-인경우
            plusminus[plusminuscounter] = numcounter;
            plusminuscounter++;
        }
        temp++;
    }

    for(cursor=0;cursor<plusminuscounter;cursor++)
    {
        sumtemp=0;
        
        for (int j=sector;j<plusminus[cursor];j++)  //-전까지 다 더해준다
            sumtemp +=numarr[j];
        sector = plusminus[cursor];

        if (cursor==0)      //이게 최초의 -앞구간이라면 더해주고
            sum +=sumtemp;
        else        //이후라면 다 빼준다.
            sum -=sumtemp;
    }

    sumtemp =0;
    for (int j = sector ;j<numcounter;j++)      //마지막 -부터 끝까지 모든 수를 더한다
        sumtemp += numarr[j];
    
    if (cursor!=0)  //-가 한번이라도 등장했다면 마지막 - 부터 모든 수를 뺸다
        sum -=sumtemp;
    else        //단 한번도 -가 등장한적이없다면 모든 수를 + 해준다.
        sum +=sumtemp;
    
    printf("%d\n",sum);
}
