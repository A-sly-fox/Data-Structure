#include<stdio.h>
#define MAX 100

int main(){
    int a[MAX],num=0,c[MAX],output[MAX];
    while(scanf("%d",&a[num]) != EOF)
    num++;
    for (int i = 0; i < num; i++)
        c[i] = 0;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            if(a[i] > a[j])
                c[i]++;
    for (int i = 0; i < num; i++)
        output[c[i]] = a[i];
    for (int i = 0; i < num; i++)
        printf("%d ",output[i]);
    return 0;
}