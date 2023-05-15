#include<stdio.h>

#define MAX 100
int main(){
    char a[MAX],c;
    int i=0;
    while((c=getchar())!='\n'){
        if(c=='('){
            a[i]=c;
            i++;
        }
        else if(c==')'){
            i--;
        }
    }
    printf((i==0)?"1":"0");
    return 0;
}