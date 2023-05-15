#include<stdio.h>
#define MAX 100

int main(){
    int record[MAX],a=0,x,y,z,t;
    while(scanf("%d",&record[a]) != EOF)
        a++;
    x = y = z =0;
    for(int i = 0; i < a; i++){
        if(record[i] == 1)
            x++;
        else if(record[i] == 2)
            y++;
        else
            z++;
    }
    for(int i = 0; i < a;i++){
        if(i < x)
            record[i] = 1;
        else if(i < x+y)
            record[i] = 2;
        else
            record[i] = 3;
    }
    for(int i = 0; i < a; i++)
        printf("%d ",record[i]);
    return 0;
}