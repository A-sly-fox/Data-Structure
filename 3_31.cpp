#include<stdio.h>
#define MAX 100

int main(){
    char a[MAX],c;
    int i=0,j,sign=0;
    while((c=getchar())!='@'){
        a[i]=c;
        i++;
    }
    for(j=0;j<i;j++)
        if(a[j]!=a[i-1-j]){
            sign=1;
        }
    printf((sign>0)?"0":"1");
    return 0;
}