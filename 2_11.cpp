#include<stdio.h>
#define MAX 100 

int main(){
    int va[MAX];
    char c;
    int i,count,x,change;
    for(i=0;i<MAX;i++){
        scanf("%d%c",&va[i],&c);
        if(c=='\n')
            break;
    }
    count=i;
    scanf("%d",&x);
    for(i=0;i<=count;i++){
        if(va[i]<x){
            ;
        }else{
            change=va[i];
            va[i]=x;
            x=change;
        }
        printf("%d ",va[i]);
    }
    printf("%d",x);
    return 0;
}