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
        
        if (*temp=='-'){        //+인경우
            plusminus[plusminuscounter] = numcounter;
            plusminuscounter++;
        }
        temp++;
    }

    for(cursor=0;cursor<plusminuscounter;cursor++)
    {
        sumtemp=0;
        
        for (int j=sector;j<plusminus[cursor];j++)
            sumtemp +=numarr[j];
        sector = plusminus[cursor];

        if (cursor==0)
            sum +=sumtemp;
        else
            sum -=sumtemp;
    }

    sumtemp =0;
    for (int j = sector ;j<numcounter;j++)
        sumtemp += numarr[j];
    
    if (cursor!=0)
        sum -=sumtemp;
    else
        sum +=sumtemp;
    
    printf("%d\n",sum);
}
