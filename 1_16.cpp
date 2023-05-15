#include<stdio.h>

int main(){
    int a,b,c,d,e,f;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if(c>a){
            d=c;
            e=a;
            f=b;
        }else if(c<b){
            d=a;
            e=b;
            f=c;
        }else{
            d=a;
            e=c;
            f=b;
        }
    }else{
        if(c>b){
            d=c;
            e=b;
            f=a;
        }else if(c<a){
            d=b;
            e=a;
            f=c;
        }else{
            d=b;
            e=c;
            f=a;
        }
    }
    printf("%d %d %d\n",d,e,f);
    return 0;
}