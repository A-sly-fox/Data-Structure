#include<stdio.h>

int main(){
    int n,arrsize;
    long long int result=1;
    scanf("%d %d",&n,&arrsize);
    if(n>arrsize){
        printf("-1");
        return 0;
    }
    int a[n];
    a[0]=1;
    for (int i = 1; i < n; i++){
        result=result*i*2;
        if(result>4294967295){
            printf("-1");
            return  0;
        }
        a[i]=result;
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}