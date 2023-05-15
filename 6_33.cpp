#include<stdio.h>
#define MAX 100
int L[MAX];
int R[MAX];

int main(){
    char c=' ';
    int a,b,num=1;
    for(int i=0;i<MAX;i++){
        scanf("%d",&L[i]);
        c=getchar();
        if(c=='\n')
            break;
    }
    for(int i=0;i<MAX;i++){
        scanf("%d",&R[i]);
        c=getchar();
        if(c=='\n')
            break;
    }
    scanf("%d %d",&a,&b);
    if(b!=L[0])
        for(int i=1;i<MAX;i++){
            num++;
            if(b==L[i])
                break;
            num++;
            if(b==R[i])
                break;
        }
    if(a==L[num] || a==R[num])
        printf("1");
    else
        printf("0");
    return 0;
}