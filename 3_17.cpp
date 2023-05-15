#include<stdio.h>
#define MAX 100

int main(){
    char a[MAX],b[MAX],c;
    int i=0,sign=1;
    while((c=getchar())!='&'){
        a[i]=c;
        i++;
    }
    while((c=getchar())!='@'){
        i--;
        if(c!=a[i] || i<0){
            sign=0;
            break;
        }
    }
    printf("%d\n",sign);
    return 0;
}