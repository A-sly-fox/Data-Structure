#include<stdio.h>

int main(){
    int k,m,i,j;
    scanf("%d %d",&k,&m);
    int f[m+1];
    for(i=0;i<k-1;i++)
        f[i]=0;
    f[k-1]=1;
    for(i=k;i<=m;i++){
        f[i]=0;
        for(j=1;j<=k;j++){
            f[i]=f[i]+f[i-j];
        }
    }
    printf("%d\n",f[m]);
    return 0;
}