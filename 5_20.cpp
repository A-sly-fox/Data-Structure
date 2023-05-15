#include<stdio.h>

int main(){
    int m,n,min,sign=0;
    scanf("%d %d\n",&m,&n);
    int matrix[m][n];
    for(int i=0;i<m*n;i++){
        scanf("%d",&matrix[i/n][i%n]);
    }
    for(int j=m-1;j>=0;j--){
        for(int k=n-1;k>=0;k--){
            if(matrix[j][k]){
                if(sign)
                    printf("+");
                if(matrix[j][k]!=1)
                    printf("%d",matrix[j][k]);
                if(j)
                    printf("xE%d",j);
                if(k)
                    printf("yE%d",k);
                sign=1;
            }
        }
    }
    return 0;
}