#include<stdio.h>
#define MAX 100
int v1[MAX];
int v2[MAX];
int v3[MAX];

int main(){
    int m,n,i=0,j,num1,num2,sum;
    num1=num2=0;
    char d=' ';
    scanf("%d %d",&m,&n);
    int a[m][n];
    int b[m][n];
    int c[m][n];
    //读取数据部分，复杂度为O（t+m*n），t为稀疏矩阵的项数
    while(d!='\n'){
        scanf("%d",&v1[i++]);
        d=getchar();
    }
    for(j=0;j<m*n;j++){
        scanf("%d",&a[j/n][j%n]);
    }
    i=0;
    d=' ';
    while(d!='\n'){
        scanf("%d",&v2[i++]);
        d=getchar();
    }
    for(j=0;j<m*n;j++){
        scanf("%d",&b[j/n][j%n]);
    }
    i=0;
    //求和部分，复杂度为O（m*n）
    for(j=0;j<m*n;j++){
        if(!a[j/n][j%n] && !b[j/n][j%n]){
            c[j/n][j%n]=0;
        }else if(a[j/n][j%n] && !b[j/n][j%n]){
            c[j/n][j%n]=1;
            v3[i++]=v1[num1++];
        }else if(!a[j/n][j%n] && b[j/n][j%n]){
            c[j/n][j%n]=1;
            v3[i++]=v2[num2++];
        }else{
            sum=v1[num1++]+v2[num2++];
            if(sum){
                c[j/n][j%n]=1;
                v3[i++]=sum;
            }else{
                c[j/n][j%n]=0;
            }
        }
    }
    //打印结果部分，算法复杂度为O（i+m*n），i是得到的矩阵的项数，小于t
    for(int k=0;k<i;k++){
        printf("%d",v3[k]);
        if(k!=i-1)
            printf(" ");
    }
    printf("\n");
    for(int k=0;k<m*n;k++){
        printf("%d",c[k/n][k%n]);
        printf(((k+1)%n)?" ":"\n");
    }
    //综上，整个算法的复杂度为O（t+m*n）
    return 0;
}