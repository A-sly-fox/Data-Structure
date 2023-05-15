#include<stdio.h>
#define MAX 100
//int f(int a);

int main(){
    int a,b[MAX],buff=0,result=1;
    scanf("%d",&a);
    //printf("%d\n",f(a));
    while(a!=0){
        b[buff++]=a;
        a=a/2;
    }
    buff--;
    while(buff!=-1){
        result*=b[buff--];
    }
    printf("%d\n",result);
    return 0;
}

/*int f(int a){
    if(a==0)
        return 1;
    else
        return a*f(a/2);
}*/